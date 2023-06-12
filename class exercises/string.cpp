#include "cstring"

class string {
  public:
  struct Srep; // representation
  Srep* rep;
  class Cref; // reference to char
  class Range {
  }; // for exception

  string();
  string(const char*);
  string(const string&);
  string& operator=(const string&);
  string& operator=(const char*);
  ~string();
};



string::string() {
  rep = new Srep(0, ""); // string default
}
string::string(const string& x) {
  x.rep->n++;
  rep = x.rep; // shared representation
}
string::~string() {
  if (--rep->n == 0) delete rep;
}

string& string::operator=(const string& x) {
  x.rep->n++;
  if (--rep->n == 0) delete rep;
  rep = x.rep;
  return *this;
}
string::string(const char* x) {
  rep = new Srep(strlen(x), x);
}
string& string::operator=(const char* x) {
  if (rep->n == 1) rep->assign(strlen(x), x);
  else {
    rep->n--;
    rep = new Srep(strlen(x), x);
  }
  return *this;
}


struct string::Srep {
  char* s; // pointer to elements
  int size; // amount of characters
  int n; // counter of references

  Srep(int new_size, const char* p) {
    n = 1;
    size = new_size;
    s = new char[size + 1]; /// the expression [size + 1] add one to the end for null(\0) at end of string
    strcpy(s, p);
  }

  ~Srep() {
    delete[] s;
  }

  Srep* copy() {
    if (n == 1) return this;
    n--;
    return new Srep(size, s);
  }

  void assign(int new_size, const char* p) {
    if (size != new_size) {
      delete[] s;
      size = new_size;
      s = new char[size + 1];
    }
    strcpy(s, p);

  }
  private: // private copys
  Srep(const Srep&);
  Srep& operator=(const Srep&);
};

