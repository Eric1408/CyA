#pragma once 

#include <cstdlib>
#include <iostream>
#include <string>

const std::string kHelp = "En esta practica se desarrollara un programa dfa2grammar que lea un fichero de texto\n"
                          ".fa en el que figure la especificacion de un DFA M y genere un fichero .gra que contenga\n"
                          "la especificacion de una gramatica regular G tal que L(M) = L(G). Para obtener la\n"
                          "gramatica G, tal que L(G) = L(M), aplicaremos el algoritmo visto en clase y disponible\n"
                          "en las transparencias del tema 3 de la asignatura \n"
                          "son rechazadas o acpetadas por el automata (DFA o NFA)\n";
const std::string kUse = "Modo de empleo: ./dfa2grammar input.fa output.gra\n"
                         "Pruebe ‘dfa2grammar --help’ para mas informacion.\n";

void Usage(int, char*[]);
