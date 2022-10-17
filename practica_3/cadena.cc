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
std::string Cadena::Reverse(void) const {
  std::string result;
  for (int i = length_ -1; i >= ZERO; --i) { 
    result += cadena_[i].GetSymbol();
  }
  if (length_ == -1) {
    return cadena_incorrecta;
  }

  return result;
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


Cadena::Cadena(std::string input) {
  length_ = 0;
  for (size_t i = 0; i < input.size(); i++) {
    length_++;
    cadena_.push_back(input[i]);  
  }
}

std::ostream& operator<<(std::ostream& out, const Cadena& input) {
  for (size_t i = 0; i < input.cadena_.size(); ++i) {
    out << input.cadena_[i];
  }

  return out;
}

bool operator<(const Cadena& in_1, const Cadena& in_2) {
  return in_1.cadena_ < in_2.cadena_;
}

std::string Cadena::GetCadena(void) const{
  std::string result;
    for (size_t i = 0; i < cadena_.size(); ++i) {
      result += cadena_[i].GetSymbol();
    }

  return result;
}
