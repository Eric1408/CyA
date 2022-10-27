#include "analyzer.h"

void Analyzer::Build(std::string input, int pos) {
  std::regex expression_var("[^[:graph:]](int|double)\\s(\\w+(\\s=\\s\\d+)?)");
  std::regex expression_loop("\\s*[^\\w](for|while)");
  std::regex expression_main("int main");
  std::regex expression_comments("^\\s*(\\/\\/.*)");
  //std::regex expression_comments("^\\s*(\\/\\/.*)|^\\s*(\\/\\*)|^\\s*.*|^\\s*(\\*\\/)");
  std::regex expression_description("(\\/\\*\\*)|(^\\s\\*.*)");
  //std::regex descript_ini("^\\/\\*\\*");
  std::regex descript_ini("^\\s*\\/\\*\\*?");
  std::regex descript_end("\\s\\*\\/");
  //std::regex expression_comments(".*[^:](\\/\\/.*)");

  std::smatch matches;
  std::smatch aux;
  
  
  if (std::regex_search(input, matches, expression_var)) {
    variables_.emplace_back(matches, pos);
  } else if (std::regex_search(input, matches, expression_loop)) {
    loops_.emplace_back(matches, pos);
  } else if (std::regex_search(input, matches, expression_main)) {
    main_ = true;
  } else if (std::regex_search(input, matches, expression_comments)) {
    comments_.emplace_back(matches, pos);
  } else if (std::regex_search(input, matches, expression_description)) {
    if (std::regex_search(input, aux, descript_ini)) {
      descript_.Build(aux, pos);
    } else if (std::regex_search(input, aux, descript_end)) {
      descript_.Insert(aux, pos);
    } else {
      descript_.Insert(matches);
    }
  }
}

std::ostream& operator<<(std::ostream& out, const Analyzer& kAnaly) {
  out << "DESCRIPTION :\n" << kAnaly.descript_ << std::endl;
  
  out << "\nVARIABLES :\n";
  for (int i = 0; i < kAnaly.VarSize(); i++) {
    out << kAnaly.variables_[i] << std::endl;
  }
  
  out << "\nSTATEMENTS :\n";
  for (int i = 0; i < kAnaly.LoopSize(); ++i) {
    out << kAnaly.loops_[i] << std::endl;
  }
  
  out << "\nMAIN :\n";
  kAnaly.main_ ? out << "True\n" : out << "False\n";

  out << "\nCOMMENTS :\n";
  out << "[LINE " << kAnaly.descript_.GetInit() << "-" << kAnaly.descript_.GetEnd() << "] DESCRIPTION\n"; 
  for (int i = 0; i < kAnaly.CommentSize(); ++i) {
    out << kAnaly.comments_[i] << std::endl;   
  }
  
  return out;
}