/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file analyzer_main.cc
 * @brief Fichero de cabecera donde contiene a todas las clases 
 * necesarias para anlizar el codigo
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
#include <vector>
#include <regex>

#include "var.h"
#include "loop.h"
#include "comment.h"
#include "description.h"

class Analyzer{
 public:
  Analyzer(void) : variables_{}, loops_{}, main_{}, descript_{} {}

  void Build(std::string, int);

  inline int LoopSize(void) const {return loops_.size();}
  inline int VarSize(void) const {return variables_.size();}
  inline int CommentSize(void) const {return comments_.size();}

  friend std::ostream& operator<<(std::ostream& out, const Analyzer&);

 private:
  bool main_;  
  Description descript_;
  std::vector<Loop> loops_;
  std::vector<Var> variables_;
  std::vector<Comment> comments_;
};