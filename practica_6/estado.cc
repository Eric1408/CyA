#include "estado.h"

Estado::Estado(std::string input) {
  final_ = input[0] - '0';
  transitions_ = input[2] - '0';
  input.erase(0, 4);

  for (int i = 0; i < transitions_; ++i) {
    next_[Simbolo(input[0])] = input[2] - '0';
    input.erase(0, 4);
  }

}

std::ostream& operator<<(std::ostream& out, const Estado& input) {
  for (auto const& it : input.next_) {
    out << "con un " << it.first.GetSymbol() << " pasa al estado " << it.second << std::endl; 
  }

  return out;
}
