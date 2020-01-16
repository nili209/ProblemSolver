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
#include <mutex>
#define END_OF_MESSAGE 'e'
template<typename Problem, typename Solution>
class MyClientHandler : public ClientHandler {
 private:
  CacheManager<Problem, Solution> *cache_manager;
  //string problem = "";
  Solver<Problem, Solution> *solver;
 public:
  /**
   * Constructor.
   */
  MyClientHandler(Solver<Problem, string> *solver1, CacheManager<Problem, Solution> *cache_menager1) :
  solver(solver1), cache_manager(cache_menager1) {}
  /**
   * Given a socket of client, the function reads data from the client and sends to the client the solution.
   */
  virtual void handleClient(int client_socket) {
    const char *solution;
    string s = "";
    //just read into a buffer of string problem
    string problem = initProblem(client_socket);
    //checks if the problem is already solved
    if (cache_manager->isSolved(problem)) {
      s = cache_manager->getSolution(problem);
      solution = s.c_str();
    } else {
      s = solver->solve(problem);
      solution = s.c_str();
      cache_manager->saveSolution(solution, problem);
    }

    string so = solution;
    string file_name = "AStar.txt";
    ofstream file;
    file.open(file_name, ios::out | ios::binary | ios::app);
    unsigned int size = so.size();
    file.write(so.c_str(), size);
    file.write("\n", 1);
    file.close();
    int is_sent = send(client_socket, solution, strlen(solution), 0);
    solution = "";
    if (is_sent == -1) {
      cout << "Error sending message" << endl;
      exit(1);
    }
    problem = "";
  }
  /**
   * The function initializes the problem.
   */
  string initProblem(int client_socket_in) {
    string problem = "";
    char buffer[LINE_SIZE] = {0};
     buffer[LINE_SIZE] = {0};
    while (true) {
       buffer[LINE_SIZE] = {0};
      int valread = read(client_socket_in, buffer, LINE_SIZE);
      int i = 0;
      while (i < valread) {
        if (buffer[i] == END_OF_MESSAGE) {
          return problem;
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
  /**
   * Destructor.
   */
  virtual ~MyClientHandler() = default;
};

#endif //EX4_MYCLIENTHANDLER_H
