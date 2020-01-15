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
  vector<State<T>*> closed;
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
      cout<<"Number of nodes evaluated: "<< number_of_nodes_evaluated <<endl;
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
  /**
   * The function inserts a new state to closed.
   */
  void addToClosed(State<T>* s) {
    closed.push_back(s);
  }
  /**
   * The function checks if a state is in closed.
   */
  bool isClosedContain(State<T> *s) {
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
