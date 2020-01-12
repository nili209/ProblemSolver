//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H

#include <sys/socket.h>
#include "ClientHandler.h"
#include "State.h"
#include "Point.h"
#include "State.h"
#include "Searchable.h"
#include "SearchSolver.h"
#include "FileCacheManager.h"
template <typename Problem, typename Solution>
class MyClientHandler : public ClientHandler {
 private:
  CacheManager<Problem, Solution>* cache_manager;
  string problem = "";
  //can be searchsolver?
  Solver<Problem, Solution> *solver;
 public:
  MyClientHandler(Solver<Problem, const char*> *solver1, CacheManager<Solution, Problem>* cache_menager1) : solver(solver1),
  cache_manager(cache_menager1){}
  virtual void handleClient(int client_socket_in, int client_socket_out) {
    const char *solution;
    //just read into a buffer of string problem
    initProblem(client_socket_in);
    if (cache_manager->isSolved(problem)) {
      solution = cache_manager->getSolution(problem);
    } else {
      solution = solver->solve(problem);
      cache_manager->saveSolution(solution, problem);
    }
    //does the length of solution is sizeof(solution)?
    //client_socket_out.write(solution, sizeof(solution));
    int is_sent = send(client_socket_out, solution, sizeof(solution), 0);
    if (is_sent == -1) {
      cout << "Error sending message" << endl;
      exit(1);
    }
  }
  virtual ~MyClientHandler() = default;
  void addToStructure(string line, int num_of_line);
  State<Point> *createState(int value, int location, int num_of_line);
  void insertStateToStructure(State<Point> *p_state);
  double getCost(int row, int col);
  void createMatrix(int row_in, int col_in, int row_out, int col_out);
  void initProblem(istream &input_stream);
};

#endif //EX4_MYCLIENTHANDLER_H
