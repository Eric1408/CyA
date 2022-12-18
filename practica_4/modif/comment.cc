#include "comment.h"

/**
 * @name Constructor
 * @brief Metodo que permite construir la clase Comment
*/
Comment::Comment(std::smatch matches, int pos) {
  comment_ = matches[1];
  position_ = pos;
}

/**
 * @name Sobrecarga
 * @brief sobrecarga del operador <<
*/
std::ostream& operator<<(std::ostream& out, const Comment& com) {
  out << "[LINE " << com.position_ << "] " << com.comment_;
  
  return out;
}
