// This is the "header" file of the library
// It just declares the interface (types, functions, etc.)

// To avoid importing a library twice the we can make use
// of so-called conditional compilation directives
// the idea is to use a unique name to identify the library
#ifndef __my_sweet_library__
#define __my_sweet_library__

// A library, can of course need other libraries
#include <string>
#include "live02-my_sweet_library.cpp"

using namespace std;

// This library just offers some simple functions
string sweet(string s);
string cool(string s);
string weird(string s);

#endif
