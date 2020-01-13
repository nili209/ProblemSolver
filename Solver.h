//
// Created by nili and shiraz  on 1/8/20.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H
using namespace std;

#include <string>
template <class Problem, class Solution>
 class Solver {
 public:
     //Probelm = string
     virtual Solution solve(Problem problem) = 0;
     virtual ~Solver() = default;
 };

#endif //EX4_SOLVER_H
