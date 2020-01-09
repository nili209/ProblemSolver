//
// Created by shiraz on 9.1.2020.
//


#include "Matrix.h"
Matrix::Matrix(State<Point>* initial_state1, State<Point>* goal_state1, vector<State<Point>*> structure1)
: MySearchable(initial_state1, goal_state1, structure1) {}
vector<State<Point>*> Matrix::getAllPossibleStates(State<Point>* other_state) {
  vector<State<Point>*> neighbors;
  for (State<Point>* state : structure) {
    if (state->getState().isNeighbor(other_state->getState())) {
      neighbors.push_back(state);
    }
  }
  return neighbors;
}

