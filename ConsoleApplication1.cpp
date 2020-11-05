#include "Lista.h"
#include "ListaSformatowana.h"
#include <iostream>
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
		//zbędne stałe w tym kontekście ale niech pozostaną
		constexpr auto WERSJA_SUMY_KONTROLNEJ = 'w';
    //stara wersja a la C: #define  WERSJA_SUMY_KONTROLNEJ 's'
		cout << "Podaj napis: " << endl;
		string lancuch;
		cin >> lancuch;
		unsigned char sigma = 100;
		unsigned char licznik = 15;
       
		for (unsigned char ch : lancuch) {
			sigma ^= (ch + licznik);
			licznik += 17;   
		}
		cout << "Suma kontrolna wyliczona z użyciem klasy string to: " << (int)sigma << endl;
         // zadanie: napisać używając char *
		sigma = 100;
		licznik = 15;
		const char *wsk = lancuch.c_str();
		 //string powrot = (string)wsk; a tak się rzutuje vice versa 
		 // z niskopoziomowego char* na string
		while (*wsk) {
			sigma ^= (*wsk++ + licznik);
			licznik += 17;
		}
		cout << "Suma kontrolna z użyciem niskopoziomowego char* to: " << (int)sigma << endl;

//dodatkowe zadanie: 
		/*
		  Przy rzutowaniu obiektu lancuch do char* używamy jak wiadomo c_str().
		  Nieodzowne jest zastosowanie const gdyż zawartości lancuch nie
		  możemy zmieniać niskopoziomowo. 
		  Zadanie: zrobić jego kopię.
		*/
		//pierwsze podejście (nieelastyczne, bo zakładamy że lancuch
		//nie ma więcej niż 1000 znaków):
		char kopia[1000];
		char* kopia2;
		/* to jest sposób aby ,,rozwidlić'' kod programu na wesję kompilatora
		dla Visual (_MSC_VER jest zdefiniowana) i 
		wesję dla innych kompilatorów (gcc, clang) - wtedy
		_MSC_VER jest niezdefiniowana. Można także zdefiniować zmienną VISUAL:
#ifdef _MSC_VER
  #define VISUAL
#endif  */
#ifdef _MSC_VER
		auto ile = strlen(lancuch.c_str()) + 1;
		memcpy_s(kopia, ile, lancuch.c_str(), ile);
#else
		memcpy(kopia, lancuch.c_str(), strlen(lancuch.c_str()) + 1);
#endif
		cout << "Kopia niskopoziomowa łańcucha: " << kopia;
    };
	static void zadaniaZKlasAbstrakcyjnych() {
		//TODO:

	}
};
/*
  słowo virtual pozwala w C++ na tworzenie tak zwanych klas
  abstrakcyjnych.
*/


int main()
{
	do {
		cout << "Wybierz opcje:\n";
		cout << "1. Test klasy List\n";
		cout << "2. Obliczenie sumy kontrolnej lancucha\n";
		cout << "3. Klasy abstrakcyjne\n";
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
		case '3': {
			Zadania::zadaniaZKlasAbstrakcyjnych();
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
