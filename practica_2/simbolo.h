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
  Simbolo(void) : symbol_("") {}
  Simbolo(std::string input) {symbol_ = input;}

  inline std::string GetSymbol(void) {return symbol_;}
  inline int SymSize(void) {return symbol_.size();}
  inline void SetSym(std::string input) {symbol_ = input;}
  
  friend bool operator<(const Simbolo&, const Simbolo&);
  friend std::ostream& operator<<(std::ostream&, const Simbolo&);

  //void Write(std::ostream&) const;

 private:
  std::string symbol_;
};

