﻿// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Lista.h"
#include "ListaSformatowana.h"
using namespace std;

class Zadania {
  public:
    static void zadaniaZProgObiektowego() {
		  cout << "wypisanie z klasy lista----------------------\n";
		  //obiekt jako zmienna lokalna
		  Lista li1(10);
		  li1.wypisanie();

		  cout << "wypisanie z klasy lista----------------------\n";
		  
		  //wskaźnik na obiekt
		  Lista* li2 = new Lista(10);
		  li2->wypisanie();
		  delete li2;
		  
		  cout << "uzycie listy sformatowanej----------------------\n";

		  // użycie listy sformatowanej
		  ListaSformatowana* lf = new ListaSformatowana(10);
		  lf->wypisanie();
		  delete lf;
    };
    static void zadaniaZeWskaznikow() {
// wersja na klasie string:
       constexpr auto WERSJA_SUMY_KONTROLNEJ = 's';
    //stara wersja a la C: #define  WERSJA_SUMY_KONTROLNEJ 's'
       cout << "Podaj napis: " << endl;
       string lancuch;
       cin >> lancuch;
       unsigned char sigma = 100;
       unsigned char licznik = 15;
       
       if (WERSJA_SUMY_KONTROLNEJ == 's') {       
         for (unsigned char ch : lancuch) {
           sigma ^= (ch + licznik);
           licznik += 17;   
         }
       } else if (WERSJA_SUMY_KONTROLNEJ == 'w') {
         // zadanie: napisać używając char *
         const char *wsk = lancuch.c_str();
         
       }  

       cout << "Suma kontrolna to: " << (int)sigma << endl;
    };
};

int main()
{
	do {
	  cout << "Wybierz opcje:\n";
	  cout << "1. Test klasy List\n";
	  cout << "2. Obliczenie sumy kontrolnej lancucha\n";
	  cout << "0. Koniec\n";
	  string txt;
	  cin >> txt;
	  if (txt.empty() || txt[0] == '0') break;
	  switch (txt[0]) {
	    case '1': {
		    Zadania::zadaniaZProgObiektowego();
        break;
	    }
		  case '2': {
			  Zadania::zadaniaZeWskaznikow();
        break;
	  	}
		  default:
			  break;
		}
	  } while (true);
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
