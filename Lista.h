#pragma once
#define WER_Z_KLAWIATURY 'w'
#define WER_DNI_TYGODNIA 't'
#include <vector>
#include <string>
using namespace std;
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


