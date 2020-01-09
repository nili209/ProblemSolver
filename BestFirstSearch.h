//
// Created by nili on 1/8/20.
//

#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H

#include <string>
#include <queue>
#include <vector>
#include "MySearcher.h"
template<typename T>
class BestFirstSearch : public MySearcher<string, T> {
  class MyComperator {
   public:
    bool operator()(State<T>* left, State<T>* right) {
      return (left->getTrailCost()) > (right->getTrailCost());
    }
  };
 private:
  priority_queue<State<T>*, vector<State<T>*>, MyComperator> open_priority_queue;
  vector<State<T>*> closed;
  string solution;
  string backTrace(State<T>* state, State<T>* init, State<T>* goal) {
    if(state->Equals(init)) {
      return solution;
    }
    string direction = state->getDirection();
    solution.insert(0, direction);
    MySearcher<string, Point>::number_of_nodes_evaluated++;
    if (!state->Equals(goal)) {
      solution.insert(direction.length(), ", ");
    }
    return backTrace(state->getComeFrom(), init, goal);
  }
 public:
  virtual string search(Searchable<T> *searchable) {
    addToOpenPriorityQueue(searchable->getInitialState());
    while (!open_priority_queue.empty()) {
      State<T>* current = popOpenPriorityQueue();
      closed.push_back(current);
      if (current->Equals(searchable->getGoalState())) {
        return backTrace(current, searchable->getInitialState(), searchable->getGoalState());
      }
      vector<State<T>*> neighbors = searchable->getAllPossibleStates(current);
      for(State<T>* neighbor : neighbors) {
        if (!isClosedContain(neighbor) && !isOpenContain(neighbor)) {
          neighbor->setComeFrom(current);
          addToOpenPriorityQueue(neighbor);
        } else {
          double prev_trial = neighbor->getTrailCost();
          double curr_trial = current->getTrailCost() + neighbor->getCost();
          if (curr_trial < prev_trial) {
            if (!isOpenContain(neighbor)) {
              addToOpenPriorityQueue(neighbor);
            } else {
              neighbor->setTrailCost(curr_trial);
              neighbor->setComeFrom(current);
              open_priority_queue = updatePriorityQ(open_priority_queue);
            }
          }
        }
      }
    }
  }
  priority_queue<State<T>*, vector<State<T> *>, MyComperator> updatePriorityQ(priority_queue<State<T> *,
      vector<State<T> *>, MyComperator> prev_priority_queue){
    priority_queue<State<T> *, vector<State<T> *>, MyComperator> newQ;
    while (!prev_priority_queue.empty()) {
      newQ.push(prev_priority_queue.top());
      prev_priority_queue.pop();
    }
    return newQ;
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
  virtual ~BestFirstSearch() = default;

};
#endif //EX4_BESTFIRSTSEARCH_H
