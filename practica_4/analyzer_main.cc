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

int main(int argc, char* argv[]) {
  std::string name{argv[1]};
  std::string out{argv[2]};

  std::ifstream code{name};
  std::ofstream output{out};
  std::string aux;

  while (getline(code, aux)) {
    std::cout << aux << std::endl;
  }

  return 0;
}