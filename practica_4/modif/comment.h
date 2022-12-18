/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file comment.h
 * @brief Fuchero de cabecera que contiene la clase que almacena los comentarios de linea
 * @author Eric Angueta Rogel || alu0101335339@ull.edu.es
 * @version 0.1
 * @date 2022-10-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <iostream>
#include <regex>
#include <string>

class Comment {
 public:
  Comment(std::smatch, int);

  friend std::ostream& operator<<(std::ostream&, const Comment&);
 private:
  int position_;
  std::string comment_;
};
