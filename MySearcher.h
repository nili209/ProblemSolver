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
  Solution solution;
 protected:
  /**
 * Given a state, goal state and init state, the function returns the
 * trace of the state from init state to goal state.
 * In this assigment the trace back is a string but in case of a change we
 * need just to change the inner implementation of this function.
 */
  Solution backTrace(State<T> *state, State<T> *init, State<T> *goal) {
    string s = "";
    if (state->Equals(init)) {
      s = solution;
      solution = "";
      return s;
    }
    //up, down, right or left.
    string direction = state->getDirection();
    string trail_cost = "(" + to_string(int(state->getTrailCost())) + ")";
    direction += trail_cost;
    solution.insert(0, direction);
    if (!state->Equals(goal)) {
      solution.insert(direction.length(), ", ");
    }
    return backTrace(state->getComeFrom(), init, goal);
  }
  /**
   * The function checks if a state is in closed.
   */
  bool isClosedContain(State<T> *s, vector<State<T>*> closed) {
    for (State<T>* n : closed) {
      if (s->Equals(n)) {
        return true;
      }
    }
    return false;
  }
 public:
  /**
 * Constructor.
 */
  MySearcher<T, Solution>() {};
  /**
   * Destructor.
   */
  virtual ~MySearcher() = default;
};
#endif //EX4_MYSEARCHER_H
