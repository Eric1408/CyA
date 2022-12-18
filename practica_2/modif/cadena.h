/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file cadena.h
 * @author Eric Angueta Rogel || alu0101335339@ull.edu.es
 * @version 0.1
 * @date 2022-09-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <fstream>
#include <vector>
#include "alfabeto.h"

const int ZERO = 0;

/**
 * @brief La clase Cadena contiene todos los metodos necesarios para las opciones
 *        que pide la practica
 * 
 */
class Cadena {
 public:
  Cadena(void) : length_{0} {}
  Cadena(std::string);

  std::string Reverse(void) const;           // para practica 2
  std::string Reverse(std::string);          // para practica 1
  inline int Length(void) {return length_;}  // practica 1 
  void Prefix(std::ofstream&);               // practica 1
  void Suffix(std::ofstream&);               // practica 1
  void Substring(std::ofstream&);            // practica 1

  std::string GetCadena(void) const;         // practica 2

  friend std::ostream& operator<<(std::ostream&, const Cadena&); // practica 2
  friend bool operator<(const Cadena&, const Cadena&);            //practica 2
  
 private:
  int length_;
  std::vector<Simbolo> cadena_;
};
