//
// Created by nili and shiraz on 1/8/20.
//

#ifndef EX4_SEARCHSOLVER_H
#define EX4_SEARCHSOLVER_H

#include "Solver.h"
#include "Searcher.h"

#define END_OF_LINE ';'

//T = Point
template<typename T, class Solution>
class SearchSolver : public Solver<string, Solution> {
private:
    int number_of_rows = 0;
    int number_of_cols = 0;
    Searchable<T> *matrix;
    vector<State<T> *> structure;
    Searcher<T, Solution> *my_searcher;
public:
    SearchSolver(Searcher<T, Solution> *searcher) : my_searcher(searcher) {}

    /**
     * Given a problem, the function creates a Searchable of type matrix.
     */
    void initMatrix(string problem) {
        int i = 0;
        char current_char = problem[i];
        string data = "";
        int number_of_lines = initNumberOfLines(problem);
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

    void readLastValues(string problem, int i) {
        char current_char = problem[i];
        int counter_of_last_values = 0;
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

    void createMatrix(int row_in, int col_in, int row_out, int col_out) {
        double initial_cost = getCost(row_in, col_in);
        double goal_cost = getCost(row_out, col_out);
        State<Point> *initial_state = createState(initial_cost, false, row_in, col_in);
        State<Point> *goal_state = createState(goal_cost, false, row_out, col_out);
        matrix = new Matrix(initial_state, goal_state, structure);
    }

    State<Point> *createState(double value, bool to_push, int row, int col) {
        Point *point = new Point(row, col);
        State<Point> *state = new State<Point>(*point, value);
        if (to_push) {
            structure.push_back(state);
        }
        return state;
    }

    int initNumberOfLines(string problem) {
        int i, length = problem.length(), number_of_lines = 0;
        for (i = 0; i < length; i++) {
            if (problem[i] == END_OF_LINE) {
                number_of_lines++;
            }
        }
        return number_of_lines;
    }

    virtual Solution solve(string problem) {
        initMatrix(problem);
        return my_searcher->search(matrix);
    }

/**
* Destructor.
*/
    virtual ~
    SearchSolver() {
        delete my_searcher;
    }

};

#endif //EX4_SEARCHSOLVER_H
