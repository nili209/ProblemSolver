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
  int number_of_nodes_evaluated = 0;
  Solution solution;
 protected:
  /**
   * Given a number, the function add the number to number of nodes evaluated.
   */
  void setNumberOfNodesEvaluated(int num) {
    number_of_nodes_evaluated += num;
  }
  /**
   * Reset number os nodes evaluated.
   */
  void clearNumberOfNodesEvaluated() {
    number_of_nodes_evaluated = 0;
  }
  /**
 * Given a state, goal state and init state, the function returns the
 * trace of the state from init state to goal state.
 * In this assigment the trace back is a string but in case of a change we
 * need just to change the inner implementation of this function.
 */
  Solution backTrace(State<T> *state, State<T> *init, State<T> *goal) {
    string s = "";
    if (state->Equals(init)) {
      cout<<"Number of nodes evaluated: "<< number_of_nodes_evaluated <<endl;
      number_of_nodes_evaluated = 0;
      s = solution;
      solution = "";
      return s;
    }
    //up, down, right or left.
    string direction = state->getDirection();
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
  virtual Solution search(Searchable<T> *searchable) = 0;
  /**
   * The function returns the number of nodes evaluated.
   */
  int getNumberOfNodesEvaluated() {
    return number_of_nodes_evaluated;
  }
  /**
   * Destructor.
   */
  virtual ~MySearcher() = default;
};
#endif //EX4_MYSEARCHER_H
