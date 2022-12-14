#include "alfabeto.h"
/**
 * @brief Construct a new Alfabeto:: Alfabeto object
 * 
 * @param in 
 */
Alfabeto::Alfabeto(std::string in) {
  for (size_t i = 0; i < in.size(); ++i) {
    this -> Insert(in[i]);
  }
}

/**
 * @brief Metodo que es una especie de constructor de alfabeto
*/
void Alfabeto::Insert(char input) {
  if (input != EMPTYCHAIN && input != ' ')
    alpha_symbol_.insert(input);
}

std::ostream& operator<<(std::ostream& out, const Alfabeto& input) {
  for (auto& str : input.alpha_symbol_) {
    out << str.GetSymbol() << std::endl;
  }
  
  return out;
}

Alfabeto operator+(const Alfabeto& sum1, const Alfabeto& sum2) {
  Alfabeto result;
  for (auto const& str : sum1.alpha_symbol_) {
   result.Insert(str.GetSymbol()); 
  }

  for (auto const& str : sum2.alpha_symbol_) {
    result.Insert(str.GetSymbol());
  }

  return result;
}
