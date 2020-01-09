//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "State.h"
#include "Point.h"
#include "State.h"
#include "Searchable.h"
#include "SearchSolver.h"
#include "FileCacheManager.h"
class MyClientHandler : public ClientHandler {
 private:
  FileCacheManager cache_manager;
  Searchable<Point> *matrix;
  vector<State<Point> *> structure;
  string problem = "";
  SearchSolver<Searchable<Point>, string> *search_solver;
 public:
  virtual void handleClient(istream input_stream, ostream output_stream) = 0;
  virtual ~MyClientHandler() = default;
  void addToStructure(string line, int num_of_line);
  State<Point> *createState(int value, int location, int num_of_line);
  void insertStateToStructure(State<Point> *p_state);
  double getCost(int row, int col);
  void createMatrix(int row_in, int col_in, int row_out, int col_out);
  void initProblem(istream &input_stream);
};

#endif //EX4_MYCLIENTHANDLER_H
