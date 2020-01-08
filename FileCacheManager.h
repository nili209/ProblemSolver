//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H

#include "CacheManager.h"
class FileCacheManager : public CacheManager {
public:
    template<typename Problem>
    bool isSolved(Problem problem) {
        return false;
    }
    template<typename Solution>
    void saveSolution(Solution solution){

    }
    template<typename Solution, typename Problem>
    Solution getSolution(Problem problem) {
        Solution solution;
        return solution;
    }
    virtual ~FileCacheManager() = default;
};


#endif //EX4_FILECACHEMANAGER_H
