#include <iostream>
#include <string>
#include <fstream>

#include "gramatica.h"

int main(int argc, char* argv[]) {
  std::ifstream input{argv[1]};
  
  Gramatica grammar(input);

  return 0;
}