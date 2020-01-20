//
// Created by nili and shiraz on 14.1.2020.
//

#ifndef EX4__BFS_H_
#define EX4__BFS_H_
#include <string>
#include <queue>
#include <vector>
#include "MySearcher.h"
template<typename T, typename Solution>
//T = Point
class BFS : public MySearcher<T, Solution> {
 public:
  /**
   * Given a Searchable, the function returns the shortest path from it's initial state to it's goal state.
   * Using the algorithm of BFS.
   */
  Solution search(Searchable<T> *searchable) {
    int number_of_nodes_evaluated = 0;
    queue<State<T> *> my_queue;
    vector<State<T>*> closed;
    State<T>* init_state = searchable->getInitialState();
    State<T>* goal_state = searchable->getGoalState();
    my_queue.push(init_state);
    closed.push_back(init_state);
    while(!my_queue.empty()) {
      State<T>* current_state = my_queue.front();
      my_queue.pop();
      number_of_nodes_evaluated++;
      //we reached the end - found the goal state.
      if (current_state->Equals(goal_state)) {
        return this->backTrace(current_state, init_state, goal_state);
      }
      vector<State<T>*> neighbors = searchable->getAllPossibleStates(current_state);
      for(State<T>* neighbor : neighbors) {
        if (!this->isClosedContain(neighbor, closed)) {
          closed.push_back(neighbor);
          neighbor->setComeFrom(current_state);
          my_queue.push(neighbor);
        }
      }
    }
    return NO_PATH;
  }
  /**
   * Destructor.
   */
  virtual ~BFS() = default;
};

#endif //EX4__BFS_H_
