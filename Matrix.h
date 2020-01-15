//
// Created by nili and shiraz on 9.1.2020.
//

#ifndef EX4__MATRIX_H_
#define EX4__MATRIX_H_
#include "MySearchable.h"
#include "Point.h"
class Matrix : public MySearchable<Point> {
 public:
  Matrix(State<Point>* initial_state1, State<Point>* goal_state1,vector<State<Point>*> structure1);
  vector<State<Point>*> getAllPossibleStates(State<Point>* s);
};

#endif //EX4__MATRIX_H_
