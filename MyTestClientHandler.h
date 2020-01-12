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
  MyTestClientHandler(Solver<Problem, Solution> *solver1, CacheManager<string, Solution>* cache_manager1) :
      solver(solver1), cache_manager(cache_manager1) {}
  virtual void handleClient(int client_socket_in, int client_socket_out) {
    myTestClientHandler(client_socket_in);
  }
  void myTestClientHandler(int client_socket_in) {
    while(true) {
      char buffer[LINE_SIZE] = {0};
      int valread = read(client_socket_in, buffer, LINE_SIZE);
      char *temp_problem = new char[valread];
      strcpy(temp_problem, buffer);
      if (strcmp(temp_problem, END) == 0) {
        return;
      }
      cout << buffer << endl;
      string problem = temp_problem;
      cache_manager->isSolved(problem);
      string solution = "";
      if (cache_manager->isSolved(problem)) {
        solution = cache_manager->getSolution(problem);
      } else {
        solution = solver->solve(problem);
        cache_manager->saveSolution(solution.c_str(), problem);
      }
      const char* solution_to_send = solution.c_str();
      int is_sent = send(client_socket_in, solution_to_send, strlen(solution_to_send), 0);
      if (is_sent == -1) {
        cout << "Error sending message" << endl;
        exit(1);
      }
    }
  }
  virtual ~MyTestClientHandler() {
    delete solver;
    delete cache_manager;
  }
};

#endif //EX4_MYTESTCLIENTHANDLER_H
