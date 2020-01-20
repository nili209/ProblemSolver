//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H
#include "CacheManager.h"
#define PROBLEM "Problem_"
#include <functional>
#include <string>
template<typename Solution>
class FileCacheManager : public CacheManager<string, Solution> {
 private:
  int capacity;
  // <key, <value, key iterator>>
  unordered_map<string, pair<Solution, list<string>::iterator>> cache;
  // list of keys. first - mru, last - lru
  list<string> lru;
  list<string> file_name;
  //<problem, problem_name>
  unordered_map<string, string> problem_map;
  /**
   * Given a problem and an object, the function checks if the solution
   * to this problem already saved in the cache or files.
   * If so, the function reads the solution into the obj.
   * In this assignment the soltuion is string so the reading is spesoficly for strings.
   */
  void search_key_in_file(string &problem, Solution &obj) {
    ifstream is;
    hash < string > hasher;
    auto problem_hashed = hasher(problem);
    string problem_name = PROBLEM + to_string(problem_hashed) + ".txt";
    is.open(problem_name, ios::in | ios::binary);
    if (!is.is_open()) {
      throw "error opening the file";
    }
    //assuming obj is a string
    char s = ' ';
    is.get(s);
    while (s != EOF) {
      obj += s;
      s = EOF;
      is.get(s);
    }
    //is.read((char*) &(obj), sizeof(obj));
    is.close();
    return;
  }
  /**
   * Given a problem and solution, the funciton inserts the solution to the cache.
   */
  void insert(string problem, Solution obj) {
    write_to_file(problem, obj);
    //check if key exist in the cache, if so - update it. else - add it to the cache
    auto item = cache.find(problem);
    //key exists in the cache
    if (item != cache.end()) {
      //update the key to be MRU
      use_update(item);
      //update the value of the key
      item->second = {obj, lru.begin()};
      return;
    }
    //key does not exist in the cache
    //if we reached the limited size of the cache we need to remove thr lru in order to add the new item
    int size = cache.size();
    if (size == capacity && size != 0) {
      cache.erase(lru.back());
      lru.pop_back();
    }
    if (size > 0) {
      lru.push_front(problem);
      cache.insert({problem, {obj, lru.begin()}});
    }
  }
  /**
   * Given a problem and solution, the funciton write the solution into a binary file.
   * In this assignment the solution is string so the writing is done specoficly for string type.
   */
  void write_to_file(string problem, Solution &obj) {
    string problem_name;
    auto item = problem_map.find(problem);
    if (item != problem_map.end()) {
      problem_name = item->second;
    } else {
      hash < string > hasher;
      auto problem_hashed = hasher(problem);
      problem_name = PROBLEM + to_string(problem_hashed) + ".txt";
      file_name.push_front(problem_name);
      problem_map.insert({problem, problem_name});
    }
    ofstream outf;
    outf.open(problem_name, ios::out | ios::binary);
    if (!outf.is_open()) {
      throw "error opening the file";
    }
    //assuming obj is a string
    unsigned int size = obj.size();
    outf.write(obj.c_str(), size);
    //outf.write((char*)(&obj), sizeof(obj));
    outf.close();
  }
  /**
 * Given a problem, the function returns it's solution.
 */
  Solution get(string problem) {
    Solution value;
    //searching for the key in the cache
    auto item = cache.find(problem);
    //the key does not exist in the cache
    if (item == cache.end()) {
      //search the key in the files
      search_key_in_file(problem, value);
      insert(problem, value);
      //the key is in the cache
    } else {
      //update the key to be MRU
      use_update(item);
      value = item->second.first;
    }
    return value;
  }
  /**
   * The function updates the lru.
   */
  void use_update(typename unordered_map<string, pair<Solution, list<string>::iterator>>::iterator &it) {
    lru.erase(it->second.second);
    lru.push_front(it->first);
    it->second.second = lru.begin();
  }
  /**
   * Given a function, the function activates the function on each object of the cache.
   */
  template<typename Printer>
  void foreach(Printer pFunction) {
    for (auto it = lru.begin(); it != lru.end(); ++it) {
      auto item = cache.find(*it);
      if (item != cache.end()) {
        pFunction(item->second.first);
      }
    }
  }
 public:
  /**
   * Constructor.
   */
  FileCacheManager(int capacity_m) : capacity(capacity_m) {}
  /**
   * Given a problem, the function returns true if the cache contains it's solution and false otherwise.
   */
  bool isSolved(string problem) {
    auto item = problem_map.find(problem);
    //check if the problem is in the problem map - we solved it in the current run.
    if (item == problem_map.end()) {
      hash < string > hasher;
      auto problem_hashed = hasher(problem);
      string problem_name = PROBLEM + to_string(problem_hashed) + ".txt";
      ifstream ifstream1(problem_name);
      //if a file with the problem name exists - it means that the the problem is allready solved.
      if (ifstream1) {
        return true;
      }
      return false;
    }
    return true;
  }
  /**
   * Given a Solution and a problem, the function save the solution in the cache.
   */
  void saveSolution(Solution solution, string problem) {
    insert(problem, solution);
  }
  /**
   * Given a problem, the function returns it's solution.
   */
  Solution getSolution(string problem) {
    return get(problem);
  }
  /**
   * Destructor.
   */
  virtual ~FileCacheManager() = default;
};
#endif //EX4_FILECACHEMANAGER_H
