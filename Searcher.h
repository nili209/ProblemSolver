//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H
#define UP "Up"
#define DOWN "Down"
#define RIGHT "Right"
#define LEFT "Left"
#include "Searchable.h"
template <class Solution,typename T>
class Searcher {
public:
    virtual Solution search(Searchable<T>* searchable);
    virtual int getNumberOfNodesEvaluated();
    virtual ~Searcher() = default;
};


#endif //EX4_SEARCHER_H
