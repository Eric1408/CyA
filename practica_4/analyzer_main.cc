#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
  std::string name{argv[1]};
  std::string out{argv[2]};

  std::ifstream code{name};
  std::ofstream output{out};
  std::string aux;

  while (getline(code, aux)) {
    std::cout << aux << std::endl;
  }

  return 0;
}