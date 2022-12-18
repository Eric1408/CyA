/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file description.h
 * @brief Fichero de cabecera que contiene las clase que alamacena la descripcion del programa
 * @author Eric Angueta Rogel || alu0101335339@ull.edu.es
 * @version 0.1
 * @date 2022-10-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <iostream>
#include <string>
#include <regex>

class Description {
 public:
  Description(void) : pos_ini_{0}, pos_end_{0}, descript_{""} {}
  Description(std::smatch, int);
  
  void Build(std::smatch, int);
  void Insert(std::smatch);
  void Insert(std::smatch, int);

  inline int GetInit(void) const {return pos_ini_;}
  inline int GetEnd(void) const {return pos_end_;} 

  friend std::ostream& operator<<(std::ostream&, const Description&);
 private:
  int pos_ini_;
  int pos_end_;
  std::string descript_;
};
