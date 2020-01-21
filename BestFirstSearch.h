//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H

#include <string>
#include <queue>
#include <vector>
#include "MySearcher.h"
template<typename T, typename Solution>
class BestFirstSearch : public MySearcher<T, Solution> {
  class MyComperator {
   public:
    bool operator()(State<T>* left, State<T>* right) {
      return (left->getTrailCost()) > (right->getTrailCost());
    }
  };
 public:
  /**
 * Constructor.
 */
  BestFirstSearch(){};
  /**
   * Given a Searchable, the function returns the cheapest path from it's initial state to it's goal state.
   * Using the algorithm of Best First Search.
   */
  Solution search(Searchable<T> *searchable) {
    int number_of_nodes_evaluated = 0;
    vector<State<T>*> closed;
    priority_queue<State<T>*, vector<State<T>*>, MyComperator> open_priority_queue;
    State<T>* init_state = searchable->getInitialState();
    State<T>* goal_state = searchable->getGoalState();
    open_priority_queue.push(init_state);
    while (!open_priority_queue.empty()) {
      //pop the lowest trial cost state from open queue.
      State<T>* current_state = open_priority_queue.top();
      open_priority_queue.pop();
      closed.push_back(current_state);
      number_of_nodes_evaluated++;
      //this is the goal state.
      if (current_state->Equals(searchable->getGoalState())) {
        return this->backTrace(current_state, init_state, goal_state);
      }
      vector<State<T>*> neighbors = searchable->getAllPossibleStates(current_state);
      for(State<T>* neighbor : neighbors) {
        //we did not reached to this state until now or we already done evaluating it.
        if (!this->isClosedContain(neighbor, closed) && !isOpenContain(neighbor, open_priority_queue)) {
          neighbor->setComeFrom(current_state);
          open_priority_queue.push(neighbor);
        } else {
          double prev_trial = neighbor->getTrailCost();
          double curr_trial = current_state->getTrailCost() + neighbor->getCost();
          //the current path is better.
          if (curr_trial < prev_trial) {
            if (!isOpenContain(neighbor,open_priority_queue)) {
              open_priority_queue.push(neighbor);
            } else {
              //update the trial cost to the lower trial cost.
              neighbor->setTrailCost(curr_trial);
              neighbor->setComeFrom(current_state);
              open_priority_queue = updatePriorityQ(open_priority_queue);
            }
          }
        }
      }
    }
    return NO_PATH;
  }
  /**
   * The function updates the open priority queue.
   */
  priority_queue<State<T>*, vector<State<T> *>, MyComperator> updatePriorityQ(priority_queue<State<T> *,
      vector<State<T> *>, MyComperator> prev_priority_queue){
    priority_queue<State<T> *, vector<State<T> *>, MyComperator> newQ;
    while (!prev_priority_queue.empty()) {
      newQ.push(prev_priority_queue.top());
      prev_priority_queue.pop();
    }
    return newQ;
  }
  /**
 * Given a State, the function returns true if open priority queue  contains it and false otherwise.
 */
  bool isOpenContain(State<T> *state1, priority_queue<State<T>*, vector<State<T>*>, MyComperator> open_priority_queue) {
    priority_queue<State<T>*, vector<State<T>*>, MyComperator> temp = open_priority_queue;
    while (!temp.empty()) {
        State<T>* state2 = temp.top();
        if (state1->Equals(state2)) {
          return true;
        }
        temp.pop();
    }
    return false;
  }
  /**
   * Destructor.
   */
  virtual ~BestFirstSearch() = default;

};
#endif //EX4_BESTFIRSTSEARCH_H
