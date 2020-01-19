#include "StringReverser.h"
#include "Searchable.h"
#include "CacheManager.h"
#include "SearchSolver.h"
#include "FileCacheManager.h"
#include "Server.h"
#include "MyClientHandler.h"
#include "MySerialServer.h"
#include "MyParallelServer.h"
#include "AStar.h"

using namespace std;

namespace boot {
class Main {
 public:
  int main(int port) {
    ///General initialization
    CacheManager<string, string> *my_cache = new FileCacheManager<string>(-1);
    server_side::Server *server = new MyParallelServer();
    ///AStar
    Searcher<Point, string> *searcher_AStar(new AStar<Point, string>);
    Solver<string, string> *matrix_solver_AStar = new SearchSolver<Point, string>(searcher_AStar);
    ClientHandler *c_AStar = new MyClientHandler<string, string>(matrix_solver_AStar, my_cache);
    server->open(port, c_AStar);
    return 0;
  }
};
}

int main(int argc, char *argv[]) {
  boot::Main main;
  main.main(atoi(argv[1]));
  return 0;
}
