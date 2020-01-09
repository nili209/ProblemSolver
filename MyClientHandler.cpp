//
// Created by nili and shiraz on 1/8/20.
//

#include "MyClientHandler.h"
#include "Matrix.h"

void MyClientHandler::handleClient(istream input_stream, ostream output_stream) {
  const char *solution;
  initProblem(input_stream);
  if (cache_manager.isSolved(problem)) {
    solution = cache_manager.getSolution(problem).c_str();
  } else {
    solution = search_solver->solve(matrix).c_str();
    cache_manager.saveSolution(solution, problem);
  }
  //does the length of solution is sizeof(solution)
  output_stream.write(solution, sizeof(solution));
}
void MyClientHandler::initProblem(istream &input_stream) {
  string line = "", row_in = "", row_out = "", col_in = "", col_out = "";
  char current_char;
  int counter_of_lines = 0, counter_of_last_values = 0;
  input_stream.get(current_char);
  while (current_char != 'e') {
    while (current_char != '\n') {
      line += current_char;
      input_stream.get(current_char);
    }
    addToStructure(line, counter_of_lines);
    counter_of_lines++;
    line = "";
    problem += line;
    problem += ';';
  }
  //reading the word end
  while (current_char != '\n') {
    input_stream.get(current_char);
  }
  while (counter_of_last_values <= 3) {
    input_stream.get(current_char);
    problem += current_char;
    while (current_char != ',' || current_char != '\n') {
      switch (counter_of_last_values) {
        case 0: {
          row_in += current_char;
          break;
        }
        case 1 : {
          col_in += current_char;
          break;
        }
        case 2: {
          row_out += current_char;
          break;
        }
        case 3: {
          col_out += current_char;
          break;
        }
        default: {
          break;
        }
      }
    }
    counter_of_last_values++;
    problem += ';';
  }
  createMatrix(stoi(row_in), stoi(col_in), stoi(row_out), stoi(col_out));
}
void MyClientHandler::createMatrix(int row_in, int col_in, int row_out, int col_out) {
  double initial_cost = getCost(row_in, col_in);
  double goal_cost = getCost(row_out, col_out);
  State<Point> *initial_state = createState(initial_cost, row_in, col_in);
  State<Point> *goal_state = createState(goal_cost, row_out, col_out);
  matrix = new Matrix(initial_state, goal_state, structure);
}
void MyClientHandler::addToStructure(string line, int num_of_line) {
  string data = "";
  int location = 0, value = 0;
  for (int i = 0; i < line.length(); i++) {
    while (line[i] != ',') {
      data += line[i];
    }
    value = stoi(data);
    State<Point> *state = createState(value, location, num_of_line);
    location++;
    insertStateToStructure(state);
  }
}
State<Point> *MyClientHandler::createState(int value, int row, int col) {
  Point *point = new Point(row, col);
  State<Point> *state = new State<Point>(*point, value);
  return state;
}
double MyClientHandler::getCost(int row, int col) {
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
void MyClientHandler::insertStateToStructure(State<Point> *p_state) {
  structure.push_back(p_state);
}

