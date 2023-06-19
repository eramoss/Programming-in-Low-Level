#include <map>
#include <iostream>

template <class T> class string {
public:
  struct Srep;
  Srep* rep;


  string();
  string(const T*);
  string(const string*);

  T read(int i) const;

};

/**
 * @class string
 * Example:
 * string<unsigned char>;
 * string<wchar_t>;
 *
 * class japanese_characters{
 * ...
 * }
 *
 * string<japanese_characters>;
 *
 * //////////////////////////////
 * [string<char>;] do the same thing as string descript in ./string.cpp
 *
*/
