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

#include "cadena.h"


const std::string kExplain  {"El modo de uso de este programa es el siguiente:\n"
                          "./p01_strings <entrada.txt> <salida.txt> <opcode>\n"
                          "Este programa realiza una serie de operaciones con el opcode proporcionado, son las siguientes:\n"
                          "   1 -> longitud de la cadena\n"
                          "   2 -> inversa de la cadena\n"
                          "   3 -> prefijos de la cadena\n"
                          "   4 -> sufijos de la cadena\n"
                          "   5 -> subcadenas de la cadena\n"
                          "Donde una vez dado la informacion se guardara en <salida.txt>\n"};
const std::string kHelp {"./p01_strings: faltan o se ha pasado del numero de argumentos.\n"
                          "Pruebe './p01_strings --help' para mas informacion\n"};
void Usage(int, char*[]);
void Selector(std::ofstream&, std::vector<Cadena>&, int);
