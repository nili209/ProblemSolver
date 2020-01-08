//
// Created by nili and shiraz  on 1/8/20.
//

#ifndef EX4_SOLVER_H
#define EX4_SOLVER_H
using namespace std;
template <class Problem, class Solution>
 class Solver {
 public:
     virtual Solution solve(Problem problem) = 0;
     virtual ~Solver() = default;
 };

#endif //EX4_SOLVER_H
