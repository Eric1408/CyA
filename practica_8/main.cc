/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file main.h
 * @brief Fichero principal que contiene la gramatica
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

#include "gramatica.h"
#include "usage.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream input{argv[1]};
  std::ofstream output{argv[2]};

  Gramatica grammar(input);
  grammar.ToChomsky();
  output << grammar;

  return 0;
}