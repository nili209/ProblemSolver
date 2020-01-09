//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_SEARCHSOLVER_H
#define EX4_SEARCHSOLVER_H

#include "Solver.h"
#include "Searcher.h"
template <class Problem, class Solution>
class SearchSolver : public Solver<Searchable<Point>*, string> {
private:
    Searcher<string, Point>* my_searcher;
public:
    SearchSolver(Searcher<string, Point>* searcher) : my_searcher(searcher) {}
    virtual string solve(Searchable<Point>* problem) {
        return my_searcher->search(problem);
    }
    virtual ~SearchSolver() {
        delete my_searcher;
    }

};


#endif //EX4_SEARCHSOLVER_H
