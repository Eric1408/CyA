#pragma once

#include <iostream>

#include "simbolo.h"

class Transicion {
 public:
  Transicion(std::string);

  // Getters
  inline Simbolo GetSymbol(void) const { return symbol_; }
  inline int GetNext(void) const { return next_; }
  
 private:
  Simbolo symbol_;
  int next_;
  //std::map<Simbolo, int> next_;
};
