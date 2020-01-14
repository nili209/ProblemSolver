//
// Created by shiraz on 14.1.2020.
//

#ifndef EX4__BFS_H_
#define EX4__BFS_H_
#include <string>
#include <queue>
//#include <vector>
#include "MySearcher.h"
template<typename T, typename Solution>
//T = Point
class BFS : public MySearcher<T, Solution> {
 private:
  queue<State<T> *> my_queue;
 public:
  /**
   * Given a Searchable, the function returns the shortest path from it's initial state to it's goal state.
   * Using the algorithm of BFS.
   */
  string search(Searchable<T> *searchable) {
    State<T>* init_state = searchable->getInitialState();
    State<T>* goal_state = searchable->getGoalState();
    my_queue.push(init_state);
    init_state->setVisited(true);
    while(!my_queue.empty()) {
      State<T>* current_state = dequeue();
      this->setNumberOfNodesEvaluated(1);
      if (current_state->Equals(goal_state)) {
        return this->backTrace(current_state, init_state, goal_state);
      }
      vector<State<T>*> neighbors = searchable->getAllPossibleStates(current_state);
      for(State<T>* neighbor : neighbors) {
        if (!neighbor->isVisited()) {
          neighbor->setVisited(true);
          neighbor->setComeFrom(current_state);
          my_queue.push(neighbor);
        }
      }
    }
    return NO_PATH;
  }
  State<T>* dequeue() {
    State<T>* front = my_queue.front();
    my_queue.pop();
    return front;
  }
};

#endif //EX4__BFS_H_
