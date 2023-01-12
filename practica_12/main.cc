/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file main.cc
 * @brief Fcihero que main que contiene el programa principal  
 * @author Eric Angueta Rogel || alu0101335339@ull.edu.es
 * @version 0.1
 * @date 2022-09-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <chrono>

#include "usage.h"
#include "BigInt.h"

int main(int argc, char* argv[]) {
  Usage(argc, argv);
  
  BigInt n1;
  BigInt n2;
  
  std::cin >> n1;
  std::cin >> n2;

  auto start = std::chrono::high_resolution_clock::now();
  if (std::string(argv[1]) == "-k") {
    std::cout << KaratsubaBigInt(n1, n2) << std::endl;
  } else if (std::string(argv[1]) == "-m") {
    std::cout << n1 * n2 << std::endl;  
  } else if (std::string(argv[1]) == "-n") {
    int cota = atoi(argv[2]);
    if (Length(n1) < cota || Length(n2) < cota) {
      std::cout << n1 * n2 << std::endl;
    } else {
      std::cout << KaratsubaBigInt(n1, n2) << std::endl;
    }
  } else if (std::string(argv[1]) == "-r") {
    int random = atoi(argv[2]);
    n1 = GenerateRandomNumber(random);
    n2 = GenerateRandomNumber(random);
    std::cout << n1 * n2 << std::endl;
  }

  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
  std::cout << "duracion: " << duration.count() << std::endl;
  
  return 0;
}