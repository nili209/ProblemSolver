//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#include "Searchable.h"
template <class Solution,typename T>
class Searcher {
public:
    Searcher<Solution, T>(){}
    virtual Solution search(Searchable<T>* searchable) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
    virtual ~Searcher() = default;
};


#endif //EX4_SEARCHER_H
