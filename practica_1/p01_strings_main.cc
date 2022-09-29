/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file p01_strings_main.cc
 * @author Eric Angueta Rogel || alu0101335339@ull.edu.es
 * @brief p01_strings_main.cc: programa cliente.
 *        Contiene la funcion main del proyecto que usa las clases p01_strings.cc y p01_strings.h
 *        para hacer operaciones con las cadenas dadas a partir de un fichero.
 * @version 0.1
 * @date 2022-09-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <fstream>

#include "p01_strings.h"

int main(int argc, char* argv[]) {
  std::ifstream filein{argv[1]};
  std::ofstream fileout{argv[2]};
  int opcode = atoi(argv[3]);
  std::string line;
  
  while (getline(filein, line)) {
    Cadena(line);
  }

  switch (opcode) {
  case 1:
    /* code */
    break;
  case 2:

    break;
  case 3:

    break;
  case 4:

    break;
  case 5:
  
    break;
  default:
    break;
  }
  
  return 0;
}