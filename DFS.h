//
// Created by nili on 1/14/20.
//

#ifndef EX4_DFS_H
#define EX4_DFS_H

#include <string>
#include <stack>
#include <vector>
#include "MySearcher.h"

template<typename T, typename Solution>
//T = Point
class DFS : public MySearcher<T, Solution> {
private:
    stack<State<T> *> my_stack;
public:
    string search(Searchable<T> *searchable) {
        State<T> *init_state = searchable->getInitialState();
        State<T> *goal_state = searchable->getGoalState();
        my_stack.push(init_state);
        init_state->setVisited(true);
        while (!my_stack.empty()) {
            State<T> *current_state = my_stack.top();
            if (current_state->Equals(searchable->getGoalState())) {
                return this->backTrace(current_state, searchable->getInitialState(), searchable->getGoalState());
            }
            this->setNumberOfNodesEvaluated(1);
            my_stack.pop();
            vector<State<T> *> neighbors = searchable->getAllPossibleStates(current_state);
            for (State<T> *neighbor : neighbors) {
                if (!neighbor->isVisited()) {
                    neighbor->setVisited(true);
                    neighbor->setComeFrom(current_state);
                    my_stack.push(neighbor);
                }
            }
        }
    }

};

#endif //EX4_DFS_H
