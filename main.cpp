#include <iostream>
#include "StringReverser.h"
namespace boot {
    class Main {
    public:
        int main(int argc, char* argv[]);
    };
}
int main(int argc, char* argv[]) {
  std::cout << "Hello Nili" << std::endl;
  StringReverser* stringReverser = new StringReverser();
  cout<<stringReverser->solve("shiraz")<<endl;
  return 0;
}