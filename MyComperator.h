//
// Created by shiraz on 9.1.2020.
//

#ifndef EX4__MYCOMPERATOR_H_
#define EX4__MYCOMPERATOR_H_
#include "State.h"
template<typename T>
class MyComperator {
 public:
  bool operator() (const State<T>& state1, const State<T>& state2)
  {
    return state1->getTrailCost() > state2->getTrailCost();
  }
};

#endif //EX4__MYCOMPERATOR_H_
