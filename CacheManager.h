//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H

using namespace std;
#include <unordered_map>
#include <iostream>
#include <string>
#include <list>
#include <functional>
#include <algorithm>
#include <fstream>
#include <cstdlib>
using namespace std;

template <typename Solution, typename Problem>
class CacheManager {
 private:
  virtual void search_key_in_file(string &file_name_s, Solution& obj) = 0;
  virtual void insert(string key, Solution obj) = 0;
  virtual void write_to_file(string key, Solution& obj) = 0;
  virtual Solution get(string key) = 0;
  void use_update(typename unordered_map<string, pair<Solution, list<string>::iterator>>::iterator &it);
  template<typename Printer>
  void foreach(Printer pFunction);
 public:
    bool isSolved(Problem problem);
    void saveSolution(Solution solution, Problem problem);
    Solution getSolution(Problem problem);
    virtual ~CacheManager() = default;
};
#endif //EX4_CACHEMANAGER_H
