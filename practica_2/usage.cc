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
void Selector(std::ofstream& fileout, Lenguaje& lenguaje, Lenguaje& lenguaje_2, int opcode) {
  switch (opcode) {
  case 1:
    
    break;
  case 2:
    break;
  case 3: 
    break;
  case 4: 
    break;
  case 5:
    break;
  case 6:
    break;
  default:
    break;

  }
}
