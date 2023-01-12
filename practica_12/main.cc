/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file automata_main.cc
 * @brief Fcihero que main que contiene las clase automata para generar uno 
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

//#include "usage.h"
#include "BigInt.h"

int main(int argc, char* argv[]) {
  std::string numb1, numb2;
  
  std::cin >> numb1;
  std::cin >> numb2;

  BigInt n1(numb1);
  BigInt n2(numb2);
  
  if (std::string(argv[1]) == "-k") {
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << KaratsubaBigInt(n1, n2) << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "duracion: " << duration.count() << std::endl;
  
  } else if (std::string(argv[1]) == "-m") {
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << n1 * n2 << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "duracion: " << duration.count() << std::endl;
  
  }
  
  //Karatsuba kara(n1, n2);
  //kara.Metodo(n1, n2);
  
  return 0;
}