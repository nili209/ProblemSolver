////
//// Created by shiraz on 14.1.2020.
////
//
//#ifndef EX4__PRIORITYQUEUESEARCHER_H_
//#define EX4__PRIORITYQUEUESEARCHER_H_
//#include <queue>
//#include <iostream>
//#include "MySearcher.h"
////getCompare
//template<typename T, typename Solution>
////T = Point
//class PriorityQueueSearcher : public MySearcher<T, Solution> {
//  class MyComperator {
//   public:
//    bool operator()(State<T> *left, State<T> *right) {
//      double comparator_left = getCompare(left);//;left->getTrailCost() + left->gerHeuristic();
//      double comparator_right = getCompare(right);//right->getTrailCost() + right->gerHeuristic();
//      return (comparator_left > comparator_right);
//    }
//  };
// public:
//  PriorityQueueSearcher(){}
// protected:
//  priority_queue<State<T> *, vector<State<T> *>, MyComperator> open_priority_queue;
//  static double getCompare(State<T>* state);
//  /**
//* Given a State, the function returns true if open priority queue  contains it and false otherwise.
//*/
//  bool isOpenContain(State<T> *state1) {
//    priority_queue<State<T> *, vector<State<T> *>, MyComperator> temp = open_priority_queue;
//    while (!temp.empty()) {
//      State<T> *state2 = temp.top();
//      if (state1->Equals(state2)) {
//        return true;
//      }
//      temp.pop();
//    }
//    return false;
//  }
//  priority_queue<State<T>*, vector<State<T> *>, MyComperator> updatePriorityQ(priority_queue<State<T> *,
//                                                                                             vector<State<T> *>, MyComperator> prev_priority_queue){
//    priority_queue<State<T> *, vector<State<T> *>, MyComperator> newQ;
//    while (!prev_priority_queue.empty()) {
//      newQ.push(prev_priority_queue.top());
//      prev_priority_queue.pop();
//    }
//    return newQ;
//  }
//};
//#endif //EX4__PRIORITYQUEUESEARCHER_H_
