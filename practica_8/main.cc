#include <iostream>
#include <string>
#include <fstream>

#include "gramatica.h"
#include "usage.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream input{argv[1]};
  std::ofstream output{argv[2]};

  Gramatica grammar(input);
  grammar.ToChomsky();
  output << grammar;

  return 0;
}