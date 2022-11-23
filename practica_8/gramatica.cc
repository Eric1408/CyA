#include "gramatica.h"

Gramatica::Gramatica(std::istream& input) {
  std::string lines;
  int size{0};
  char aux;

  input >> size;
  for (int i = 0; i < size; ++i) {
    input >> aux;
    terminal_.Insert(aux);
  }
  input >> size;
  for (int i = 0; i < size; i++) {
    input >> aux;
    no_terminal_.Insert(aux);
  }
  input >> aux;
  start_ = Simbolo(aux);
  input >> size;
  std::cout << size << std::endl;
  std::string line;
  // el primer getline le pasa a line una  cadena vacia (no se el motivo)
  getline(input, line);
  for (int i = 0; i < size; ++i) {
    getline(input, line);
    std::cout << line << std::endl;
    
    producciones_[Simbolo(line[0])].push_back(line.erase(0,5));
  }

  for (auto const& it : producciones_) {
    std::cout << it.first << ":\n";
    for (size_t i = 0; i < it.second.size(); ++i) {
      std::cout <<  "   " << it.second[i] << std::endl; 
    }
  }
  //std::cout << "terminales: " << terminal_ << "\nNo terminales: " << no_terminal_ << std::endl;

}