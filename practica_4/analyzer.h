#pragma once

#include <iostream>
#include <regex>
#include <string>

class Analyzer{
 public:
  void Var(void); // variables de tipo int y double
  void Loop(void); //deteccion de bucles for y while, numero de bucles de cada tipo, y en la linea encontrada
  void Main(void);
  void Comments(void);
  
 private:
  std::string code;
};