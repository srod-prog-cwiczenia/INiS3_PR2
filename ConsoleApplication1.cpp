#include "Lista.h"
#include "ListaSformatowana.h"
#include "TMenu.h"

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
		auto ile = strlen(lancuch.c_str()) + 1;
#ifdef VISUAL
		memcpy_s(kopia, ile, lancuch.c_str(), ile);
#else
		memcpy(kopia, lancuch.c_str(), strlen(lancuch.c_str()) + 1);
#endif
		cout << "Kopia niskopoziomowa łańcucha: " << kopia << endl;

		/*zadanie; zaalokować pamięć do zmiennej kopia2 przez
		  instrukcję malloc. Zwróćmy uwagę że malloc
		  tworzy tak zwany ,,wskaźnik generyczny'', czyli 
		  taki ,,uniwersalny wskaźnik'', void *,
		  więc aby postawić go pod typowany wskaźnik kopia2
		  należy użyć rzutowania (char*)
		  */
		kopia2 = (char*) malloc(strlen(lancuch.c_str()) + 1);
#ifdef VISUAL
		memcpy_s(kopia2, ile, lancuch.c_str(), ile);
#else
		memcpy(kopia2, lancuch.c_str(), strlen(lancuch.c_str()) + 1);
#endif
		cout << "Kopia niskopoziomowa łańcucha: " << kopia2 << endl;
		free(kopia2);
    };
	static void zadaniaZKlasAbstrakcyjnych() {
		/*
		  w C++ rolę interfejsów pełnią tak zwane klasy 
		  abstrakcyjne. Klasa abstrakcyjna to klasa która
		  nie posiada instancji, czyli nie można utworzyć
		  obiektu o typie tej klasy.
		*/
		/*zadanie: utworzyć klasę Menu do obsługi menu.
		interface tej klasy wyglądać może tak: */
		class TMenuAbs {  //to jest klasa abstrakcyjna (bo zawiera 
	//konstrukcje postaci: virtual ... = 0;
		public:
			virtual void addAll(int ilePar, ...) = 0;
			virtual unsigned int wybierz() = 0;
			TMenuAbs() {};
			virtual ~TMenuAbs() {};
			/*
			  implementacja tego interfejsu powinna funkcjonować tak:
				TMenu* mnu = new TMenu();
				mnu->addAll(2, "Opcja 1", "Opcja 2");
				  (automatyczna numeracja + 0. Wyjscie).
				auto opcja = mnu->wybierz();
				delete mnu;
			*/
		};
	}
};
/*
  słowo virtual pozwala w C++ na tworzenie tak zwanych klas
  abstrakcyjnych.
*/


int main()
{
	bool koniec = false;
	do {
		TMenu mnu;
		mnu.addAll(3, "Test klasy List",
			"Obliczenie sumy kontrolnej lancucha",
			"Klasy abstrakcyjne");
		switch (mnu.wybierz()) {
		case 1: {
			Zadania::zadaniaZProgObiektowego();
			break;
		}
		case 2: {
			Zadania::zadaniaZeWskaznikow();
			break;
		}
		case 3: {
			Zadania::zadaniaZKlasAbstrakcyjnych();
			break;
		}
		default:
			koniec = true;
			break;
		}
	} while (!koniec);
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
