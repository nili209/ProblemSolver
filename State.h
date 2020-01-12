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
  /**
   * Constructor.
   */
  State<T>(T state1, double cost1) : state(state1), cost(cost1), trail_cost(cost1), come_from(nullptr) {}
  /**
   * Given a State, the function returns true if it's state equals to this state and false otherwise.
   */
  bool Equals(State<T>* s) {
    return state == s->state;
  }
  /**
   * Getter of trail_cost.
   */
  double getTrailCost() const {
    return trail_cost;
  }
  /**
   * Given a new_trial_cost the function updates the trail_cost.
   */
  void setTrailCost(double new_trial_cost) {
    trail_cost = new_trial_cost;
  }
  /**
   * Getter of cost.
   */
  double getCost() {
    return cost;
  }
  /**
   * Given a State, the function udpates come_from and trail_cost.
   */
  void setComeFrom(State<Point> *s) {
    come_from = s;
    trail_cost += s->getTrailCost();
  }
  /**
   * Getter of come_from.
   */
  State<T>* getComeFrom() {
    return come_from;
  }
  /**
 * Getter of state.
 */
  T getState() {
    return state;
  }
  /**
   * The function returns the direction necessary to get the this state's parent.
   */
  string getDirection() {
    Point parent = come_from->getState();
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
    return nullptr;
  }
  /**
   * Destructor.
   */
  virtual ~State() = default;
};
#endif //EX4_STATE_H
