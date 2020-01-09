//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H

#include "CacheManager.h"
class FileCacheManager : public CacheManager<string, string> {
 private:
  int capacity;
  // <key, <value, key iterator>>
  unordered_map<string, pair<string, list<string>::iterator>> cache;
  // list of keys. first - mru, last - lru
  list<string> lru;
  list<string> file_name;
  unordered_map<string, string> file_name_map;
  void search_key_in_file(string &file_name_s, string& obj) {
    ifstream is;
    for (auto it = file_name.begin(); it!= file_name.end(); ++it) {
      if ((file_name_s).compare(*it) == 0) {
        is.open(file_name_s, ios::in| ios::binary);
        if(!is.is_open()) {
          throw "error opening the file";
        }
        is.read((char*) &(obj), sizeof(obj));
        is.close();
        return;
      }
    }
    return;
  }
  void insert(string key, string obj) {
    write_to_file(key, obj);
    //check if key exist in the cache, if so - update it. else - add it to the cache
    auto item = cache.find(key);
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
    if (size == capacity) {
      cache.erase(lru.back());
      lru.pop_back();
    }
    lru.push_front(key);
    cache.insert({key, {obj, lru.begin()}});
  }
  void write_to_file(string key, string& obj) {
    string c_name = key + ".txt";
    file_name.push_front(c_name);
    file_name_map.insert({c_name, c_name});
    ofstream outf;
    outf.open(c_name, ios::out | ios::binary);
    if(!outf.is_open()) {
      throw "error opening the file";
    }
    outf.write((char*)(&obj), sizeof(obj));
    outf.close();
  }
  string get(string key) {
    string value;
    string c_name = key + ".txt";
    string name = c_name;
    //searching for the key in the cache
    auto item = cache.find(key);
    //the key does not exist in the cache
    if (item == cache.end()) {
      //search the key in the files
      search_key_in_file(name, value);
      insert(key, value);
      //the key is in the cache
    } else {
      //update the key to be MRU
      use_update(item);
      value = item->second.first;
    }
    return value;
  }
  void use_update(typename unordered_map<string, pair<string, list<string>::iterator>>::iterator &it) {
    lru.erase(it->second.second);
    lru.push_front(it->first);
    it->second.second = lru.begin();
  }
  template<typename Printer>
  void foreach(Printer pFunction) {
    for (auto it = lru.begin(); it!= lru.end();++it) {
      auto item = cache.find(*it);
      if (item != cache.end()) {
        pFunction(item->second.first);
      }
    }
  }
 public:
  FileCacheManager() : capacity(0) {}
  bool isSolved(string problem) {
    string key = problem + ".txt";
    auto item = file_name_map.find(problem);
    if (item == file_name_map.end()) {
      return false;
    }
    return true;
  }
  void saveSolution(string solution, string problem) {
    //string key = problem;
    insert(problem, solution);
  }
  string getSolution(string problem) {
    //string key = problem;
    return get(problem);
  }
  virtual ~FileCacheManager() = default;
};
#endif //EX4_FILECACHEMANAGER_H
