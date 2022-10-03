#pragma once

#include <iostream>
#include <string>

const char SPACE = ' ';
const char ENDL = '\n';
const int ZERO = 0;

class Simbolo {
 public:
  Simbolo(void) : symbol_("") {}
  Simbolo(std::string input) {symbol_ = input;}

  void Write(std::ostream&) const;

 private:
  std::string symbol_;
};

void Simbolo::Write(std::ostream& os) const {
  os << symbol_;
}

std::ostream& operator<<(std::ostream& os, const Simbolo& symbol) {
  symbol.Write(os);
  return os; 
}

class Alfabeto {
 public:
  Alfabeto(void) : symbol_{} {}
  Alfabeto(std::string);
  void Build(std::string);
  void GetAlpha(void);

 private:
  std::vector<Simbolo> symbol_;
};

void Alfabeto::GetAlpha(void) {
  for (int i = 0; i < symbol_.size(); ++i) {
    std::cout << symbol_[i] << " ";
  }
}

void Alfabeto::Build(std::string input) {
  //bool space{true};
  int size = input.size();
  std::string push_string{""};
  
  for (int i = 0; i < size; ++i) {
    if (input[i] != SPACE) {
      push_string += input[i];
    } else if (input[i] == SPACE || ENDL){
      symbol_.push_back(push_string);
      push_string = "";
    }
  }
  
  //for (int i = 0; i < size; i++) {
  //  if (input[i] != SPACE) {
  //    push_string += input[i];
  //  } else if (input[i] == SPACE) {
  //    space = false;
  //    //std::cout << push_string;
  //    symbol_.push_back(push_string);
  //    push_string = "";
  //  }
  //}
  //
  //if (space) {
  //  //std::cout << input;
  //  symbol_.push_back(input);
  //}
}

class Cadena : public Alfabeto {
 public:
  Cadena(void) : length_{0} {}
  Cadena(std::string);

  inline int Length(void) {return length_;}
  void Reverse(void);
  void Prefix(void);
  void Suffix(void);
  void Substring(void);

 private:
  int length_;
  std::string cadena_;
  Alfabeto alpha_;
};

void Cadena::Prefix(void) {
  
}

Cadena::Cadena(std::string input) {
  const int size = input.size();
  int i = size;
  length_ = -1;

  while (input[i] != SPACE) {
    length_++;
    length_ > size ? length_ = input.size() : length_ ;
    --i;
  }

  int cadena_begin = size - length_;
  cadena_ = input.substr(cadena_begin, length_);

  int alpha_size = size - length_;
  alpha_size == ZERO ? alpha_size = size : alpha_size;  
  alpha_.Build(input.substr(ZERO, alpha_size));
  //alpha_.GetAlpha();
}

void Cadena::Reverse() {
  for (int i = length_; i >= ZERO; --i) 
    std::cout <<  cadena_[i];
}
