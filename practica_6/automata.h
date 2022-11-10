#pragma once

#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <map>

#include "alfabeto.h"
#include "estado.h"
#include "simbolo.h"

class Automata {
 public:
  Automata(std::ifstream&);
  
  //Checkeo de simbolos
  bool Belong(const Simbolo&);
  void CheckSymbol(const Estado&);

  //Getters
  inline Estado GetEstados(int i) const {return states_.at(i);}
  inline int GetTotalStates(void) const {return total_states_;}

  bool CheckString(std::string) const;

 private:
  Alfabeto alpha_;
  int total_states_;
  int init_;
  std::map<int, Estado> states_;

};