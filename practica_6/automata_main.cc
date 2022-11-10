#include <iostream>
#include <string>
#include <fstream>

#include "usage.h"
#include "automata.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream file_in{argv[1]};
  std::ifstream file_strings{argv[2]};

  Automata autom(file_in);
  //for (int i = 0; i < autom.GetTotalStates(); ++i) {
  //  std::cout << "Desde " << i << " transiciona ";
  //  std::cout << autom.GetEstados(i);
  //}
  
  return 0;
}
