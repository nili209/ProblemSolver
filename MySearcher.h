//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_MYSEARCHER_H
#define EX4_MYSEARCHER_H

#include "Searcher.h"
template <class Solution, typename T>
class MySearcher : public Searcher<Solution, T> {
    virtual Solution search(Searchable<T>* searchable);
    int getNumberOfNodesEvaluated() {
        return 0;
    }
    virtual ~MySearcher() = default;

};
#endif //EX4_MYSEARCHER_H
