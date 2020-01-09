#include <iostream>
#include "StringReverser.h"
#include "Searchable.h"
#include "BestFirstSearch.h"
#include "Matrix.h"
#include "CacheManager.h"
#include "SearchSolver.h"
#include "FileCacheManager.h"
namespace boot {
    class Main {
    public:
        int main(int argc, char* argv[]);
    };
}
using namespace std;
Searchable<Point>* buildSearchable() {

}
void tester(Searcher<string, Point>* searcher) {
  Searchable<Point>* matrix = buildSearchable();
}
int main(int argc, char* argv[]) {
  Searcher<string, Point>* searcher(new BestFirstSearch<Point>);
  Point * initial_point = new Point(0,0);
  Point * p01 = new Point(0,1);
  Point * p10 = new Point(1,0);
  Point * p11 = new Point(1,1);
  Point * p20 = new Point(2,0);
  Point * goal_point = new Point(2,1);
  vector<State<Point>*> structure;
  State<Point>* initial_state1 = new State<Point>(*initial_point, 1);
  State<Point>* state2 = new State<Point>(*p01, 4);
  State<Point>* state3 = new State<Point>(*p10, 7);
  State<Point>* state4 = new State<Point>(*p11, 1);
  State<Point>* state5 = new State<Point>(*p20, 0);
  State<Point>* goal_state4 = new State<Point>(*goal_point, 10);
  structure.push_back(initial_state1);
  structure.push_back(state2);
  structure.push_back(state3);
  structure.push_back(state4);
  structure.push_back(state5);
  structure.push_back(goal_state4);
  Searchable<Point>* matrix = new Matrix(initial_state1, goal_state4, structure);
  string s = searcher->search(matrix);
  std::cout<<"test1: "<<s<<endl<<"number of nodes = " << searcher->getNumberOfNodesEvaluated()<<endl;
  //test2
  Searcher<string, Point>* searcher2(new BestFirstSearch<Point>);
  initial_point = new Point(0,0);
  p01 = new Point(0,1);
  p10 = new Point(1,0);
  goal_point = new Point(1,1);
  vector<State<Point>*> structure2;
  State<Point>* arr[6];
  //arr[0] =
  initial_state1 = new State<Point>(*initial_point, 1);
  state2 = new State<Point>(*p01, 2);
  state3 = new State<Point>(*p10, 3);
  goal_state4 = new State<Point>(*goal_point, 4);
  structure2.push_back(initial_state1);
  structure2.push_back(state2);
  structure2.push_back(state3);
  structure2.push_back(goal_state4);
  Searchable<Point>* matrix2  = new Matrix(initial_state1, goal_state4, structure2);
  string s1 = searcher2->search(matrix2);
  std::cout<<"test2: "<< s1<<endl<<"number of nodes = " << searcher2->getNumberOfNodesEvaluated()<<endl;
  //test3
  Searcher<string, Point>* searcher3(new BestFirstSearch<Point>);
  initial_point = new Point(0,0);
  p01 = new Point(0,1);
  Point* p02 = new Point(0,2);
  p10 = new Point(1,0);
  p20 = new Point(2,0);
  p11 = new Point(1,1);
  Point* p12 = new Point(1,2);
  Point* p21 = new Point(2,1);
  goal_point = new Point(2,2);
  vector<State<Point>*> structure3;
  initial_state1 = new State<Point>(*initial_point, 1);
  state2 = new State<Point>(*p01, 8);
  state3 = new State<Point>(*p10, 9);
  state4 = new State<Point>(*p11, 1000);
  state5 = new State<Point>(*p02, 10);
  State<Point>* state6 = new State<Point>(*p20, 10);
  State<Point>* state7 = new State<Point>(*p21, 0);
  State<Point>* state8 = new State<Point>(*p12, 8);
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
  Searchable<Point>* matrix3  = new Matrix(initial_state1, goal_state4, structure3);
  string s2 = searcher3->search(matrix3);
  std::cout<<"test3: "<< s2<<endl<<"number of nodes = " << searcher3->getNumberOfNodesEvaluated()<<endl;
  string problem1 = "1,2;3,4;0;0;1;1";
  string problem2 = "1,4;7,1;0,10;0;0;2;1";
  string problem3 = "1,8,10;9,1000,8;10,0,2;0;0;2;2";
  FileCacheManager my_cache;
  cout<<my_cache.isSolved(problem1)<<endl;
  my_cache.saveSolution(s1,problem1);
  cout<<my_cache.isSolved(problem1)<<endl;
  cout<<my_cache.getSolution(problem1)<<endl;
  /****
   *
   */
  cout<<my_cache.isSolved(problem2)<<endl;
  my_cache.saveSolution(s,problem2);
  cout<<my_cache.isSolved(problem2)<<endl;
  cout<<my_cache.getSolution(problem2)<<endl;
  cout<<my_cache.isSolved(problem2)<<endl;
  /****
   *
   */
  cout<<my_cache.isSolved(problem3)<<endl;
  my_cache.saveSolution(s2,problem3);
  cout<<my_cache.isSolved(problem3)<<endl;
  cout<<my_cache.getSolution(problem3)<<endl;
  return 0;
}