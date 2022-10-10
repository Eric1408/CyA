#include "lenguaje.h"

Lenguaje::Lenguaje(std::string input) {
  std::string push;
  int resize_l{0};

  for (size_t i = 0; i < input.size(); ++i) {
    resize_l++;
    if (input[i] != '{' && input[i] != ' ') {
      push = input[i];
      alpha_.Build(push);
      std::cout << push << " ";
    } else if (input[i] == '}') {
      break;
    }
  }
  alpha_.GetAlpha();
  std::cout << std::endl;
}
