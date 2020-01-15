//
// Created by nili and shiraz on 9.1.2020.
//


#include "Matrix.h"
/**
 * Constructor.
 */
Matrix::Matrix(State<Point> *initial_state1, State<Point> *goal_state1, vector<State<Point> *> structure1)
    : MySearchable(initial_state1, goal_state1, structure1) {}
/**
 * Given a State, the function returns all it's neighbors.
 */
vector<State<Point> *> Matrix::getAllPossibleStates(State<Point> *other_state) {
  vector<State<Point> *> neighbors;
  for (State<Point> *state : structure) {
    Point current_point = state->getState();
    Point other_point = other_state->getState();
    if (current_point.isNeighbor(other_point)) {
      //if this is -1 it means that this is a wall
      if (state->getCost() >= 0) {
        neighbors.push_back(state);
      }
    }
  }
  return neighbors;
}

