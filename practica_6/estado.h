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
#include <map>

#include "simbolo.h"

/**
 * @class Estado
*/
class Estado {
 public:
  Estado(void) : final_{0}, transitions_{0}, next_{} {}  
  Estado(std::string);
  
  inline bool IsAcepted(void) const {return final_ == 1 ? true : false;}
  inline std::map<Simbolo, int> GetMap(void) const {return next_;}
  inline int GetNext(const Simbolo& i) const {return next_.at(i);}
  
  bool Check(const Simbolo&) const ;
  friend std::ostream& operator<<(std::ostream&, const Estado&);

 private:
  int final_;
  int transitions_;
  std::map<Simbolo, int> next_;
};

