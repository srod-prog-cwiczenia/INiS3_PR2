#pragma once
#include "define.h"
class Lista
{
private:
    vector<string> vec;
public:
	Lista(int ile);
	Lista(char wersja);//'w' - wczytaj z klawiatury, 't' - dni tygodnia
	~Lista();
	void wypisanie();
	virtual string format(string txt_p);
};


