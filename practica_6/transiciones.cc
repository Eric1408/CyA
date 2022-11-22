#include "transiciones.h"

Transicion::Transicion(std::string input) {
  char char_transition = input[0];
  int state = input[2] - '0';
  //next_[Simbolo(char_transition)] = state;
  symbol_ = Simbolo(char_transition);
  next_ = state;

  //std::cout << "Transicion:\n   symbol_: " << symbol_ << "\n  next_: " << next_ << std::endl;
}
