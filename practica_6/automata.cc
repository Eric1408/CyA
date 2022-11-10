#include "automata.h"

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
      init_ = stoi(lines);
      counter++;
      break;
    default:
      int index = lines[0] - '0';
      lines.erase(0, 2);
      states_[index] = Estado(lines);
      CheckSymbol(states_[index]);
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

void Automata::CheckSymbol(const Estado& input) {
  for (auto const& it : input.GetMap()) {
    if (!Belong(it.first.GetSymbol())) {
      std::cout << "El simbolo: " << it.first.GetSymbol() << " no pertenece al alfabeto:\n";
      std::cout << alpha_.GetAlpha() << std::endl;
      exit(EXIT_FAILURE); 
    }    
  }
}

bool Automata::Belong(const Simbolo& input) {
  for (auto const& str : alpha_.GetSetAlpha()) {
    if (str.GetSymbol() == input.GetSymbol()) {
      return true;
    }
  }
  
  return false;
}
