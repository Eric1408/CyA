#include "simbolo.h"

/**
 * @brief 
 * 
 * @param out 
 * @param sym 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const Simbolo& sym) {
  out << sym.symbol_;
  
  return out;
}

/**
 * @brief 
 * 
 * @param operand1 
 * @param operand2 
 * @return true 
 * @return false 
 */
bool operator<(const Simbolo& operand1, const Simbolo& operand2) {
  return operand1.symbol_ < operand2.symbol_;
}
