#include "usage.h"

/**
 * @brief Define como se debe usar el programa
 * 
 * @param argc 
 * @param argv 
 */
void Usage(int argc, char* argv[]) {
  std::string help = argv[1];
  if ((argc < 6 || argc > 6) && help != "--help") {
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
 * @param lenguaje_1
 * @param lenguaje_2 
 * @param opcode 
 */
void Selector(std::ofstream& fileout, Lenguaje& lenguaje_1, Lenguaje& lenguaje_2, int opcode, std::string cadena) {
  switch (opcode) {
  case 1:
    fileout << (lenguaje_1 * lenguaje_2) * cadena << std::endl;
    break;
  case 2:
    fileout << lenguaje_1 + lenguaje_2 << std::endl;
    break;
  case 3: 
    fileout << lenguaje_1 / lenguaje_2 << std::endl;
    break;
  case 4:
    fileout << lenguaje_1 - lenguaje_2 << std::endl; 
    break;
  case 5:
    lenguaje_1.ReverseLenguage();
    fileout << lenguaje_1 << std::endl;
    break;
  case 6:
    int n;
    std::cout << "Introduzca la potencia para el lenguaje: " << lenguaje_1 << std::endl;
    std::cin >> n;
    n--;
    fileout << lenguaje_1.PowLenguage(lenguaje_1, n) << std::endl;
    break;
  default:
    break;

  }
}
