#include <iostream>
#include "StringReverser.h"
#include "Searchable.h"
#include "BestFirstSearch.h"
namespace boot {
    class Main {
    public:
        int main(int argc, char* argv[]);
    };
}
int main(int argc, char* argv[]) {
  Searcher<string, string>* searcher(new BestFirstSearch<string>);
  Searchable<string>* searchable;
  searcher->search(searchable);
  return 0;
}