#include "voraces.h"

/**
 * @brief Construct a new Voraces:: Voraces object
 * 
 * @param input 
 */
Voraces::Voraces(std::vector<int>& input) {
  for (std::vector<int>::iterator it = input.begin(); it != input.end(); ++it) {
    coins_.push_back(*it);
  }
}

/**
 * @brief dada una divisa, genera el cambio en monedas o billetes del valor exacto de la divisa
 *        utilizando un algoritmo O(m)
 * 
 * @param input 
 * @return conjunto 
 */
conjunto Voraces::Devolver(double input) {
  int cantidad = input * 100;
  conjunto solution;
  int sum = 0;
  
  for (int i = 0; i < Size(); ++i) {
    int c = (cantidad - sum) / GetAt(i);
    if (c > 0) {
      solution.emplace_back(c, GetAt(i)); 
      sum = sum + c * GetAt(i);
    }
  }

  return solution;
}

/**
 * @brief dada una divisa, genera el cambio en monedas o billetes del valor exacto de la divisa
 *        utilizando un algoritmo O(m * n)
 * 
 * @param input 
 * @return conjunto 
 */
conjunto Voraces::DevolverBasic(double input) {
  int cantidad = input * 100;
  std::vector<int> solution;
  int sum{0};

  while (sum != cantidad) {
    for (int i = 0; i < Size();) {
      int v = GetAt(i);
      if (sum + v > cantidad) {
        ++i;
      } else {
        solution.push_back(v);
        sum += v;
      }
    }
  }

  return ToConjunto(solution);
 }

/**
 * @brief Convierte un vector de enteros en un conjunto 
 * 
 * @param input 
 * @return conjunto 
 */
conjunto Voraces::ToConjunto(std::vector<int>& input) {
  int counter = 1;
  conjunto solution;
  
  for (size_t i = 0; i != input.size(); ++i) {
    if (input[i] == input[i + 1]) {
      counter++;
    } else {
      solution.emplace_back(counter, input[i]);
      counter = 1;
    }
  }

  return solution;
}

/**
 * @brief Muestra por pantalla el resultado de la conversion
 * 
 * @param input 
 * @param check_b 
 */
void Voraces::Write(const conjunto& input, bool check_b) const {
  int count{0};
  std::cout << "Solucion: ";

  for (size_t i = 0; i < input.size(); i++) {
    if (input[i].second >= 100) {
      if (i == input.size() -1) {
        input[i].first > 1 ? std::cout << input[i].first << 'x' << (input[i].second / 100) << "$\n" : std::cout << (input[i].second / 100) << "$\n";
      } else {
        input[i].first > 1 ? std::cout << input[i].first << 'x' << (input[i].second / 100) << "$, " : std::cout << (input[i].second / 100) << "$, ";
      }
    } else {
      if (i == input.size() -1) {
        input[i].first > 1 ? std::cout << input[i].first << 'x' << (input[i].second) << "c\n" : std::cout << (input[i].second) << "c\n";       
      } else {
        input[i].first > 1 ? std::cout << input[i].first << 'x' << (input[i].second) << "c, " : std::cout << (input[i].second) << "c, ";
      }
    }
    count += input[i].first;
  }
  
  check_b == true ? std::cout << "Total billetes o monedas: " : std::cout << "Total monedas: ";
  std::cout << count << std::endl;
}
