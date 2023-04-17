#include <iostream>
#include <string>
#include <map>

double number_value;
std::string string_value;
std::map<std::string, double> table;

double prim(bool get); // pre assignment functions
double term(bool get);
double expr(bool get);

int errors_amount;
double error(const std::string& s){
  errors_amount ++;
  std::cerr << s << std::endl;
  return 1;
}

typedef enum Token_value{
  NAME, NUMBER, END,
  PLUS='+' , MINUS='-' , MUL='*' , DIV='/' ,
  IMPR=';', ATT='=', BRACK_L='(', BRACK_R=')',

} Token_value;
Token_value curr_token = IMPR;




Token_value get_token(){
  char ch;
  do {
    if (!std::cin.get(ch)) return curr_token = END;
  } while (ch != '\n' && isspace(ch));
  switch (ch)
  { 
    case 0:
      return curr_token = END;
    case ';': case '\n':
      return curr_token = IMPR;
    case '*': case '/': case '+': case '-': case '(': case ')': case '=':
      return curr_token = Token_value(ch);

    case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '.':
      std::cin.putback(ch);  // case ch is a number, put the ch value on number value and return current token as a NUMBER.
      std::cin >> number_value;
      return curr_token = NUMBER;

    default: {
      if (isalpha(ch)) {
        string_value = ch;
        while( std::cin.get(ch) && isalnum(ch)) string_value.push_back(ch); 
        std::cin.putback(ch);
        if(string_value == "clear") system("clear");
        return curr_token = NAME;
      }
      error("invalid character token");
      return curr_token = IMPR;
    }
  }
}

double prim(bool get){
  if (get) get_token();

  switch (curr_token){
    case NUMBER:{
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
      if (curr_token != BRACK_R) error("expected bracket \")\"");
      get_token();
      return e;
    }
      
    default:
      return error("expected primary expression");
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
        return error("invalid division: The divisor is NULL");
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



int main(int argc, char const *argv[])
{
  table["pi"] = 3.1315926535897932385;
  table["e"] = 2.7182818284590452354;
  while(std::cin) {
    get_token();
    if(curr_token == END) break;
    if(curr_token == IMPR) continue;
    std::cout << expr(false) << "\n";
  }
  return errors_amount;
}
