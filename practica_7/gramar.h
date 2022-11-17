#pragma once 

#include <iostream>
#include <string>
#include <map>
#include <set>

#include "automata.h"
#include "simbolo.h"

const int ALPHA_SIZE{27};

class Grammar {
 public:
  Grammar(Automata in) : dfa_{in} {}
  
  inline int GetTerminalsSize(void) {return dfa_.AlphaSize();}
  inline std::set<Simbolo> GetTerminals(void) {return dfa_.GetSimbolos();}
  inline int GetEstadosSize(void) {return dfa_.GetEstdoSize();}
  inline int GetStart(void) {return dfa_.GetInit();}
  void Translate(void);


  friend std::ostream& operator<<(std::ostream&, Grammar&);
 private:
  // Simbolos del alfabeto E (Lo contiene el DFA)
  // Conjunto de simbolos no terminales V = Conjunto de estados(std::map<int, Estado> estados_)
  // Simbolo de arranque S = Estado de arranque(int init_)
  std::map<int, char> no_terminal_;
  // Conjunto de reglas de produccion P
  Automata dfa_;
};