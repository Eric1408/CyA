/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file analyzer_main.cc
 * @brief Programa principal donde hace la llamada al analizador de codigo
 * @author Eric Angueta Rogel || alu0101335339@ull.edu.es
 * @version 0.1
 * @date 2022-10-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <fstream>
#include <string>

#include "analyzer.h"
#include "usage.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
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
    if (analy.ForIni(lines)) {
      analy.DeleteFor(lines);
    
    } else if (!analy.FinFor()) {
      analy.DeleteFor(lines);
      analy.ForFin(lines);
    }
  }

  std::string aux;
  std::ofstream salida{name + ".tmp"};
  for (size_t i = 0; i < analy.CodeSize(); ++i) {
    aux = analy.GetCode(i);
    salida << aux;
  }

  fileout << analy;

  return 0;
}