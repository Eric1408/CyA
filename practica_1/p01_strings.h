#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

const char SPACE = ' ';
const int ZERO = 0;

class Simbolo {
 public:
  Simbolo(void) : symbol_("") {}
  Simbolo(std::string input) {symbol_ = input;}

  inline std::string GetSymbol(void) {return symbol_;}
  inline int SymSize(void) {return symbol_.size();}
  inline void SetSym(std::string input) {symbol_ = input;}

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


  void Sort(void);
  void GetAlpha(void);
  void Build(std::string);
  inline int Size(void) {return symbol_.size();}
  inline Simbolo at(int pos) {return symbol_[pos];}

 private:
  std::vector<Simbolo> symbol_;
};

void Alfabeto::Sort(void) {
  std::string aux;
  for (int i = 0; i < Size(); i++) {
    for (int j = Size() - 1; j > i; --j) {
      if (symbol_[i].SymSize() < symbol_[j].SymSize()) {
        aux = symbol_[i].GetSymbol();
        symbol_[i].SetSym(symbol_[j].GetSymbol());
        symbol_[j].SetSym(aux);
      }
    }
    
  }
}

void Alfabeto::GetAlpha(void) {
  for (int i = 0; i < symbol_.size(); ++i) {
    std::cout << symbol_[i] << " ";
  }
}

void Alfabeto::Build(std::string input) {
  ////////// CONSTRUCTOR QUE FUNCIONA CON VECTOR<SIMBOLO>
  
  int size = input.size();
  std::string push_string{""};
  
  size_t found = input.find(SPACE);
  if (found != std::string::npos) {
    for (int i = 0; i < size; ++i) {
      if (input[i] != SPACE) {
        push_string += input[i];
      } else if (input[i] == SPACE){
        symbol_.push_back(push_string);
        push_string = "";
      }
    }
  } else {
    int counter;
    push_string = input[0];
    symbol_.push_back(push_string);
    for (int i = 0; i < size; ++i) {
      counter = 0;
      for (int j = 0; j < symbol_.size() ; ++j) {
        push_string = input[i];
        if (push_string != symbol_[j].GetSymbol()) {
          counter++;
          if (counter == symbol_.size()) {
            symbol_.push_back(push_string);
          }
        }
      }
    } 
  }
  // metodo sort para ordenar el alphabeto de mayor a menor
  Sort();
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
  bool IsCorrect(std::string);

 private:
  int length_;
  Alfabeto alpha_;
  
  std::vector<Simbolo> sim_cadena_;
};

void Cadena::Prefix(void) {
  std::cout << "& ";
  for (int i = 1; i <= length_; ++i) {
    //std::cout << cadena_.substr(ZERO, i) << ' ';
  }
}

void Cadena::Suffix(void) {
  std::cout << "& ";
  int pos = 0;
  
  for (int i = 1; i <= length_; ++i) {
    pos = length_ - i;
    //std::cout << cadena_.substr(pos, i) << ' ';
  }
}

void Cadena::Substring(void) {
  std::cout << "& ";
  for (int i = 0; i < alpha_.Size(); i++) {
    std::cout << alpha_.at(i) << " ";
  }
  

  for (int i = 1; i <= length_; i++) {
    for (int j = 0; j < length_; j++) {
      //std::cout << cadena_.substr(j, i) << " ";
    }
  }
  
}

void Cadena::Reverse() {
  for (int i = length_; i >= ZERO; --i) {
    //std::cout <<  cadena_[i];
  }
}


Cadena::Cadena(std::string input) {
  const int MAX_BUCLE = 500;
  int last_space = input.find_last_of(SPACE);
  int size = input.size() - last_space - 1;
  std::string cadena = input.substr(last_space + 1, size);
  std::string push_symbol;
  length_ = 0;

  if (last_space != std::string::npos ) {
    alpha_.Build(input.substr(ZERO, last_space + 1));
    int romper = 0;
    int pos{0};
    //if (IsCorrect(cadena)) {
    while (cadena.size() > ZERO) {
      bool inside = {false};
      if (romper == MAX_BUCLE) {
        std::cout << "La cadena no pertenece al alfabeto\n";
        break;
      }
      for (int i = 0; i < alpha_.at(pos).SymSize(); ++i) {
        //std::cout << "iteracion i = " << i << std::endl;
        //std::cout << "  push sym = " << push_symbol << std::endl;
        //std::cout << "  pos = " << pos << std::endl;
        //std::cout << "  alpha.getsym = " << alpha_.at(pos).GetSymbol() << std::endl;
        push_symbol += cadena[i];        
        if (push_symbol == alpha_.at(pos).GetSymbol()) {
          //std::cout << "  Entrando en el if push == sym\n";
          //std::cout << "    size cadena = " << cadena.size() << std::endl;
          //std::cout << "    size cadena = " << cadena.size() << std::endl;
          inside = true;
          sim_cadena_.push_back(push_symbol);
          cadena.erase(ZERO, push_symbol.size());
          push_symbol = "";
          length_++;
        } else {
          inside = false;
        }
      }
      if (inside == false) {
        //std::cout << "Entrando en el if inside\n";
        ++pos;
        push_symbol = "";
      }
      if (pos == alpha_.Size()) {
        //std::cout << "Estra al if (pos == alpha.Size - 1)\n";
        pos = 0;
      }
      //if (romper == 20) {
      //  break;
      //}
      romper++;
    }
  } else {
    //cadena = input.substr(ZERO, last_space);
    alpha_.Build(cadena);
    for (int i = 0; i < cadena.size(); ++i) {
      push_symbol = cadena[i];
      sim_cadena_.push_back(push_symbol);
      length_++;
    }
  }
  alpha_.GetAlpha();
  std::cout << std::endl;
}
