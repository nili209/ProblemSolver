//
// Created by nili and shiraz on 14.1.2020.
//

#ifndef EX4__ASTAR_H_
#define EX4__ASTAR_H_
#include <queue>
#include <iostream>
#include "MySearcher.h"
template<typename T, typename Solution>
class AStar : public MySearcher<T, Solution> {
  class MyComperator {
   public:
    bool operator()(State<T> *left, State<T> *right) {
      double f_left = left->getTrailCost() + left->gerHeuristic();
      double f_right = right->getTrailCost() + right->gerHeuristic();
      return (f_left > f_right);
    }
  };
 private:
  priority_queue<State<T> *, vector<State<T> *>, MyComperator> open_priority_queue;
 public:
  /**
   * Given a Searchable, the function returns a path from it's initial state to it's goal state.
   * Using the algorithm of AStar.
   */
  Solution search(Searchable<T> *searchable) {
    State<T> *init_state = searchable->getInitialState();
    State<T> *goal_state = searchable->getGoalState();
    open_priority_queue.push(init_state);
    while (!this->open_priority_queue.empty()) {
      State<T> *current_state = this->open_priority_queue.top();
      open_priority_queue.pop();
      this->setNumberOfNodesEvaluated(1);
      if (current_state->Equals(goal_state)) {
        cout << "AStar:" << endl;
        cout << "Trial cost: " << current_state->getTrailCost() << endl;
        return this->backTrace(current_state, init_state, goal_state);
      }
      this->addToClosed(current_state);
      vector<State<T> *> neighbors = searchable->getAllPossibleStates(current_state);
      for (State<T> *neighbor : neighbors) {
        double possible_trail_cost = neighbor->getCost() + current_state->getTrailCost();
        if (!isOpenContain(neighbor) && !this->isClosedContain(neighbor)) {
          neighbor->setComeFrom(current_state);
          neighbor->setTrailCost(possible_trail_cost);
          setHeuristic(neighbor, goal_state);
          open_priority_queue.push(neighbor);
          continue;
        } else if (this->isClosedContain(neighbor)) {
          continue;
        } else if (possible_trail_cost < neighbor->getTrailCost()) {
          neighbor->setComeFrom(current_state);
          neighbor->setTrailCost(possible_trail_cost);
          setHeuristic(neighbor, goal_state);
          open_priority_queue = updatePriorityQ(open_priority_queue);
        }
      }
    }
    return NO_PATH;
  }
  /**
  * The function calculates the heuristic value and updates it.
  */
  void setHeuristic(State<T>* neighbor, State<T>* goal_state) {
    int x_neighbor = neighbor->getState().getX(), y_neighbor = neighbor->getState().getY(),
    x_goal = goal_state->getState().getX(), y_goal = goal_state->getState().getY();
    neighbor->setHeuristic(abs(x_goal - x_neighbor) + abs(y_goal - y_neighbor));
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
  bool isOpenContain(State<T> *state1) {
    priority_queue<State<T> *, vector<State<T> *>, MyComperator> temp = open_priority_queue;
    while (!temp.empty()) {
      State<T> *state2 = temp.top();
      if (state1->Equals(state2)) {
        return true;
      }
      temp.pop();
    }
    return false;
  }/**
   * Destructor.
   */
  virtual ~AStar() = default;
};
#endif //EX4__ASTAR_H_
