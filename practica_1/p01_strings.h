#pragma once

#include <iostream>
#include <string>

const char SPACE = ' ';

class Alfabeto {
 public:
  Alfabeto(void) : simbolo_(NULL) {}
  Alfabeto(std::string); 
 private:
  std::string* simbolo_;
};

class Cadena {
 public:
  Cadena(void) : alfa_(), longitud_{0} {}
  Cadena(std::string);
 private:
  Alfabeto alfa_;
  int longitud_;
  std::string cadena_;
};

Cadena::Cadena(std::string input) {
  //cadena_ = input.pop(); //siendo pop la ultima posicon del vector string y eliminado este mismo
  //if (input.size() == 0) 
    //alfa_(cadena_);
  //alfa_(input);
}
