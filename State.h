//
// Created by nili on 1/8/20.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H
using namespace std;
template <typename T>
class State {
private:
    T state;
    double cost;
    double trail_cost;
    State<T>* come_from;
public:
    State<T>(T state1, double cost1) : state(state1), cost(cost1), trail_cost(cost1), come_from(nullptr) {}
    bool Equals(State<T>* s) {
        //we used == but it should be Equals
        return this->state == s->state;
    }
};
#endif //EX4_STATE_H
