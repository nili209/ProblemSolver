#include <iostream>
#include "StringReverser.h"
#include "Searchable.h"
#include "BestFirstSearch.h"
#include "Matrix.h"
namespace boot {
    class Main {
    public:
        int main(int argc, char* argv[]);
    };
}
using namespace std;
int main(int argc, char* argv[]) {
  Searcher<string, Point>* searcher(new BestFirstSearch<Point>);
  Point * initial_point = new Point(0,0);
  Point * p2 = new Point(0,1);
  Point * p3 = new Point(1,0);
  Point * goal_point = new Point(1,1);
  vector<State<Point>*> structure;
  State<Point>* initial_state1 = new State<Point>(*initial_point, 1);
  State<Point>* state2 = new State<Point>(*p2, 2);
  State<Point>* state3 = new State<Point>(*p3, 3);
  State<Point>* goal_state4 = new State<Point>(*goal_point, 4);
  structure.push_back(initial_state1);
  structure.push_back(state2);
  structure.push_back(state3);
  structure.push_back(goal_state4);
  Searchable<Point>* matrix = new Matrix(initial_state1, goal_state4, structure);
  string s = searcher->search(matrix);
  std::cout<<s<<endl;
  return 0;
}