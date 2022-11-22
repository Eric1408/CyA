#include "estado.h"

/**
 * @brief Constructor Estado
*/
Estado::Estado(std::string input) {
  name_ = input[0] - '0';
  final_ = input[2] - '0';
  total_transitions_ = input[4] - '0';
  input.erase(0, 4);
  //std::cout << "Estado:\nName: " << name_ << "\nFinal: " << final_ << "\nTotal Transitions: " 
  //          << total_transitions_ << std::endl;
  
  //for (int i = 0; i < total_transitions_; ++i) {
  //  next_[Simbolo(input[0])] = input[2] - '0';
  //  input.erase(0, 4);
  //}

}

/**
 * @brief sobrecarg del operador <<
*/
std::ostream& operator<<(std::ostream& out, const Estado& input) {
  //for (auto const& it : input.next_) {
  //  out << "con un " << it.first.GetSymbol() << " pasa al estado " << it.second << std::endl; 
  //}

  return out;
}

/**
 * @brief Comprueba si un Simbolo de la cadena es admisible para una transicion
*/
bool Estado::Check(const Simbolo& input) const {
  //for (auto& it : next_ ) {
  //  if (input.GetSymbol() == it.first.GetSymbol()) {
  //    return true;
  //  }
  //}

  return false;
}
