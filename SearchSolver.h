//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_SEARCHSOLVER_H
#define EX4_SEARCHSOLVER_H

#include "Solver.h"
#include "Searcher.h"
//T = Point
template<typename T, class Solution>
class SearchSolver : public Solver<string, Solution> {
 private:
  Searchable<Point> *matrix;
  vector<State<Point> *> structure;
  Searcher<Searchable<T>*, Solution> *my_searcher;
 public:
  SearchSolver(Searcher<T, Solution> *searcher) : my_searcher(searcher) {}
  /**
   * Given a problem, the function creates a Searchable of type matrix.
   */
  void initMatrix(string problem) {

  }
  virtual Solution solve(string problem) {
    initMatrix(problem);
    return my_searcher->search(matrix);
  }
  /**
 * Destructor.
 */
  virtual ~SearchSolver() {
    delete my_searcher;
  }

};

#endif //EX4_SEARCHSOLVER_H
