//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
template <class Problem, class Solution>
class MyTestClientHandler : public ClientHandler {
private:
    Solver<Problem, Solution>* solver;
    CacheManager<Solution,Problem>* cache_manager;
public:
    virtual void handleClient(istream input_stream, ostream output_stream) {
    }
    Solution myTestClientHandler(istream istream) {
        Solution solution;
        return solution;
    }
    virtual ~MyTestClientHandler() {
        delete solver;
        delete cache_manager;
    }
};


#endif //EX4_MYTESTCLIENTHANDLER_H
