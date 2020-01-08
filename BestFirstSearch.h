//
// Created by nili on 1/8/20.
//

#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H

#include <string>
#include <queue>
#include "MySearcher.h"
template <typename T>
class BestFirstSearch : public  MySearcher<string> {
private:
    queue<State<T>*> open_queue;
    string solution;
public:
    virtual string search(Searchable<T>* searchable) {

    }
    void addToOpenQueue(State<T>* s) {
        open_queue.push(s);
    }
    State<T>* popOpenQueue() {
        State<T>* temp = open_queue.front();
        open_queue.pop();
        return temp;
    }

};
#endif //EX4_BESTFIRSTSEARCH_H
