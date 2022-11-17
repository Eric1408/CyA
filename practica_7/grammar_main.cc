/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file grammar_main.cc
 * @brief Fichero main que contiene las clase automata para generar uno 
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
#include "gramar.h"
#include "automata.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream file_in{argv[1]};
  std::ofstream output{argv[2]};
  std::string lines;

  Automata autom(file_in);
  Grammar gramatica(autom);
  std::cout << gramatica;

  return 0;
}
