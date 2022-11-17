#include "gramar.h"

/**
 * @brief Metodo para traducir indices de Estados a Simbolos no terminales
 * 
 */
void Grammar::Translate(void) {
  int number_of_states = GetEstadosSize();
  int j = 0;
  for (int i = 0; i < number_of_states; ++i) {
    
    if (dfa_.GetIndexState()[i] != GetStart()) {
      no_terminal_[dfa_.GetIndexState()[i]] = char('A' + j);
      ++j;
    } else {
      no_terminal_[dfa_.GetIndexState()[i]] = 'S';
    }
  }
}

std::ostream& operator<<(std::ostream& os, Grammar& gram) {
  os << gram.GetTerminalsSize() << std::endl;
  for (auto& it : gram.GetTerminals()) {
    os << it << std::endl;
  }
  os << gram.GetEstadosSize() << std::endl;
  gram.Translate();
  for (auto& it : gram.no_terminal_) {
    os << it.second << std::endl;
  }
  os << gram.no_terminal_[gram.GetStart()] << std::endl;


  return os;
}
