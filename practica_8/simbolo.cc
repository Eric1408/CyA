#include "simbolo.h"

/**
 * @brief Metodo para escribir el contenido de Simbolo 
 * 
 * @param os 
 */
std::ostream& operator<<(std::ostream& out, const Simbolo& sym) {
  out << sym.symbol_;
  
  return out;
}

bool operator<(const Simbolo& operand1, const Simbolo& operand2) {
  return operand1.symbol_ < operand2.symbol_;
}

bool operator!=(const Simbolo& in_1, const Simbolo& in_2) {
  return in_1.GetSymbol() != in_2.GetSymbol();
}
