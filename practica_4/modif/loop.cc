#include "loop.h"

/**
 * @name Constructor
 * @brief Constructor de la clase Loop
*/
Loop::Loop(std::smatch matches, int pos) {
  type_ = matches[1];
  position_ = pos;
}

/**
 * @name Sobrecarga
 * @brief Sobrecarga del operador <<
*/
std::ostream& operator<<(std::ostream& out, const Loop& input) {
  out << "[LINE " << input.position_ << "] LOOP: " << input.type_;

  return out;
}
