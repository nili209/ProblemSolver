//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_STRINGREVERSER_H
#define EX4_STRINGREVERSER_H
#include "Solver.h"
#include <string>

class StringReverser : public Solver<string, string> {
public:
    virtual string solve(string problem);
    virtual ~StringReverser() = default;
};
#endif //EX4_STRINGREVERSER_H
