/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file lenguajesP02.cc
 * @author Eric Angueta Rogel || alu0101335339@ull.edu.es
 * @brief lenguajesP02.cc: programa cliente.
 *        Contiene la funcion main del proyecto que usa las clases cadena.h alfabeto.h y simbolo.h
 *        para hacer operaciones con los lenguajes dados a partir de dos ficheros.
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

#include "lenguaje.h"
#include "cadena.h"
#include "usage.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream filein_1{argv[1]};
  std::ifstream filein_2{argv[2]};
  std::ofstream fileout{argv[3]};
  int opcode = atoi(argv[4]);
  std::string cadena{argv[5]};

  std::string line;
  std::string line_2;
  
  while (getline(filein_1, line) && getline(filein_2, line_2)) {
    Lenguaje lenguaje_1(line);
    Lenguaje lenguaje_2(line_2);
    Selector(fileout, lenguaje_1, lenguaje_2, opcode, cadena);
  }

  return 0;
}

