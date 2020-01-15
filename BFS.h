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
 private:
  queue<State<T> *> my_queue;
 public:
  /**
   * Given a Searchable, the function returns the shortest path from it's initial state to it's goal state.
   * Using the algorithm of BFS.
   */
  Solution search(Searchable<T> *searchable) {
    State<T>* init_state = searchable->getInitialState();
    State<T>* goal_state = searchable->getGoalState();
    my_queue.push(init_state);
    this->addToClosed(init_state);
    while(!my_queue.empty()) {
      State<T>* current_state = my_queue.front();
      my_queue.pop();
      this->setNumberOfNodesEvaluated(1);
      if (current_state->Equals(goal_state)) {
        cout<<"BFS:"<<endl;
        cout<<"Trial cost: "<< current_state->getTrailCost()<<endl;
        return this->backTrace(current_state, init_state, goal_state);
      }
      vector<State<T>*> neighbors = searchable->getAllPossibleStates(current_state);
      for(State<T>* neighbor : neighbors) {
        if (!this->isClosedContain(neighbor)) {
          this->addToClosed(neighbor);
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
