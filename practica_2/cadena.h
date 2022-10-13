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

  std::string Reverse(void) const;
  std::string Reverse(std::string);
  inline int Length(void) {return length_;}
  void Prefix(std::ofstream&);
  void Suffix(std::ofstream&);
  void Substring(std::ofstream&);

  std::string GetCadena(void) const;

  friend std::ostream& operator<<(std::ostream&, const Cadena&);
  friend bool operator<(const Cadena&, const Cadena&);
  
 private:
  int length_;
  std::vector<Simbolo> cadena_;
  std::string cadena_incorrecta;
};
