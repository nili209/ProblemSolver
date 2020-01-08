//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H

#include "State.h"
#include <vector>
using namespace std;
template <typename T>
class Searchable {
public:
    virtual State<T>* getInitialState();
    virtual State<T>* getGoalState();
    virtual vector<State<T>*> getAllPossibleStates(State<T>* s);
    virtual ~Searchable() = default;

};


#endif //EX4_SEARCHABLE_H
