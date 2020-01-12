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
#define END "end"
template<typename Problem, typename Solution>
class MyClientHandler : public ClientHandler {
 private:
  CacheManager<Problem, Solution> *cache_manager;
  string problem = "";
  //can be searchsolver?
  Solver<Problem, Solution> *solver;
 public:
  MyClientHandler(Solver<Problem, const char *> *solver1, CacheManager<Problem, Solution> *cache_menager1) :
  solver(solver1), cache_manager(cache_menager1) {}
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
//  State<Point> *createState(int value) {
//    Point *point = new Point(number_of_rows, number_of_cols);
//    State<Point> *state = new State<Point>(*point, value);
//    return state;
//  }
  void insertStateToStructure(State<Point> *p_state);
  double getCost(int row, int col);
  void createMatrix(int row_in, int col_in, int row_out, int col_out);
//  void separateByComma(char *problem) {
//    string data = "";
//    int value = 0;
//    int length = sizeof(problem);
//    for (int i = 0; i < length; i++) {
//      while (problem[i] != ',' && problem[i] != '\n') {
//        data += problem[i];
//      }
//      value = stoi(data);
//      State<Point> *state = createState(value);
//      number_of_cols++;
//      insertStateToStructure(state);
//    }
//  }
  void initProblem(int client_socket_in) {
    char buffer[LINE_SIZE] = {0};
    int valread = read(client_socket_in, buffer, LINE_SIZE);
    while (strcmp(buffer, END) != 0) {
      char *temp_problem = new char[valread];
      problem += temp_problem;
      problem += ';';
    }
  }
};

#endif //EX4_MYCLIENTHANDLER_H
