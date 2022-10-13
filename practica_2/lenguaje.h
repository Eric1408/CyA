#pragma once

#include <string>
#include <iterator>
#include <vector>

#include "cadena.h"
#include "alfabeto.h"

const char SPACE = ' ';

class Lenguaje{
 public:
  Lenguaje(void) : alpha_{}, cadenas_{} {}
  Lenguaje(std::string);
  //~Lenguaje();

  void SetLenguage(void);
  void ReverseLenguage(void);
  std::string GetCadenas(void) const;
  Lenguaje PowLenguage(const Lenguaje&, int);

  friend Lenguaje operator*(const Lenguaje&, const Lenguaje&);
  friend Lenguaje operator+(const Lenguaje&, const Lenguaje&);
  friend Lenguaje operator/(const Lenguaje&, const Lenguaje&);
  friend Lenguaje operator-(const Lenguaje&, const Lenguaje&);
  friend std::ostream& operator<<(std::ostream&, const Lenguaje&);

 private:
  Alfabeto alpha_;
  std::set<Cadena> cadenas_;
};