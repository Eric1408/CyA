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
 *        Contiene la funcion main del proyecto que usa las clases cadena.h alfabeto.h y simbolo.h
 *        para hacer operaciones con las cadenas dadas a partir de un fichero.
 * @version 0.1
 * @date 2022-09-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "cadena.h"
#include "usage.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream filein{argv[1]};
  std::ofstream fileout{argv[2]};
  int opcode = atoi(argv[3]);

  std::string line;
  std::vector<Cadena> cadenas;
  
  while (getline(filein, line)) {
    cadenas.push_back(line);
  }

  Selector(fileout, cadenas, opcode);
}

