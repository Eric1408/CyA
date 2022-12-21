/**
 * @file voraces.h
 * @author Eric Angueta Rogel (alu0101335339@ull.edu.es)
 * @brief 
 * @version 0.1
 * @date 2022-12-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <vector>
#include <utility>
#include <iostream>

typedef std::vector<std::pair<int, int>> conjunto;

class Voraces {
 public:
  Voraces(std::vector<int>&);
  conjunto Devolver(double);
  conjunto DevolverBasic(double);
  conjunto ToConjunto(std::vector<int>&);
  
  //GETTERS 
  inline int GetAt(int i) const { return coins_[i]; }
  inline int Size(void) const { return coins_.size(); }

  void Write(const conjunto&, bool) const;

 private:
  std::vector<int> coins_;
};