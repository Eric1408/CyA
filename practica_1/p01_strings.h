#pragma once

#include <iostream>
#include <string>

const char SPACE = ' ';

class Simbolo {
 public:
  Simbolo(void) : simbolo_("") {}
 private:
  std::string simbolo_;
};
class Alfabeto {
 public:
  Alfabeto(void) : simbolo_() {}
  
  std::string Prefijos(void);
  std::string Sufijos(void);
  std::string Subcadena(void);

 private:
  std::vector<Simbolo> simbolo_;
};

class Cadena {
 public:
  Cadena(void) : longitud_{0} {}
  Cadena(std::string);
  void build(std::string);

  int Longitud(void) {return longitud_;}
  std::string Inversa(void);
  
 private:
  int longitud_;
  std::string cadena_;

};

Cadena::Cadena(std::string input) {
  
  for (size_t i = input.size() - 1; i >= 0; --i) {
    if (input[i] != SPACE) {
      longitud_++; 
    }
  }
  int cadpos = input.size() - longitud_ - 1;
  for (size_t i = cadpos; i < input.size(); ++i) {
    cadena_ += input[i];
  }

  input.erase(cadpos, input.size()-1);

}
