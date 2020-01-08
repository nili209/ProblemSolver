//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_STRINGREVERSER_H
#define EX4_STRINGREVERSER_H

#include "Solver.h"
#include <string>

class StringReverser : public Solver<string, string> {
public:
    virtual string solve(string problem) {
        int n = problem.length();
        for (int i = 0; i < n / 2; i++) {
            swap(problem[i], problem[n - i - 1]);
        }
        return problem;
    }
};
#endif //EX4_STRINGREVERSER_H
