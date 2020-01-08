//
// Created by nili on 1/8/20.
//

#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H

#include <iostream>
using namespace std;
class CacheManager {
public:
    template<typename Problem>
    bool isSolved(Problem problem);
    template<typename Solution>
    void saveSolution(Solution solution);
    template<typename Solution, typename Problem>
    Solution getSolution(Problem problem);

};
#endif //EX4_CACHEMANAGER_H
