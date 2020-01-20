//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_SEARCHSOLVER_H
#define EX4_SEARCHSOLVER_H
#include "Solver.h"
#include "Searcher.h"
#include "Matrix.h"
#define END_OF_LINE ';'

template<typename T, class Solution>
class SearchSolver : public Solver<string, Solution> {
 private:
  Searchable<T> *matrix;
  vector<State<T> *> structure;
  Searcher<T, Solution> *my_searcher;
 public:
  /**
   * Constructor.
   */
  SearchSolver(Searcher<T, Solution> *searcher) : my_searcher(searcher) {}
  /**
   * Given a problem, the function creates a Searchable of type matrix.
   */
  void initMatrix(string problem) {
    int i = 0;
    int number_of_rows = 0;
    int number_of_cols = 0;
    Searchable<T> *m = nullptr;
    matrix = m;
    vector<State<T> *> v;
    structure = v;
    char current_char = problem[i];
    string data = "";
    int number_of_lines = initNumberOfLines(problem);
    //read from buffer until we get to the two last rows that contains the start and end point.
    while (number_of_rows < number_of_lines - 2) {
      while (current_char != END_OF_LINE) {
        if (current_char == ',') {
          createState(stoi(data), true, number_of_rows, number_of_cols);
          data = "";
          number_of_cols++;
          current_char = problem[++i];
          continue;
        }
        data += current_char;
        current_char = problem[++i];
      }
      createState(stoi(data), true, number_of_rows, number_of_cols);
      data = "";
      current_char = problem[++i];
      number_of_rows++;
      number_of_cols = 0;
    }
    readLastValues(problem, i);
  }
  /**
   * Given a problem and an index, the function sets the start point and end point.
   */
  void readLastValues(string problem, int i) {
    char current_char = problem[i];
    string row_in = "", col_in = "", row_out = "", col_out = "";
    while (current_char != ',') {
      row_in += current_char;
      current_char = problem[++i];
    }
    current_char = problem[++i];
    while (current_char != ';') {
      col_in += current_char;
      current_char = problem[++i];
    }
    current_char = problem[++i];
    while (current_char != ',') {
      row_out += current_char;
      current_char = problem[++i];
    }
    current_char = problem[++i];
    while (current_char != ';') {
      col_out += current_char;
      current_char = problem[++i];
    }
    createMatrix(stoi(row_in), stoi(col_in), stoi(row_out), stoi(col_out));
  }
  /**
   * Given a point, the function returns its cost.
   */
  double getCost(int row, int col) {
    int x, y;
    for (State<Point> *state : structure) {
      x = state->getState().getX();
      y = state->getState().getY();
      if (x == row && y == col) {
        return state->getCost();
      }
    }
    return 0;
  }
  /**
   * Given values of start point and end point, the function creates a matrix.
   */
  void createMatrix(int row_in, int col_in, int row_out, int col_out) {
    double initial_cost = getCost(row_in, col_in);
    double goal_cost = getCost(row_out, col_out);
    State<Point> *initial_state = createState(initial_cost, false, row_in, col_in);
    State<Point> *goal_state = createState(goal_cost, false, row_out, col_out);
    matrix = new Matrix(initial_state, goal_state, structure);
  }
  /**
   * The function creates a new state and add it to structure if neccesary.
   */
  State<Point> *createState(double value, bool to_push, int row, int col) {
    Point *point = new Point(row, col);
    State<Point> *state = new State<Point>(*point, value);
    if (to_push) {
      structure.push_back(state);
    }
    return state;
  }
  /**
   * Given a problem function counts the number of lines the problem has and returns it.
   */
  int initNumberOfLines(string problem) {
    int i, length = problem.length(), number_of_lines = 0;
    for (i = 0; i < length; i++) {
      if (problem[i] == END_OF_LINE) {
        number_of_lines++;
      }
    }
    return number_of_lines;
  }
  /**
   * Given a problem the function returns it's solution.
   */
  virtual Solution solve(string problem) {
    initMatrix(problem);
    return my_searcher->search(matrix);
  }
/**
* Destructor.
*/
  virtual ~SearchSolver() {
    delete my_searcher;
  }
};

#endif //EX4_SEARCHSOLVER_H
