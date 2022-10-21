/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file simbolo.h
 * @author Eric Angueta Rogel || alu0101335339@ull.edu.es
 * @version 0.1
 * @date 2022-09-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <iostream>
#include <string>

class Simbolo {
 public:
  Simbolo(void) : symbol_{} {}
  Simbolo(char input) {symbol_ = input;}

  inline char GetSymbol(void) const {return symbol_;}
  inline void SetSym(char input) {symbol_ = input;}
  
  friend bool operator<(const Simbolo&, const Simbolo&);
  friend std::ostream& operator<<(std::ostream&, const Simbolo&);

 private:
  char symbol_;
};

