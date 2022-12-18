#include "description.h"

/**
 * @name Consructor
 * @brief Constructor de la clase Description
*/
Description::Description(std::smatch matches, int pos) {
  pos_ini_ = pos;
  descript_ = matches[0];
}

/**
 * @name Build
 * @brief Metodo que permite añadir contenido a Description
*/
void Description::Build(std::smatch matches, int pos) {
  pos_ini_ = pos;
  descript_ = matches[0];
  descript_ += "\n";
}

/**
 * @name Insert
 * @brief Metodo que permite añadir contenido a Description
*/
void Description::Insert(std::smatch matches, int pos) {
  pos_end_ = pos;
  descript_ += matches[0];
}

/**
 * @name Insert
 * @brief Metodo que permite añadir contenido sin la posicion la clase Desription
*/
void Description::Insert(std::smatch matches) {
  descript_ += matches[0];
  descript_ += "\n";
}

/**
 * @name Sobrecarga
 * @brief sobrecarga del operador <<
*/
std::ostream& operator<<(std::ostream& out, const Description& descript) {
  out << descript.descript_;
  
  return out;
}
