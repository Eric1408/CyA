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
 * @date 2022-12-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>

#include "voraces.h"
#include "usage.h"

int main (int argc, char* argv[]) {
  Usage(argc, argv);
  double cantidad;
  std::vector<int> coins{200, 100, 50, 20, 10, 5, 2, 1};
  std::vector<int> bills{50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
  Voraces cambio_c(coins);  
  Voraces cambio_b(bills);

  if (std::string(argv[1]) == "-b") {
    if (std::string(argv[2]) == "-o") {
      cantidad = atof(argv[3]);
      cambio_b.Write(cambio_b.Devolver(cantidad), true);
    } else {
      cantidad = atof(argv[2]);
      cambio_b.Write(cambio_b.DevolverBasic(cantidad), true);
    }

  } else if (std::string(argv[1]) == "-o") {
    if (std::string(argv[2]) == "-b") {
      cantidad = atof(argv[3]);
      cambio_b.Write(cambio_b.Devolver(cantidad), true);
    } else {
      cantidad = atof(argv[2]);
      cambio_c.Write(cambio_c.Devolver(cantidad), false);
    }
  } else {
    cantidad = atof(argv[1]);
    cambio_c.Write(cambio_c.DevolverBasic(cantidad), false);
  }

  return 0;
}