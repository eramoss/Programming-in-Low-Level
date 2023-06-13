#include "cstring"
#include "iostream"



class string {
  // representation
  public:
  struct Srep {
    char* s; // pointer to elements
    uint32_t size; // amount of characters
    uint32_t n; // counter of references

    Srep(uint32_t new_size, const char* p) {
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

    void assign(uint32_t new_size, const char* p) {
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
  Srep* rep;

  class Cref {

    /*
    * defined to get a reference to s[i]
    * string::operator[] returns a Cref when its not const
    * Cref is similar to char& except on Srep::copy()
    * /// copy on write
    */
    public:
    friend class string;
    string& s;
    uint32_t i;
    Cref(string& ss, uint32_t ii) : s(ss), i(ii) {
    }
    operator char() const {
      return s.read(i);
    }
    void operator = (char c) {
      s.write(i, c);
    }
  };

  class Range {
  }; // for exception

  string();
  string(const char* x);
  string(const string& x);
  string& operator=(const string& x);
  string& operator=(const char* x);
  ~string();

  string& operator+= (const string& y) {

    string temp = *this;
    temp.write(0, this->read(0)); // copy a literal string to discard old representation
    delete[] this->rep->s;
    this->rep->size = this->size() + y.size();
    this->rep->s = new char[this->size() - 1];
    strcpy(this->rep->s, temp.rep->s);
    strncat(this->rep->s, y.rep->s, y.size());


    return *this;
  }
  string& operator+= (const char* y) {
    uint32_t ySize = 0;
    for (uint32_t i = 0; y[i] != '\0'; ++i) {
      ySize++;
    }
    string temp = *this;
    temp.write(0, this->read(0)); // copy a literal string to discard old representation
    delete[] this->rep->s;
    this->rep->size = this->size() + ySize;

    this->rep->s = new char[this->size()];
    strcpy(this->rep->s, temp.rep->s);
    strncat(this->rep->s, y, ySize);


    return *this;
  }

  friend std::ostream& operator << (std::ostream& standard_output, const string& x) {
    standard_output << x.rep->s;
    return standard_output;
  }
  friend std::istream& operator >> (std::istream& standard_input, string& x) {
    char* buffer;
    uint16_t bufferSize = 1024;
    standard_input.getline(buffer, bufferSize);
    x = buffer;
    return standard_input;
  }

  friend bool operator == (const string& x, const char* y) {
    return strcmp(x.rep->s, y) == 0;
  }
  friend bool operator == (const string& x, const string& y) {
    return strcmp(x.rep->s, y.rep->s) == 0;
  }

  friend bool operator != (const string& x, const string& y) {
    return !strcmp(x.rep->s, y.rep->s) == 0;
  }
  friend bool operator != (const string& x, const char* y) {
    return !strcmp(x.rep->s, y) == 0;
  }



  void check(uint32_t i) const {
    if (i < 0 || rep->size <= i) throw Range();
  }
  char read(uint32_t i) const {
    return rep->s[i];
  }
  void write(uint32_t i, char c) {
    rep = rep->copy(); // just copy on write
    rep->s[i] = c;
  }

  Cref operator[] (uint32_t i) {
    check(i); return Cref(*this, i);
  }
  char operator[] (uint32_t i) const {
    check(i); return rep->s[i];
  }

  uint32_t size() const {
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
  /// share representation
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

string operator+(const string& x, const string& y) {
  string result = string();
  delete[] result.rep->s;
  result.rep->size = x.size() + y.size();
  result.rep->s = new char[result.size() - 1];
  strcpy(result.rep->s, x.rep->s);
  strncat(result.rep->s, y.rep->s, y.size());


  return result;
}
string operator+(const string& x, const char* y) {
  uint32_t ySize = 0;
  for (uint32_t i = 0; y[i] != '\0'; ++i) {
    ySize++;
  }

  string result = string();
  delete[] result.rep->s;
  result.rep->size = x.size() + ySize;

  result.rep->s = new char[result.size()];
  strcpy(result.rep->s, x.rep->s);
  strncat(result.rep->s, y, ySize);


  return result;
}



int main(int argc, char const* argv[]) {
  string x;
  std::cin >> x;


  string concat = x + "world";
  concat += " , im concatenating";
  std::cout << concat << std::endl;
  return 0;
}
