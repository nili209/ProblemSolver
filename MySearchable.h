//
// Created by nili and shiraz on 9.1.2020.
//

#ifndef EX4__MYSEARCHABLE_H_
#define EX4__MYSEARCHABLE_H_
#include "Searchable.h"
template <typename T>
class MySearchable : public Searchable<T> {
 protected:
  State<T>* initial_state;
  State<T>* goal_state;
  vector<State<T>*> structure;
 public:
  /**
   * Constructor.
   */
  MySearchable<T>(State<T>* initial_state1, State<T>* goal_state1, vector<State<T>*> structure1) :
      initial_state(initial_state1), goal_state(goal_state1), structure(structure1) {}
  /**
* Getter for initial_state.
*/
  State<T>* getInitialState() {
    return initial_state;
  }
  /**
   * Getter for goal_state.
   */
  State<T>* getGoalState() {
    return goal_state;
  }
  /**
   * Given a state, the function returns all possible states for the state.
   */
  virtual vector<State<T>*> getAllPossibleStates(State<T>* s) = 0;
  virtual ~MySearchable() {
    delete initial_state;
    delete goal_state;
  }
};
#endif //EX4__MYSEARCHABLE_H_
