#include <iostream>
#include <string>
#include <map>
double number_value;
std::string string_value;
std::map<std::string, double> table;

double prim(bool get);

typedef enum Token_value{
  NAME, NUMBER, END,
  PLUS='+' , MINUS='-' , MUL='*' , DIV='/' ,
  IMPR=';', ATT='=', BRACK_L='(', BRACK_R=')',

} Token_value;
Token_value curr_token = IMPR;




Token_value get_token(){
  char ch = 0;
  std::cin >> ch;

  switch (ch)
  {
    case 0:
      return curr_token = END;

    case ';': case '*': case '/': case '+': case '-': case '(': case ')': case '=':
      return curr_token = Token_value(ch);

    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':
      std::cin.putback(ch);
      std::cin >> number_value;
      return curr_token = NUMBER;

    default:
      if (isalpha(ch)) {
        std::cin.putback(ch);
        std::cin >> string_value;
        return curr_token = NAME;
      }
      throw std::runtime_error("invalid character token");
      return curr_token = IMPR;
  }
}


double term(bool get){
  double esq = prim(get);
  
  while(1){
    switch(curr_token){
      case MUL: {
        esq *= prim(true);
        break;
      }
        
      case DIV:{
        if(double d = prim(true)){
          esq /= d;
          break;
        }
        throw std::runtime_error("invalid division: The divisor is NULL");
      }
        
      default: 
        return esq;
    }
  }
}



double expr(bool get){
  double esq = term(get);

  while(1){
    switch(curr_token) {
      case PLUS:{
        esq += term(true);
        break;
      }
        
      case MINUS:{
        esq -= term(true);
        break;
      }
        
      default:
        return esq;
    }
      
  }
}


double prim(bool get){
  if (get) get_token();

  switch (curr_token){
    case NUMBER:
    {
      double v = number_value;
      get_token();
      return v;

    }
      
    case NAME:{
      double & v = table[string_value];
      if (get_token() == ATT) v = expr(true);
      return v;
    }
      
    case MINUS: {
      return -prim(true);
    }
      
    case BRACK_L:{
      double e = expr(true);
      if (curr_token != BRACK_R) throw std::runtime_error("expected bracket \")\"");
      get_token();
      return e;
    }
      
    default:
      throw std::runtime_error("expected primary expression");
  }
}






int main(int argc, char const *argv[])
{
  std::cout << "Put the arithmetic expression:\n";
  std::cout << expr(true) << std::endl;
  return 0;
}
