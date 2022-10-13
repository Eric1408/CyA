#include "alfabeto.h"

/**
 * @brief Metodo para obtener el alfabeto
 * 
 */
std::string Alfabeto::GetAlpha(void) const {
  std::string result{""};
  for (auto& str: alpha_symbol_) {
    result.push_back(str.GetSymbol());
    result += " ";
  }

  return result;
}

void Alfabeto::Build(char input) {
  alpha_symbol_.insert(input);
}

