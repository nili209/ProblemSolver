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
#define LINE_SIZE 1024
#define END "end"
template<class Problem, class Solution>
class MyTestClientHandler : public ClientHandler {
 private:
  Solver<Problem, Solution> *solver;
  CacheManager<Problem, Solution> *cache_manager;
  //FileCacheManager<Solution>* cache_manager;
 public:
  MyTestClientHandler(Solver<Problem, Solution> *solver1, CacheManager<string, Solution> *cache_manager1) :
      solver(solver1), cache_manager(cache_manager1) {}
  virtual void handleClient(int client_socket_in, int client_socket_out) {
    myTestClientHandler(client_socket_in);
  }
  void myTestClientHandler(int client_socket_in) {
    string problem = "", line = "";
    const char *temp;
    bool done = false;
    while (!done) {
      problem = "";
      char buffer[LINE_SIZE] = {0};
      int valread = read(client_socket_in, buffer, LINE_SIZE);
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
      if (cache_manager->isSolved(problem)) {
        solution = cache_manager->getSolution(problem);
      } else {
        const char* p = problem.c_str();
        solution = solver->solve(p);
        cache_manager->saveSolution(solution.c_str(), problem);
      }
      const char *solution_to_send = solution.c_str();
      int is_sent = send(client_socket_in, solution_to_send, strlen(solution_to_send), 0);
      if (is_sent == -1) {
        cout << "Error sending message" << endl;
        exit(1);
      }
  }
  virtual ~MyTestClientHandler() {
    delete solver;
    delete cache_manager;
  }
};

#endif //EX4_MYTESTCLIENTHANDLER_H
