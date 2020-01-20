//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_MYTESTCLIENTHANDLER_H
#define EX4_MYTESTCLIENTHANDLER_H
#include <unistd.h>
#include <cstring>
#include <sys/socket.h>
#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#define END "end"
template<class Problem, class Solution>
class MyTestClientHandler : public ClientHandler {
 private:
  Solver<Problem, Solution> *solver;
  CacheManager<Problem, Solution> *cache_manager;
 public:
  /**
   * Constructor.
   */
  MyTestClientHandler(Solver<Problem, Solution> *solver1, CacheManager<string, Solution> *cache_manager1) :
      solver(solver1), cache_manager(cache_manager1) {}
      /**
       * Given a socket of client, the function reads data from the client and sends to the client the solution.
       */
  virtual void handleClient(int client_socket) {
    string problem = "", line = "";
    const char *temp;
    bool done = false;
    while (!done) {
      problem = "";
      char buffer[LINE_SIZE] = {0};
      int valread = read(client_socket, buffer, LINE_SIZE);
      int i = 0;
      while (i < valread) {
        if (buffer[i] == '\n') {
          done = true;
          break;
        }
        problem += buffer[i];
        i++;
      }
    }
    string solution = "";
    //check if the problem already solved
    if (cache_manager->isSolved(problem)) {
      solution = cache_manager->getSolution(problem);
      //the problem is not solved
    } else {
      const char *p = problem.c_str();
      solution = solver->solve(p);
      cache_manager->saveSolution(solution.c_str(), problem);
    }
    const char *solution_to_send = solution.c_str();
    int is_sent = send(client_socket, solution_to_send, strlen(solution_to_send), 0);
    if (is_sent == -1) {
      cout << "Error sending message" << endl;
      exit(1);
    }
  }
  /**
   * Destructor.
   */
  virtual ~MyTestClientHandler() {
    delete solver;
    delete cache_manager;
  }
};

#endif //EX4_MYTESTCLIENTHANDLER_H
