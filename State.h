//
// Created by nili on 1/8/20.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H
#include "Point.h"
#include <string>
#define UP "Up"
#define DOWN "Down"
#define RIGHT "Right"
#define LEFT "Left"
using namespace std;
template<typename T>
class State {
 private:
  Point state;
  double cost;
  double trail_cost;
  State<Point> *come_from;
 public:
  State<T>(T state1, double cost1) : state(state1), cost(cost1), trail_cost(cost1), come_from(nullptr) {}
  bool Equals(State<Point>* s) {
    //we used == but it should be Equals
    return state == s->state;
  }
  double getTrailCost() const {
    return trail_cost;
  }
  double getCost() {
    return cost;
  }
  void setComeFrom(State<Point> *s) {
    come_from = s;
    trail_cost += s->getTrailCost();
  }
  State<T>* getComeFrom() {
    return come_from;
  }
  T getState() {
    return state;
  }
  bool operator<(const State<Point>*& state) const {
    return (trail_cost < state->getTrailCost());
  }
  string getDirection() {
    Point parent = come_from->getState();
    if (parent.isNeighbor(state)) {
      if (parent.isUpNeighbor(state)) {
        return UP;
      }
      if(parent.isDownNeighbor(state)) {
        return DOWN;
      }
      if(parent.isRightNeighbor(state)) {
        return RIGHT;
      }
      if (parent.isLeftNeighbor(state)) {
        return LEFT;
      }
    }
    return nullptr;
  }
  virtual ~State() = default;
};
#endif //EX4_STATE_H
