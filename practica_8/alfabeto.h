/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file alfabeto.h
 * @author Eric Angueta Rogel || alu0101335339@ull.edu.es
 * @version 0.1
 * @date 2022-09-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <set>

#include "simbolo.h"

const char EMPTYCHAIN = '&';

class Alfabeto {
 public:
  Alfabeto(void) : alpha_symbol_{} {}
  Alfabeto(std::string);

  void Insert(char);
  inline int Size(void) {return alpha_symbol_.size();}
  inline std::set<Simbolo> GetSetAlpha(void) const {return alpha_symbol_;}
  std::string GetAlpha(void) const;

  friend std::ostream& operator<<(std::ostream&, const Alfabeto&);

 private:
  std::set<Simbolo> alpha_symbol_;
};
