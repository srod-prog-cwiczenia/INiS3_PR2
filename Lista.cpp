#include "Lista.h"
Lista::Lista(int ile) {

	for (int i = 0; i < ile; i++)
	  vec.push_back(to_string(i));
	  //vec.push_back("" + i); //nie dzia³a bo "" jest typu char*
}
Lista::Lista(char wersja)
{
}
//-------------------------------------------------------
Lista::~Lista() {
	//jest to destruktor
}

void Lista::wypisanie()
{
	for (string txt : vec) {
		cout << format(txt) << endl;
	}
}

string Lista::format(string txt_p)
{
	return txt_p;
}
