#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <map>

#include"simbolo.h"
#include "alfabeto.h"

typedef std::vector<std::string> vec_string; 
typedef std::map<Simbolo, vec_string> Producciones;

class Gramatica {
 public:
  Gramatica(std::istream&);

  // CHECKERS
  bool CheckGrammar(std::string) const;
  bool CheckSymbol(char) const;
  bool IsNoTerminal(char) const;

  // GETTERS
  inline Simbolo GetStart(void) const { return start_; }
  inline Alfabeto GetTerminals(void) const { return terminal_; }
  inline Alfabeto GetNoTerminals(void) const { return no_terminal_; }
  inline Producciones GetProductions(void) const { return producciones_; }

  // SETTERS
  inline void AddNoTerminal(char ch) { no_terminal_.Insert(ch); }
  inline void AddProd(char ch, std::string str) { producciones_[ch].push_back(str); }
  
  // SIZE GETTERS
  inline int TerminalSize(void) const { return terminal_.Size(); }
  inline int NoTerminalSize(void) const { return no_terminal_.Size(); }
  inline int TotalProductions(void) const { return producciones_.size(); } 
  inline int ProdSize(const Simbolo& i) const { return producciones_.at(i).size(); }

  // FOR CLASS MODIFY
  void ToChomsky(void);
  void Replace(char, char);
  char GenerateSymbol(void) const; 
  //char RecursiveChange(std::string);
  void Last(Producciones&);

  friend std::ostream& operator<<(std::ostream&, const Gramatica&);

 private:
  Simbolo start_;
  Alfabeto terminal_;
  Alfabeto no_terminal_;
  Producciones producciones_;
};