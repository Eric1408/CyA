/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Informatica Basica
 *
 * @author Eric Angueta
 * @date 23. oct .2022
 * @brief Ejercicios Informatica Basica
 * Version 1: Funcion factorial
 *
 * @see 
 */

#include <iostream>
#include <fstream>
#include <string>

#include "analyzer.h"

int main(int argc, char* argv[]) {
  int position = 0;
  std::string name{argv[1]};
  std::string out_name{argv[2]};
  std::ifstream code{name};
  std::ofstream fileout{out_name};

  std::string lines;

  Analyzer analy;
  fileout << "PROGRAM : " << name << std::endl;
  while (getline(code, lines)) {
    position++;
    analy.Build(lines, position);
  }
  fileout << analy;

  return 0;
}