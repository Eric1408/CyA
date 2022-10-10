#include "lenguaje.h"

Lenguaje::Lenguaje(std::string input) {
  std::string push;
  int resize_l{0};

  for (size_t i = 0; i < input.size(); ++i) {
      if (input[i] == '}') {
        break;
      }
    //std::cout << push;
    resize_l++;
    if (input[i] != '{' && input[i] != ' ') {
      push += input[i];
    }
  }
  //std::cout << push << std::endl;
  alpha_.Build(push);
  
  std::cout << std::endl;
}
