#include "simbolo.h"

/**
 * @brief Sobrecarga del operador << para la clase Simbolo
*/
std::ostream& operator<<(std::ostream& out, const Simbolo& sym) {
  out << sym.symbol_;
  
  return out;
}

/**
 * @brief Sobrecarga del operador < para la clase Simbolo, lo utiliza set
*/
bool operator<(const Simbolo& operand1, const Simbolo& operand2) {
  return operand1.symbol_ < operand2.symbol_;
}
