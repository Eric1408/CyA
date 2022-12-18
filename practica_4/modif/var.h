/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file var.h
 * @brief Fichero de cabecera que contiene a la clase que almacenas los tipos de datos
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

class Var {
 public:
  Var(std::smatch, int);

  friend std::ostream& operator<<(std::ostream&, const Var&);

 private:
  int positon_;
  std::string name_;
  std::string type_;
};