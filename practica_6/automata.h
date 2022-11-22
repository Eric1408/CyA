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
#include <map>

#include "alfabeto.h"
#include "estado.h"
#include "simbolo.h"
#include "transiciones.h"

typedef std::vector<Transicion> vec_transition; 

class Automata {
 public:
  Automata(std::ifstream&);
  
  //Checkeo de simbolos
  bool CheckSymbol(const Simbolo&); 
  //Checkeo de la cadena
  bool CheckString(std::string) const;

  //Getters
  inline int StateSize(void) const { return total_states_; }
  inline Estado GetState(int i) const { return states_.at(i); }
  inline int TransitionSize(int i) const { return transitions_.at(i).size(); }
  inline Transicion GetTransition(int i, int j) const { return transitions_.at(i)[j]; }

 private:
  Alfabeto alpha_;
  int total_states_;
  int start_;
  
  //maps de Estados el nombre lo alberga maps
  std::map<int, Estado> states_;
  std::map<int, vec_transition> transitions_;
  //vector de Estados el nombre lo alberga Estados
  //std::vector<Estado> estados_; 

};