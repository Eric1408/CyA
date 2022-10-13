#include "usage.h"

/**
 * @brief Define como se debe usar el programa
 * 
 * @param argc 
 * @param argv 
 */
void Usage(int argc, char* argv[]) {
  std::string help = argv[1];
  if ((argc < 5 || argc > 5) && help != "--help") {
    std::cout << kHelp;
    exit(EXIT_SUCCESS);
  } 
  if (argc == 2 && help == "--help") {
    std::cout << kExplain;
    exit(EXIT_SUCCESS);
  }
}

/**
 * @brief Selecciona la modalidad que dicte el usuario y la imprime en fileout
 * 
 * @param fileout 
 * @param cadenas 
 * @param opcode 
 */
void Selector(std::ofstream& fileout, Lenguaje& lenguaje_1, Lenguaje& lenguaje_2, int opcode) {
  switch (opcode) {
  case 1:
    std::cout << lenguaje_1 * lenguaje_2 << std::endl;
    break;
  case 2:
    std::cout << lenguaje_1 + lenguaje_2 << std::endl;
    break;
  case 3: 
    std::cout << lenguaje_1 / lenguaje_2 << std::endl;
    break;
  case 4:
    std::cout << lenguaje_1 - lenguaje_2 << std::endl; 
    break;
  case 5:
    lenguaje_1.ReverseLenguage();
    std::cout << lenguaje_1 << std::endl;
    break;
  case 6:
    
    break;
  default:
    break;

  }
}
