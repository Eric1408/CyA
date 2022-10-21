#include "simbolo.h"

/**
 * @brief Metodo para escribir el contenido de Simbolo 
 * 
 * @param os 
 */
//void Simbolo::Write(std::ostream& os) const {
//  os << symbol_;
//}

std::ostream& operator<<(std::ostream& out, const Simbolo& sym) {
  out << sym.symbol_;
  
  return out;
}

bool operator<(const Simbolo& operand1, const Simbolo& operand2) {
  return operand1.symbol_ < operand2.symbol_;
}
