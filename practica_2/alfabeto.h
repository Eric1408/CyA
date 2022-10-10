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
#include <vector>
#include <set>

#include "simbolo.h"

const char SPACE = ' ';

class Alfabeto {
 public:
  Alfabeto(void) : symbol_{} {}
  Alfabeto(std::string);


  void Sort(void);
  void GetAlpha(void);
  void Build(std::string);
  inline int Size(void) {return symbol_.size();}
  //inline Simbolo at(int pos) {return symbol_[pos];}

 private:
  //std::vector<Simbolo> symbol_;
  std::set<Simbolo> symbol_;
};
