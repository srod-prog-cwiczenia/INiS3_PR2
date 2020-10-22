﻿// ConsoleApplication1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "Lista.h"
#include "ListaSformatowana.h"
using namespace std;
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
		  break;
	    }
		case '2': {
			//TODO: opcja 2 do uzupełnienia
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
