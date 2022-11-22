#include "automata.h"

/**
 * @brief Constructor Automota
*/
Automata::Automata(std::ifstream& in) {
  std::string lines;
  int counter = 0;
  while (getline(in, lines)) {
    switch (counter) {
    case 0:
      alpha_ = Alfabeto(lines); 
      counter++;
      break;
    case 1:
      total_states_ = stoi(lines);
      counter++;
      break;
    case 2:
      start_ = stoi(lines);
      counter++;
      break;
    default:
      std::string original_lines = lines;
      int index = lines[0] - '0';
      states_[index] = Estado(lines);
      lines.erase(0, 6);

      std::string aux;
      for (int i = 0; i < states_[index].GetTransitions(); i++) {
        aux = lines.substr(0,4);
        transitions_[index].push_back(aux);
        if (!CheckSymbol(transitions_[index][i].GetSymbol())) {
          std::cerr << "El simbolo " << transitions_[index][i].GetSymbol() << " no pertenece al alfabeto\n";
          exit(EXIT_SUCCESS);
        }
        lines.erase(0,4);
      }
      counter++;
      break;
    }
  }

  counter = counter - 3;
  if (counter != total_states_) {
    std::cout << "Mira bien pendejo\n";
    exit(EXIT_FAILURE);
  }
}

/**
 * @brief Comprueba si los Simbolos pertenece al Alfabeto
*/
bool Automata::CheckSymbol(const Simbolo& input) {
  for (auto const& str : alpha_.GetSetAlpha()) {
    if (str.GetSymbol() == input.GetSymbol()) {
      return true;
    }
  }

  return false;
}

/**
 * @brief Comprueba si la cadena es aceptada o rechazada por el automata
*/
bool Automata::CheckString(std::string input) const {
  int node = start_ ;
  //for (char it_c : input) {
  //  if (states_.at(node).Check(Simbolo(it_c))) {
  //    node = states_.at(node).GetNext(Simbolo(it_c));
  //  } else {
  //    return false;
  //  }
  //} 

  if (states_.at(node).IsAcepted()) {
    return true;
  } else {
    return false;
  }
}

