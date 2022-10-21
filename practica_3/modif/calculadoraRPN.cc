/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file calculadoraRPN.cc
 * @author Eric Angueta Rogel || alu0101335339@ull.edu.es
 * @brief calculadoraRPN.cc: programa cliente.
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
#include <map>

#include "notacion_polaca.h"
#include "lenguaje.h"
#include "cadena.h"
#include "usage.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  std::ifstream filein_1{argv[1]};
  std::map<std::string, Lenguaje> map_lenguaje;

  std::string line;
  std::string name;

  while (getline(filein_1, line)) {
    size_t found = line.find("=");
    if (found != std::string::npos) {
      Lenguaje lenguaje(line);
      
      for (size_t i = 0; i < line.size(); ++i) {
        if (line[i] != SPACE) {
          name += line[i];
        } else {
          map_lenguaje[name] = lenguaje;
          name.clear();
          break;
        }
      }
    } else {
      CalculatorRPN(line, map_lenguaje);
    }
  }
  Continue(map_lenguaje);
  
  return 0;
}

