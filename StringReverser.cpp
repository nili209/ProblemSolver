//
// Created by nili and shiraz on 1/8/20.
//
#include "StringReverser.h"
/**
 * Given a string, the function returns the reverse string.
 */
const char* StringReverser::solve(string problem) {
    int n = problem.length();
    for (int i = 0; i < n / 2; i++) {
        swap(problem[i], problem[n - i - 1]);
    }
    return problem.c_str();
}

