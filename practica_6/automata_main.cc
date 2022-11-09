#include <iostream>
#include <string>
#include <fstream>

#include "usage.h"
#include "automata.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::string fileN{argv[1]};  
  std::ifstream file_in{fileN};

  
  return 0;
}
