#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <cstdarg>
#include <cassert>

using namespace std;

/*wersja sposobu wype³niania obiektu klasy Lista (modu³ Lista.cpp)*/
#define WER_Z_KLAWIATURY 'w'
#define WER_DNI_TYGODNIA 't'

/*sprawdzanie czy kompilujemy pod MS Visual Studio : */
#ifdef _MSC_VER
  #define VISUAL
#endif
