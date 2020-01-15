//
// Created by nili and shiraz on 1/14/20.
//

#ifndef EX4_DFS_H
#define EX4_DFS_H

#include <string>
#include <stack>
#include <vector>
#include "MySearcher.h"

template<typename T, typename Solution>
//T = Point
class DFS : public MySearcher<T, Solution> {
 private:
  stack<State<T> *> my_stack;
 public:
  /**
   * Given a Searchable, the function returns the a path from it's initial state to it's goal state.
   * Using the algorithm of Best First Search.
   */
  Solution search(Searchable<T> *searchable) {
    State<T> *init_state = searchable->getInitialState();
    State<T> *goal_state = searchable->getGoalState();
    my_stack.push(init_state);
    this->addToClosed(init_state);
    while (!my_stack.empty()) {
      State<T> *current_state = my_stack.top();
      my_stack.pop();
      this->setNumberOfNodesEvaluated(1);
      if (current_state->Equals(searchable->getGoalState())) {
        cout<<"DFS:"<<endl;
        cout<<"Trial cost: "<< current_state->getTrailCost()<<endl;
        return this->backTrace(current_state, init_state, goal_state);
      }
      vector<State<T> *> neighbors = searchable->getAllPossibleStates(current_state);
      for (State<T> *neighbor : neighbors) {
        if (!this->isClosedContain(neighbor)) {
          this->addToClosed(neighbor);
          neighbor->setComeFrom(current_state);
          my_stack.push(neighbor);
        }
      }
    }
    return NO_PATH;
  }
  /**
   * Destructor.
   */
  virtual ~DFS() = default;
};

#endif //EX4_DFS_H
