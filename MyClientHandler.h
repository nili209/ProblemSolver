//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H

#include <sys/socket.h>
#include <unistd.h>
#include "ClientHandler.h"
#include "State.h"
#include "Point.h"
#include "State.h"
#include "Searchable.h"
#include "SearchSolver.h"
#include "FileCacheManager.h"
#include <string>
#include <cstring>
#define LINE_SIZE 1024
#define END_OF_MESSAGE 'e'
template<typename Problem, typename Solution>
class MyClientHandler : public ClientHandler {
 private:
  CacheManager<Problem, Solution> *cache_manager;
  string problem = "";
  Solver<Problem, Solution> *solver;
 public:
  MyClientHandler(Solver<Problem, string> *solver1, CacheManager<Problem, Solution> *cache_menager1) :
  solver(solver1), cache_manager(cache_menager1) {}
  virtual void handleClient(int client_socket_in, int client_socket_out) {
    const char *solution;
    string s = "";
    //just read into a buffer of string problem
    initProblem(client_socket_in);
    if (cache_manager->isSolved(problem)) {
      solution = cache_manager->getSolution(problem).c_str();
    } else {
      s= solver->solve(problem);
      solution = s.c_str();
      cache_manager->saveSolution(solution, problem);
    }
    int is_sent = send(client_socket_out, solution, strlen(solution), 0);
    if (is_sent == -1) {
      cout << "Error sending message" << endl;
      exit(1);
    }
  }
  void initProblem(int client_socket_in) {
    while (true) {
      char buffer[LINE_SIZE] = {0};
      int valread = read(client_socket_in, buffer, LINE_SIZE);
      int i = 0;
      while (i < valread) {
        if (buffer[i] == END_OF_MESSAGE) {
          return;
        }
        //todo
        if(buffer[i] == '\\') {
          problem += ";";
          i+=2;
          continue;
        }
        if (buffer[i] == '\n') {
          problem += ";";
          i++;
          continue;
        }
        problem += buffer[i];
        i++;
      }
    }
  }
  virtual ~MyClientHandler() = default;
};

#endif //EX4_MYCLIENTHANDLER_H
