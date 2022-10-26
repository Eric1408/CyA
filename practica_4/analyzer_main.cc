#include <iostream>
#include <fstream>
#include <string>
#include <regex>

#include "analyzer.h"
#include "var.h"

int main(int argc, char* argv[]) {
  int position;
  std::string name{argv[1]};
  std::ifstream code{name};
  std::string lines;

  while (getline(code, lines)) {
    position++;
    Var variable(lines, position);
    std::cout << variable << std::endl;
  }
  

  return 0;
}