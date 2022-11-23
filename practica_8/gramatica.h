#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

#include"simbolo.h"
#include "alfabeto.h"
//#include "producciones.h"

typedef std::vector<std::string> vec_string; 
typedef std::vector<Simbolo> vec_simbolo;
//typedef std::vector<Produccion> vec_produccion;

class Gramatica {
 public:
  //Gramatica(void) alpha_{}, no_terminal_{}, start_{}, estrduct_{}, casi_{} {}
  Gramatica(std::istream&);

 private:
  Alfabeto terminal_;
  Alfabeto no_terminal_;
  Simbolo start_;
  std::map<Simbolo, vec_string> producciones_;
  std::map<Simbolo, vec_simbolo> casi_;

};