#include "gramatica.h"

/**
 * @brief Construct a new Gramatica:: Gramatica object
 * 
 * @param input 
 */
Gramatica::Gramatica(std::istream& input) {
  int size{0};
  char aux;

  // TERMINAL SIZE && TERMINALS
  input >> size;
  for (int i = 0; i < size; ++i) {
    input >> aux;
    terminal_.Insert(aux); 
  }

  // NO TERMINAL SIZE && NO TERMINALS  
  input >> size;
  for (int i = 0; i < size; i++) {
    input >> aux;
    no_terminal_.Insert(aux);
  }
  
  // START SYMBOL
  input >> aux;
  start_ = Simbolo(aux);
  
  // SIZE PRODUCTIONS && PRODUCTIONS
  input >> size;
  std::string line;
  // primer getline le pasa a line una cadena vacia (no se el motivo)
  getline(input, line);
  for (int i = 0; i < size; ++i) {
    getline(input, line);
    CheckGrammar(line);
    std::string arrow_reference = line.substr(5,line.size());
    producciones_[Simbolo(line[0])].push_back(arrow_reference);
  }
  
}

/**
 * @brief 
 * 
 * @param input 
 * @return true 
 * @return false 
 */
bool Gramatica::IsNoTerminal(char input) const {
  for (auto const& it : no_terminal_.GetSetAlpha()) {
    if (it.GetSymbol() == input) {
      return true;
    }
  }

  return false;
}

/**
 * @brief 
 * 
 */
void Gramatica::ToChomsky(void) {  
  for (auto const& it : producciones_) {
    for (size_t i = 0; i < it.second.size(); ++i) {
      if (it.second[i].size() >= 2) {
        for (size_t j = 0; j < it.second[i].size(); ++j) {
          char symbol_it = it.second[i][j]; 
          if (!IsNoTerminal(symbol_it)) {
            std::string to_push("");
            to_push.push_back(symbol_it);
            char new_symbol(GenerateSymbol());

            AddNoTerminal(new_symbol);
            producciones_[Simbolo(new_symbol)].push_back(to_push);
            Replace(symbol_it, new_symbol);
          }
        }
      }
    }
  }
  Producciones aux = producciones_;
  // ACCEDE A PRODUCCIONES_[IT]
  for (auto& it : aux) {
    //std::cout << it.first << ": \n";
    for (size_t i = 0; i < it.second.size(); ++i) {
      // PRODUCCIONES_[IT][VECTOR]
      //std::cout << "  " << it.second[i] << std::endl;
      std::string copy = it.second[i];
      if (it.second[i].size() >= 3) {
        
        //for (size_t j = 0; j < copy.size() - 1; ++j) {
        //  // PRODUCCIONES_[IT][VECTOR][STRING]
        //  // hacer una func recursiva?
        //  if (IsNoTerminal(it.second[i][j])) {
        //    char new_symbol(GenerateSymbol());
        //    AddNoTerminal(new_symbol);
        //  }
        //}
      }
    }
  }
}

void Gramatica::Last(Producciones& in) {
  for (auto& it : in) {
    
  }
}

//char Gramatica::RecursiveChange(std::string input) {
  

  //if (input.size() <= 2) {
  //  char chr = GenerateSymbol();
  //  //producciones_[Simbolo(chr)].push_back(input);
  //  
  //  return chr;
  //} else {
  //  
  //  char ch = RecursiveChange(input.substr(1, input.size()));
  //  
  //  //producciones_[Simbolo(ch)].push_back();
  //}
   
//}

/**
 * @brief 
 * 
 * @param to_replace 
 * @param new_char 
 */
void Gramatica::Replace(char to_replace, char new_char) {
  for (auto& it : producciones_) {
    for (size_t i = 0; i < it.second.size() ; i++) {
      if (it.second[i].size() >= 2) {
        for (size_t j = 0; j < it.second[i].size(); ++j) {         
          if (it.second[i][j] == to_replace) {
            it.second[i][j] = new_char;
          }
        }
      }
    }
  }
}

/**
 * @brief 
 * 
 * @param out 
 * @param input 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& out, const Gramatica& input) {
  Simbolo init = input.GetStart();
  for (int i = 0; i < input.ProdSize(init); ++i) {
    out << input.GetStart() << " -> " << input.GetProductions().at(init)[i] << std::endl;
  }
  for (auto const& it : input.GetProductions()) {
    if (it.first != input.GetStart()) {
      for (int i = 0; i < input.ProdSize(it.first); ++i) {
        out << it.first << " -> " << it.second[i] << std::endl;
      }
    }
    
  }
  
  return out;
}

/**
 * @brief 
 * 
 * @return char 
 */
char Gramatica::GenerateSymbol(void) const {
  std::srand(time(NULL));
  char ch;
  do {
    ch = 'A' + std::rand() % 26;
  } while (IsNoTerminal(ch));
  
  return ch;
}

/**
 * @brief 
 * 
 * @param input 
 * @return true 
 * @return false 
 */
bool Gramatica::CheckGrammar(std::string input) const {
  char symbol = input[0];
  std::string prod = input.erase(0,5);
  prod.push_back(symbol);

  for (size_t i = 0; i < prod.size(); ++i) {
    if (!CheckSymbol(prod[i]) || prod[i] == ' ') {
      std::cerr << "Simbolo: " << prod[i] << " no pertenece a ningun alfabeto\n";
      exit(EXIT_FAILURE);
    }
  }

  return true;
}

/**
 * @brief 
 * 
 * @param to_check 
 * @return true 
 * @return false 
 */
bool Gramatica::CheckSymbol(char to_check) const {
  Alfabeto check = terminal_ + no_terminal_;

  for (auto const& it : check.GetSetAlpha()) {
    if (to_check == it.GetSymbol()) {
      return true;
    }
  }

  return false;
}
