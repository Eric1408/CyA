#include "usage.h"

/**
 * @brief Define como se debe usar el programa
 * 
 * @param argc 
 * @param argv 
 */
void Usage(int argc, char* argv[]) {
  std::string help = argv[1];
  if ((argc < 4 || argc > 4) && help != "--help") {
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
void Selector(std::ofstream& fileout, std::vector<Cadena>& cadenas, int opcode) {
  switch (opcode) {
  case 1:
    for (size_t i = 0; i < cadenas.size(); ++i) {
      fileout << cadenas[i].Length() << std::endl;
    }
    break;
  case 2:
    for (size_t i = 0; i < cadenas.size(); ++i) {
      fileout << cadenas[i].Reverse() << std::endl;
    } 
    break;
  case 3: 
    for (size_t i = 0; i < cadenas.size(); ++i) {
      cadenas[i].Prefix(fileout); 
      fileout << std::endl;
    }
    break;
  case 4: 
    for (size_t i = 0; i < cadenas.size(); ++i) {
      cadenas[i].Suffix(fileout); 
      fileout << std::endl;
    }
    break;
  case 5:
    for (size_t i = 0; i < cadenas.size(); i++) {
      cadenas[i].Substring(fileout);
      fileout << std::endl;
    }
    break;
  case 6:
    for (size_t i = 0; cadenas.size(); ++i) {
      cadenas[i].PrefLessSuf(fileout);
      fileout << std::endl;
    }
  default:
    break;

  }
}
