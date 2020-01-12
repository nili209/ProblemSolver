//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H

#include "Searchable.h"
template <class Solution,class Problem>
class Searcher {
public:
    Searcher<Solution, Problem>(){}
    virtual Solution search(Problem searchable) = 0;
    virtual int getNumberOfNodesEvaluated() = 0;
    virtual ~Searcher() = default;
};


#endif //EX4_SEARCHER_H
