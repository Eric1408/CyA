/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file loop.h
 * @brief Fichero de cabecera que contiene la clase que almacena los bucles
 * @author Eric Angueta Rogel || alu0101335339@ull.edu.es
 * @version 0.1
 * @date 2022-10-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <iostream>
#include <regex>
#include <string>

class Loop {
 public:
  Loop(std::smatch, int);
  
  friend std::ostream& operator<<(std::ostream&, const Loop&);
 private:
  int position_;
  std::string type_;
};