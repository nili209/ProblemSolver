#include <iostream>
#include "StringReverser.h"
#include "Searchable.h"
#include "BestFirstSearch.h"
#include "Matrix.h"
#include "CacheManager.h"
#include "SearchSolver.h"
#include "FileCacheManager.h"
#include "Server.h"
#include "MyTestClientHandler.h"
#include "MyClientHandler.h"
#include "MySerialServer.h"
#include "BFS.h"
#include "DFS.h"
#include "AStar.h"

using namespace std;

namespace boot {
class Main {
 public:
  int main(int port) {
    Searcher<Point, string> *searcher(new BestFirstSearch<Point, string>);
    Point *initial_point = new Point(0, 0);
    Point *p01 = new Point(0, 1);
    Point *p10 = new Point(1, 0);
    Point *p11 = new Point(1, 1);
    Point *p20 = new Point(2, 0);
    Point *goal_point = new Point(2, 1);
    vector<State<Point> *> structure;
    State<Point> *initial_state1 = new State<Point>(*initial_point, 1);
    State<Point> *state2 = new State<Point>(*p01, 4);
    State<Point> *state3 = new State<Point>(*p10, 7);
    State<Point> *state4 = new State<Point>(*p11, 1);
    State<Point> *state5 = new State<Point>(*p20, 0);
    State<Point> *goal_state4 = new State<Point>(*goal_point, 10);
    structure.push_back(initial_state1);
    structure.push_back(state2);
    structure.push_back(state3);
    structure.push_back(state4);
    structure.push_back(state5);
    structure.push_back(goal_state4);
    Searchable<Point> *matrix = new Matrix(initial_state1, goal_state4, structure);
    string s = searcher->search(matrix);
    std::cout << "test1: " << s << endl << "number of nodes = " << searcher->getNumberOfNodesEvaluated()
              << endl;
    //test2
    Searcher<Point, string> *searcher2(new BestFirstSearch<Point, string>);
    initial_point = new Point(0, 0);
    p01 = new Point(0, 1);
    p10 = new Point(1, 0);
    goal_point = new Point(1, 1);
    vector<State<Point> *> structure2;
    initial_state1 = new State<Point>(*initial_point, 1);
    state2 = new State<Point>(*p01, -1);
    state3 = new State<Point>(*p10, 3);
    goal_state4 = new State<Point>(*goal_point, 4);
    structure2.push_back(initial_state1);
    structure2.push_back(state2);
    structure2.push_back(state3);
    structure2.push_back(goal_state4);
    Searchable<Point> *matrix2 = new Matrix(initial_state1, goal_state4, structure2);
    string s1 = searcher2->search(matrix2);
    std::cout << "test2: " << s1 << endl << "number of nodes = " << searcher2->getNumberOfNodesEvaluated()
              << endl;
    //test3
    Searcher<Point, string> *searcher3(new BestFirstSearch<Point, string>);
    initial_point = new Point(0, 0);
    p01 = new Point(0, 1);
    Point *p02 = new Point(0, 2);
    p10 = new Point(1, 0);
    p20 = new Point(2, 0);
    p11 = new Point(1, 1);
    Point *p12 = new Point(1, 2);
    Point *p21 = new Point(2, 1);
    goal_point = new Point(2, 2);
    vector<State<Point> *> structure3;
    initial_state1 = new State<Point>(*initial_point, 1);
    state2 = new State<Point>(*p01, 8);
    state3 = new State<Point>(*p10, 9);
    state4 = new State<Point>(*p11, 1000);
    state5 = new State<Point>(*p02, 10);
    State<Point> *state6 = new State<Point>(*p20, 10);
    State<Point> *state7 = new State<Point>(*p21, 0);
    State<Point> *state8 = new State<Point>(*p12, 8);
    goal_state4 = new State<Point>(*goal_point, 2);
    structure3.push_back(initial_state1);
    structure3.push_back(state2);
    structure3.push_back(state3);
    structure3.push_back(state4);
    structure3.push_back(state5);
    structure3.push_back(state6);
    structure3.push_back(state7);
    structure3.push_back(state8);
    structure3.push_back(goal_state4);
    Searchable<Point> *matrix3 = new Matrix(initial_state1, goal_state4, structure3);
    string s2 = searcher3->search(matrix3);
    std::cout << "test3: " << s2 << endl << "number of nodes = " << searcher3->getNumberOfNodesEvaluated()
              << endl;
    string problem1 = "1,2;3,4;0,0;1,1;end";
    string problem2 = "1,4;7,1;0,10;0;0;2;1";
    string problem3 = "1,8,10;9,1000,8;10,0,2;0;0;2;2";
    CacheManager<string, string> *my_cache = new FileCacheManager<string>(0);
    cout << my_cache->isSolved(problem1) << endl;
    my_cache->saveSolution(s1, problem1);
    cout << my_cache->isSolved(problem1) << endl;
    cout << my_cache->getSolution(problem1) << endl;
    /****
     *
     */
    cout << my_cache->isSolved(problem2) << endl;
    my_cache->saveSolution(s, problem2);
    cout << my_cache->isSolved(problem2) << endl;
    cout << my_cache->getSolution(problem2) << endl;
    cout << my_cache->isSolved(problem2) << endl;
    /****
     *
     */
    cout << my_cache->isSolved(problem3) << endl;
    my_cache->saveSolution(s2, problem3);
    cout << my_cache->isSolved(problem3) << endl;
    cout << my_cache->getSolution(problem3) << endl;

    cout << my_cache->getSolution(problem1) << endl;
    string trying = "shiraz";
    string prob = "prob";
    my_cache->saveSolution(trying, prob);
    cout << my_cache->getSolution(problem3) << endl;
    cout << my_cache->getSolution(prob) << endl;
    ///General initialization
    CacheManager<string, string> *my_cache3 = new FileCacheManager<string>(-1);
    server_side::Server *server1 = new MySerialServer();
    ///string reverser
//
//    Solver<string, string> *string_reverser = new StringReverser();
//    ClientHandler *c_string_reverser = new MyTestClientHandler<string, string>(string_reverser, my_cache3);
//    server1->open(port, c_string_reverser);
//    ///BestFS
//    Searcher<Point, string> *searcher_BestFS(new BestFirstSearch<Point, string>);
//    Solver<string, string> *matrix_solver_BestFS = new SearchSolver<Point, string>(searcher_BestFS);
//    ClientHandler *c_BestFS = new MyClientHandler<string, string>(matrix_solver_BestFS, my_cache3);
//    server1->open(port, c_BestFS);
//    ///BFS
//    Searcher<Point, string> *searcher_BFS(new BFS<Point, string>);
//    Solver<string, string> *matrix_solver_BFS = new SearchSolver<Point, string>(searcher_BFS);
//    ClientHandler *c_BFS = new MyClientHandler<string, string>(matrix_solver_BFS, my_cache3);
//    server1->open(port, c_BFS);
//    ///DFS
//    Searcher<Point, string> *searcher_DFS(new DFS<Point, string>);
//    Solver<string, string> *matrix_solver_DFS = new SearchSolver<Point, string>(searcher_DFS);
//    ClientHandler *c_DFS = new MyClientHandler<string, string>(matrix_solver_DFS, my_cache3);
//    server1->open(port, c_DFS);
    ///AStar
    Searcher<Point, string> *searcher_AStar(new AStar<Point, string>);
    Solver<string, string> *matrix_solver_AStar = new SearchSolver<Point, string>(searcher_AStar);
    ClientHandler *c_AStar = new MyClientHandler<string, string>(matrix_solver_AStar, my_cache3);
    server1->open(port, c_AStar);
  }
};
}

int main(int argc, char *argv[]) {
  boot::Main main;
  cout << atoi(argv[1]) << endl;
  main.main(atoi(argv[1]));
  return 0;
}
