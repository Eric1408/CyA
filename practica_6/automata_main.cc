/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file automata_main.cc
 * @brief Fcihero que main que contiene las clase automata para generar uno 
 * @author Eric Angueta Rogel || alu0101335339@ull.edu.es
 * @version 0.1
 * @date 2022-09-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <fstream>

#include "usage.h"
#include "automata.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream file_in{argv[1]};
  std::ifstream file_strings{argv[2]};
  std::string lines;

  Automata autom(file_in);
  while (getline(file_strings, lines)) {
    if (autom.CheckString(lines)) {
      std::cout << lines << " --- Accepted\n";
    } else {
      std::cout << lines << " --- Rejected\n";
    }
  }
  return 0;
}
