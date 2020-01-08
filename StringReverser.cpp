//
// Created by nili and shiraz on 1/8/20.
//
#include "StringReverser.h"
string StringReverser::solve(string problem) {
    int n = problem.length();
    for (int i = 0; i < n / 2; i++) {
        swap(problem[i], problem[n - i - 1]);
    }
    return problem;
}

