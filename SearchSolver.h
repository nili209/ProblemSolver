//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_SEARCHSOLVER_H
#define EX4_SEARCHSOLVER_H

#include "Solver.h"
#include "Searcher.h"
template <class Problem, class Solution>
class SearchSolver : public Solver<Problem, Solution> {
private:
    Searcher<Solution, Problem>* my_searcher;
public:
    SearchSolver(Searcher<Solution, Problem>* searcher) : my_searcher(searcher) {}
    virtual Solution solve(Problem problem) {
        return my_searcher->search(problem);
    }
    virtual ~SearchSolver() {
        delete my_searcher;
    }

};


#endif //EX4_SEARCHSOLVER_H
