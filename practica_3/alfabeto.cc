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
  if (result.size() >= 2) {
    result.pop_back();
  }

  return result;
}

/**
 * @brief Metodo que es una especie de constructor de alfabeto
*/
void Alfabeto::Build(char input) {
  if (input != EMPTYCHAIN)
    alpha_symbol_.insert(input);
}

