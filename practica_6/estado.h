/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file estado.h
 * @author Eric Angueta Rogel || alu0101335339@ull.edu.es
 * @version 0.1
 * @date 2022-09-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <iostream>
#include <string>

#include "simbolo.h"

class Estado {
 public:
  Estado(void) : name_{0}, final_{0}, total_transitions_{0} {}
  Estado(std::string);
  
  inline bool IsAcepted(void) const { return final_ == 1 ? true : false; }
  
  // Getters
  inline int GetName(void) const { return name_; }
  inline int GetFinal(void) const { return final_; }
  inline int GetTransitions(void) const { return total_transitions_; }
  //inline int GetNext(const Simbolo& i) const {return next_.at(i);}
  
  bool Check(const Simbolo&) const ;
  friend std::ostream& operator<<(std::ostream&, const Estado&);

 private:
  int name_;
  int final_;
  int total_transitions_;

  //Transicion transitions_;
  //std::map<Simbolo, int> next_;
};

