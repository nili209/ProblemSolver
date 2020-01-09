//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_MYSEARCHER_H
#define EX4_MYSEARCHER_H

#include "Searcher.h"
template <class string, typename Problem>
class MySearcher : public Searcher<string, Problem> {
 protected:
  int number_of_nodes_evaluated = 1;
 public:
    virtual string search(Searchable<Point>* searchable) = 0;
    int getNumberOfNodesEvaluated() {
        return number_of_nodes_evaluated;
    }
    virtual ~MySearcher() = default;
};
#endif //EX4_MYSEARCHER_H
