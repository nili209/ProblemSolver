//
// Created by nili on 1/8/20.
//

#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H

#include <string>
#include <queue>
#include <vector>
#include "MySearcher.h"
template <typename T>
class BestFirstSearch : public  MySearcher<string, T> {
private:
    priority_queue<State<T>*> open_priority_queue;
    vector<State<T>*> closed;
    string solution;
    string backTrace() {
        //update the solution
        return solution;
    }

public:
    BestFirstSearch<T>(){};
    virtual string search(Searchable<T>* searchable) {
        addToOpenPriorityQueue(searchable->getInitialState());
        while(!open_priority_queue.empty()) {
            State<T>* n = popOpenPriorityQueue();
            closed.push_back(n);
            if(n->Equals(searchable->getGoalState())) {
                return backTrace();
            }
            vector<State<T>*> succerssors = searchable->getAllPossibleStates(n);
            for(auto it = succerssors.begin(); it != succerssors.end(); ++it) {
                State<T>* s = *it;
                s->setComeFrom(n);
                if (!isClosedContain(s) && !isOpenContain(s)) {
                    s->setComeFrom(n);
                    addToOpenPriorityQueue(s);
                } else {
                    double prev_trial = s->getTrailCost();
                    double curr_trial = n->getTrailCost() + s->getCost();
                    if(curr_trial > prev_trial) {
                        if(!isOpenContain(s)) {
                            addToOpenPriorityQueue(s);
                        } else {
                            open_priority_queue.emplace(s);
                        }
                    }
                }
            }
        }
    }
    void addToOpenPriorityQueue(State<T>* s) {
        open_priority_queue.push(s);
    }
    State<T>* popOpenPriorityQueue() {
        State<T>* temp = open_priority_queue.top();
        open_priority_queue.pop();
        return temp;
    }
    bool isClosedContain(State<T>* s) {
        for(auto it = closed.begin(); it != closed.end(); ++it) {
            State<T>* n = *it;
            if (s->Equals(n)) {
                return true;
            }
        }
        return false;
    }
    bool isOpenContain(State<T>* s) {
        for(auto it = open_priority_queue.begin(); it != open_priority_queue.end(); ++it) {
            if(s->Equals(it)) {
                return true;
            }
        }
        return false;
    }
    virtual ~BestFirstSearch();

};
#endif //EX4_BESTFIRSTSEARCH_H
