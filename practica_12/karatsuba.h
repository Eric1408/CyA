#pragma once

#include "BigInt.h"

class Karatsuba {
 private:
  BigInt num1_;
  BigInt num2_;
 public:
  Karatsuba(void) : num1_{}, num2_{} {}
  Karatsuba(const BigInt& a, const BigInt& b) : num1_{a}, num2_{b} {}

  BigInt Metodo( BigInt&,  BigInt&);
};