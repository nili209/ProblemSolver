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

template <typename Problem, typename Solution>
class CacheManager {
 public:
    virtual bool isSolved(Problem problem) = 0;
    virtual void saveSolution(Solution solution, Problem problem) = 0;
    virtual Solution getSolution(Problem problem) = 0;
    virtual ~CacheManager() = default;
};
#endif //EX4_CACHEMANAGER_H
