//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H
#include <mutex>
#include "Searchable.h"
template <typename T,class Solution>
class Searcher {
 protected:
  mutex mutex_lock;
public:
    Searcher<T, Solution>(){}
    virtual Solution search(Searchable<T>* searchable) = 0;
    //virtual int getNumberOfNodesEvaluated() = 0;
    virtual ~Searcher() = default;
};


#endif //EX4_SEARCHER_H
