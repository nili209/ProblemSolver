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

template <typename T>
class CacheManager {
 private:
  virtual void search_key_in_file(string &file_name_s, T& obj) = 0;
  virtual void insert(string key, T obj) = 0;
  virtual void write_to_file(string key, T& obj) = 0;
  virtual T get(string key) = 0;
  void use_update(typename unordered_map<string, pair<T, list<string>::iterator>>::iterator &it);
  template<typename Printer>
  void foreach(Printer pFunction);
 public:
    template<typename Problem>
    bool isSolved(Problem problem);
    template<typename Solution, typename Problem>
    void saveSolution(Solution solution, Problem problem);
    template<typename Solution, typename Problem>
    Solution getSolution(Problem problem);
    virtual ~CacheManager() = default;
};
#endif //EX4_CACHEMANAGER_H
