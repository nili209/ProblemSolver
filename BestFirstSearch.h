//
// Created by nili on 1/8/20.
//

#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H

#include <string>
#include <queue>
#include <vector>
#include "MySearcher.h"
#include "MyComperator.h"
template<typename T>
class BestFirstSearch : public MySearcher<string, T> {
 private:
  priority_queue<State<T>*> open_priority_queue;
  vector<State<T>*> closed;
  string solution;
  string backTrace(State<T>* state, State<T>* init, State<T>* goal) {
    if(state->Equals(init)) {
      return solution;
    }
    string direction = state->getDirection();
    solution.insert(0, direction);
    if (!state->Equals(goal)) {
      solution.insert(direction.length(), ", ");
    }
    return backTrace(state->getComeFrom(), init, goal);
  }
 public:
  virtual string search(Searchable<T> *searchable) {
    addToOpenPriorityQueue(searchable->getInitialState());
    while (!open_priority_queue.empty()) {
      State<T>* n = popOpenPriorityQueue();
      closed.push_back(n);
      State<Point>* goal_state = searchable->getGoalState();
      if (n->Equals(goal_state)) {
        return backTrace(n, searchable->getInitialState(), searchable->getGoalState());
      }
      vector<State<T>*> succerssors = searchable->getAllPossibleStates(n);
      for( State<T>* s : succerssors) {
        if (!isClosedContain(s) && !isOpenContain(s)) {
           s->setComeFrom(n);
          addToOpenPriorityQueue(s);
        } else {
          double prev_trial = s->getTrailCost();
          double curr_trial = n->getTrailCost() + s->getCost();
          if (curr_trial < prev_trial) {
            if (!isOpenContain(s)) {
              addToOpenPriorityQueue(s);
            } else {
             // open_priority_queue.emplace(s);
            }
          }
        }
      }
    }
  }
  void addToOpenPriorityQueue(State<T> *s) {
    open_priority_queue.push(s);
  }
  State<T>* popOpenPriorityQueue() {
    State<T>* temp = open_priority_queue.top();
    open_priority_queue.pop();
    return temp;
  }
  bool isClosedContain(State<T> *s) {
    for (State<T>* n : closed) {
      if (s->Equals(n)) {
        return true;
      }
    }
    return false;
  }
  bool isOpenContain(State<T> *state1) {
    priority_queue<State<T>*> temp = open_priority_queue;
    while (!temp.empty()) {
        State<T>* state2 = temp.top();
        if (state1->Equals(state2)) {
          return true;
        }
        temp.pop();
    }
    return false;
  }
  virtual ~BestFirstSearch() = default;

};
#endif //EX4_BESTFIRSTSEARCH_H
