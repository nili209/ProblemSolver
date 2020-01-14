//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_MYSEARCHER_H
#define EX4_MYSEARCHER_H
#define NO_PATH "No path was found"
#include "Searcher.h"
// T = Point
template<typename T, typename Solution>
class MySearcher : public Searcher<T, Solution> {
 private:
  int number_of_nodes_evaluated = 1;
  Solution solution;
 protected:
  void setNumberOfNodesEvaluated(int num) {
    number_of_nodes_evaluated += num;
  }
  /**
 * Given a state, goal state and init state, the function returns the
 * trace of the state from init state to goal state.
 * In this assigment the trace back is a string but in case of a change we
 * need just to change the inner implementation of this function.
 */
  Solution backTrace(State<T> *state, State<T> *init, State<T> *goal) {
    if (state->Equals(init)) {
      return solution;
    }
    //up, down, right or left.
    string direction = state->getDirection();
    solution.insert(0, direction);
    if (!state->Equals(goal)) {
      solution.insert(direction.length(), ", ");
    }
    return backTrace(state->getComeFrom(), init, goal);
  }
 public:
  virtual Solution search(Searchable<T> *searchable) = 0;
  int getNumberOfNodesEvaluated() {
    return number_of_nodes_evaluated;
  }
  virtual ~MySearcher() = default;
};
#endif //EX4_MYSEARCHER_H
