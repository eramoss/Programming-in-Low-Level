#include "cstring"

typedef struct Srep {
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
} Srep;


class Cref {
  public:
  friend class string;
  string& s;
  int i;
  Cref(string& ss, int ii) : s(ss), i(ii) {
  }
  operator char() const {
    return s.read(i);
  }
  void operator = (char c) {
    s.write(i, c);
  }
};




class string {
  public: // representation
  Srep* rep;
  class Range {
  }; // for exception

  string();
  string(const char*);
  string(const string&);
  string& operator=(const string&);
  string& operator=(const char*);
  ~string();



  void check(int i) const {
    if (i < 0 || rep->size <= i) throw Range();
  }
  char read(int i) const {
    return rep->s[i];
  }
  void write(int i, char c) {
    rep = rep->copy();
    rep->s[i] = c;
  }

  Cref operator[] (int i) {
    check(i); return Cref(*this, i);
  }
  char operator[] (int i) const {
    check(i); return rep->s[i];
  }

  int size() const {
    return rep->size;
  }
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

