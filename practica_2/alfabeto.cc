#include "alfabeto.h"

/**
 * @brief Ordena el vector de simbolos de mayor a menor longitud de la string
 * 
 */
//void Alfabeto::Sort(void) {
//  std::string aux;
//  for (int i = 0; i < Size(); i++) {
//    for (int j = Size() - 1; j > i; --j) {
//      if (symbol_[i].SymSize() < symbol_[j].SymSize()) {
//        aux = symbol_[i].GetSymbol();
//        symbol_[i].SetSym(symbol_[j].GetSymbol());
//        symbol_[j].SetSym(aux);
//      }
//    }
//    
//  }
//}

/**
 * @brief Metodo para obtener el alfabeto (no se utiliza)
 * 
 */
void Alfabeto::GetAlpha(void) {
  for (auto& str: this->symbol_)
  {
    std::cout << str;
  }
  
}

/**
 * @brief Actua de constructor
 * 
 * @param input donde input es o la cadena o el alfabeto dado por el archivo de texto
 */
//void Alfabeto::Build(std::string input) {
//  
//  int size = input.size();
//  std::string push_string{""};
//  
//  size_t found = input.find(SPACE);
//  if (found != std::string::npos) {
//    for (int i = 0; i < size; ++i) {
//      if (input[i] != SPACE) {
//        push_string += input[i];
//      } else if (input[i] == SPACE){
//        symbol_.push_back(push_string);
//        push_string = "";
//      }
//    }
//  } else {
//    size_t counter;
//    push_string = input[0];
//    symbol_.push_back(push_string);
//    for (int i = 0; i < size; ++i) {
//      counter = 0;
//      for (size_t j = 0; j < symbol_.size() ; ++j) {
//        push_string = input[i];
//        if (push_string != symbol_[j].GetSymbol()) {
//          counter++;
//          if (counter == symbol_.size()) {
//            symbol_.push_back(push_string);
//          }
//        }
//      }
//    } 
//  }
//  Sort();
//}

void Alfabeto::Build(std::string input) {
  std::string push;
  for (size_t i = 0; i < input.size(); i++) {
    push = input[i];
    symbol_.insert(push);
  }
}

