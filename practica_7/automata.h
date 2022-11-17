/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file automata.h
 * @author Eric Angueta Rogel || alu0101335339@ull.edu.es
 * @version 0.1
 * @date 2022-09-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

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
  inline int AlphaSize(void) {return alpha_.Size();}
  inline int GetEstdoSize(void) const {return total_states_;}
  inline Estado GetEstados(int i) const {return states_.at(i);}
  inline int GetTotalStates(void) const {return total_states_;}
  inline std::set<Simbolo> GetSimbolos(void) {return alpha_.GetSetAlpha();}
  inline int GetInit(void) {return init_;}

  std::vector<int> GetIndexState(void);
  
  bool CheckString(std::string) const;

 private:
  Alfabeto alpha_;
  int total_states_;
  int init_;
  std::map<int, Estado> states_;

};