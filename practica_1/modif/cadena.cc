#include "cadena.h"

/**
 * @brief Agrega al archivo de salida los prefijos de la cadena 
 * 
 * @param out 
 */
void Cadena::Prefix(std::ofstream& out) {
  std::string result;
  
  if (length_ == -1) {
    out << cadena_incorrecta;
  } else {
    out << "& ";
    for (int i = 0; i < length_; ++i) {
      result += cadena_[i].GetSymbol();
      out << result << " ";
    }
  }
  
}

/**
 * @brief Agrega al archivo de salida los sufijos de la cadena 
 * 
 * @param out 
 */
void Cadena::Suffix(std::ofstream& out) {
  std::string result;
  std::string aux;

  if (length_ == -1) {
    out << cadena_incorrecta;
  } else {
    out << "& ";
    for (int i = length_ - 1; i >= 0; --i) {
      aux += cadena_[i].GetSymbol();
      result = Reverse(aux);
      out << result << " ";
    } 
  }
}

std::string Cadena::Reverse(std::string input) {
  std::string result;
  for (int i = input.size() -1; i >= ZERO; --i) { 
    result += input[i];
  }
  if (length_ == -1) {
    return cadena_incorrecta;
  }

  return result;
}

void Cadena::PrefLessSuf(std::ofstream& out) {
  std::string pref;
  std::string aux;
  std::string suff;

  if (length_ == -1){
    out << cadena_incorrecta;
  } else {
    for (int i = 0, j = length_ - 1; i < length_ && j >= 0; ++i, --j) {
      aux += cadena_[j].GetSymbol();
      suff = Reverse(aux);
      pref += cadena_[i].GetSymbol();
      if (suff != pref) {
        out << pref <<" ";
      }
    }
  }
}


/**
 * @brief Agrega al archivo de salida las subcadenas 
 * 
 * @param out 
 */
void Cadena::Substring(std::ofstream& out) {
  if (length_ == -1) {
    out << cadena_incorrecta;
  } else {
    out << "& ";
    std::string result;
    for (int i = 0; i < length_; ++i) {
    for (int j = i; j < length_; ++j) {
      result += cadena_[j].GetSymbol();
      out << result << " ";
    }
    result = "";
  }
  }
  
}

/**
 * @brief Agrega al archivo de salida la inversa de la cadena
 * 
 * @return std::string 
 */
std::string Cadena::Reverse(void) {
  std::string result;
  for (int i = length_ -1; i >= ZERO; --i) { 
    result += cadena_[i].GetSymbol();
  }
  if (length_ == -1) {
    return cadena_incorrecta;
  }

  return result;
}

/**
 * @brief Construct a new Cadena:: Cadena object
 * 
 * @param input 
 */
Cadena::Cadena(std::string input) {
  const int MAX_SIZE = 500;
  size_t last_space = input.find_last_of(SPACE);
  int size = input.size() - last_space - 1;
  std::string cadena = input.substr(last_space + 1, size);
  std::string push_symbol;
  length_ = 0;

  if (last_space != std::string::npos ) {
    alpha_.Build(input.substr(ZERO, last_space + 1));
    int romper = 0;
    int pos{0};
    while (cadena.size() > ZERO) {
      bool inside = {false};
      if (romper == MAX_SIZE) {
        cadena_incorrecta = "La cadena es incorrecta [" + input.substr(last_space + 1, size) + ']';
        length_ = -1;
        cadena_.clear();
        break;
      }
      for (int i = 0; i < alpha_.at(pos).SymSize(); ++i) {
        push_symbol += cadena[i];        
        if (push_symbol == alpha_.at(pos).GetSymbol()) {
          inside = true;
          cadena_.push_back(push_symbol);
          cadena.erase(ZERO, push_symbol.size());
          push_symbol = "";
          length_++;
        } else {
          inside = false;
        }
      }
      if (inside == false) {
        ++pos;
        push_symbol = "";
      }
      if (pos == alpha_.Size()) {
        pos = 0;
      }
      romper++;
    }
  } else {
    alpha_.Build(cadena);
    for (size_t i = 0; i < cadena.size(); ++i) {
      push_symbol = cadena[i];
      cadena_.push_back(push_symbol);
      length_++;
    }
  }
}
