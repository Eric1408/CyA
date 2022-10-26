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
#include <regex>

#include "analyzer.h"

int main(int argc, char* argv[]) {
  std::string name{argv[1]};
  std::ifstream code{name};
  std::string lines;
  std::string saved_code;
  std::regex expression("int\\s(\\w+)");
  std::smatch matches;
  
  while (getline(code, lines)) {
    saved_code += lines;
    for (auto match : matches) {
      std::cout << match << " ";
    }
    std::cout << std::endl;
  }
  std::regex_search(saved_code, matches, expression);

  return 0;
}