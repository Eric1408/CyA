/**
 * 
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Grado en Ingenieria Informatica
 * Curso: 2do
 * @category Computabilidad y Algoritmia
 * @file usage.h
 * @author Eric Angueta Rogel || alu0101335339@ull.edu.es
 * @version 0.1
 * @date 2022-09-29
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>



const std::string kExplain  {"El modo de uso de este programa es el siguiente:\n"
                          "./CalculadoraRPN <entrada.txt> <salida.txt>\n"
                          "Este programa analiza codigo distinguiento entre bucles, variables, comentarios y funcion principal\n"};
const std::string kHelp {"./p04_code_analyzer: faltan o se ha pasado del numero de argumentos.\n"
                          "Pruebe './p04_code_analyzer --help' para mas informacion\n"};
void Usage(int, char*[]);
