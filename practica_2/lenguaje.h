#pragma once
#include "cadena.h"
#include "alfabeto.h"

class Lenguaje{
 public:
  Lenguaje(std::string);

 private:
  Alfabeto alpha_;
  std::set<Cadena> cadenas_;
};