#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <cstdarg>
#include <cassert>

using namespace std;

/*wersja sposobu wype�niania obiektu klasy Lista (modu� Lista.cpp)*/
#define WER_Z_KLAWIATURY 'w'
#define WER_DNI_TYGODNIA 't'

/*sprawdzanie czy kompilujemy pod MS Visual Studio : */
#ifdef _MSC_VER
  #define VISUAL
#endif
