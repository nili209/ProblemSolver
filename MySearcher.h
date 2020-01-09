//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_MYSEARCHER_H
#define EX4_MYSEARCHER_H

#include "Searcher.h"
template <class string, typename T>
class MySearcher : public Searcher<string, T> {
 public:
    virtual string search(Searchable<T>* searchable) = 0;
    int getNumberOfNodesEvaluated() {
        return 0;
    }
    virtual ~MySearcher() = default;
};
#endif //EX4_MYSEARCHER_H
