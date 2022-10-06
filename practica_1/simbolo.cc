#include "simbolo.h"

/**
 * @brief Metodo para escribir el contenido de Simbolo 
 * 
 * @param os 
 */
void Simbolo::Write(std::ostream& os) const {
  os << symbol_;
}
