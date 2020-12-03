#include "Lista.h"
#include "ListaSformatowana.h"
#include "TMenu.h"
class Zadania {
  public:
	  struct DaneOsoby { //klasa (tak naprawdę struktura) wewnętrzna klasy Zadania.
		  string imie, nazwisko;
		  unsigned int wiek;
		  DaneOsoby(string imie_p, string nazwisko_p, unsigned int wiek_p) :
			  imie(imie_p), nazwisko(nazwisko_p), wiek(wiek_p) {};
		  //przeładowanie operatorów rzutowania:
		  operator string() const { return imie + " " + nazwisko + " " + to_string(wiek); };
		  operator int() const { return wiek; };
		  bool operator !() const { return imie.empty() && nazwisko.empty() && !wiek; };
		  /*!wiek to skrót na (wiek == 0)*/
		  //przeładowanie operatorów porównania:
		  bool operator == (const DaneOsoby& a) {
			  return imie == a.imie && nazwisko == a.nazwisko && wiek == a.wiek;
		  };
		  bool operator != (const DaneOsoby& a) {
			  return !(*this == a);
		  };
		  /*pierwszy sposób na przeładowanie < może być
		  * używany przy porównaniach postaci oso1 < oso2, ale
		  * nie funkcjonuje w kolekcjach
		  */
		  bool operator < (const DaneOsoby& a) {
			  if (nazwisko < a.nazwisko) return true;
			  if (nazwisko > a.nazwisko) return false;
			  if (imie < a.imie) return true;
			  if (imie > a.imie) return false;
			  if (wiek < a.wiek) return true;
			  return false;
		  }
		  /*
		  drugi sposób na przeładowanie <, funkcjonuje w kolekcjach,
		  może być używany też zamiast powyższego (czyli go zastępuje)
		  */
		  friend bool operator < (const DaneOsoby& a, const DaneOsoby& b) {
			  if (a.nazwisko < b.nazwisko) return true;
			  if (a.nazwisko > b.nazwisko) return false;
			  if (a.imie < b.imie) return true;
			  if (a.imie > b.imie) return false;
			  if (a.wiek < b.wiek) return true;
			  return false;
		  };
	  };
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
		cout << "Zadanie wykonane - klasa abstrakcyjna TMenuAbs zaimplementowana\n"
			"w module TMenu\n";
	}

	static void testyJednostkoweZPrzeladowywaniaOperatorow() {
		/*
		1. należy zdefiniować strukturę DaneOsoby zawierajacą:
		string imie, nazwisko;
		unsigned int wiek;
		2. należy przedefiniować (=przeciążyć = przeładować)
		jak najwięcej operatorów, np.
		< > <= >= == != + += ! itd.itd
		a także operator rzutowania (string)
		UWAGA: Aby można było przeciążyć operatory na przypadek
		tej struktury trzeba ją zdefiniować nie w tym miejscu
		ale np. jako klasę wewnętrzną klasy Zadania.
		*/
		DaneOsoby oso1("Adam", "Kowalski", 25);
		DaneOsoby oso2 = {"Anna", "Kowalska", 22};
		DaneOsoby oso3 = oso1;
		oso3.wiek = 30;//to nie zmienia zawartości oso1
		// test dla operatora (string):
		cout << ":Osoba 1: " << (string)oso1 << endl;
		//test dla operatora ! :
		assert(!oso1 == false); //albo już zupełnie skrótowo:
		assert(!!oso1); //...gdzie pierwszy wykrzyknik oznacza negację boolowską,
		// drugi wykrzynik to oczywiście przeładowanie operatora ! na strukturę DaneOso
		assert(!DaneOsoby( "", "", 0 ));
		//testy jednostkowe dla == i != i (int)
		assert(oso1 != oso2);
		assert(oso1 == DaneOsoby("Adam", "Kowalski", 25));
		assert((int)oso1 == 25);
		// testy jednostkowe dla < :
		assert(oso2 < oso1);
		cout << "Testy przeszły poprawnie\n";
	}
	static void przeladowaniePorownaniaASTL(const char& wersjaP = 's') { //tu parametr domyślny
		/*wersjaP == 'm' test map
		  wersjaP == 's' test set*/
		  /* zadanie: utworzyć kolekcję set<DaneOsoby>, dodać
		  kilka osób do niej (w tym spróbować dodac zdublowaną) a potem
		  je wypisać*/
		DaneOsoby tabOsob[] = { {"Dorota", "Nowak", 20},
		{"Andrzej", "Nowak", 40},
		{"Adam", "Kowalski", 25},
		{"Adam", "Kowalski", 25},
		{"Anna", "Kowalska", 22} };
		switch (wersjaP) {
		case 's': case 'S': {
			/*lecz aby używać do struktury kolekcje set i map
			nieodzowne jest przeładowanie w strukturze operatora < bo
			STL musi mieć komparator który albo możemy podać mu jawnie
			bodajże w konstruktorze albo po prostu przeładowac < w strukturze */
			set<DaneOsoby> zOso;
			zOso.insert(DaneOsoby("Adam", "Kowalski", 25));
			for (const auto& oso : tabOsob) {
				zOso.insert(oso);
			}
			cout << "Zawartosc zbioru zOso to (petla): \n";
			for (const auto& oso : zOso) {
				cout << (string)oso << endl;
				/* ....ale zawartosc zOso okazala się być nieposortowana....
				bo nieodzowne jest użycie przeładowania friend...*/
			}
			/*wypisywanie przy użyciu iteratora: */
			cout << string(50, '=') << endl;
			cout << "Zawartosc zbioru zOso to (iterator): \n";
			for (auto ite = zOso.begin(); ite != zOso.end(); ite++)
				cout << (string)(*ite) << endl;
			break;
		}
		case 'm': {
			/*UWAGA: taka sama koniecznosc przeladowania operatora porownania <
	* dla struktury DaneOsoby zachodzi w przypadku kiedy
	* używamy std::map - map<DaneOsoby, double>
	* Przykład:
	*/
			map<DaneOsoby, double> mOsoKw; //Kw - kwota
			double kwota = 0.0;
			for (const auto& oso : tabOsob) {
				mOsoKw[oso] = (kwota += 1000.0);
			}
			cout << "\nWypisanie zawartosci mapy mOsoKw: \n";
			for (const auto& ele : mOsoKw) {
				cout << (string)ele.first << " -> " << ele.second << endl;
			}
			break;
		}
		}
	}
};
/*
  słowo virtual pozwala w C++ na tworzenie tak zwanych klas
  abstrakcyjnych.
*/

int main()
{
	bool koniec1 = false;
	do {
		TMenu mnu1;
		mnu1.addAll(4, "Test klasy List",
			"Obliczenie sumy kontrolnej lancucha",
			"Klasy abstrakcyjne", "Zadania z przeładowywania operatorów");
		switch (mnu1.wybierz()) {
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
		case 4: {
			bool koniec2 = false;
			do {
				TMenu mnu2;
				mnu2.addAll(3, "Testy przeladowania operatorow",
					"Zastosowanie przeladowania < do set<DaneOsoby>",
					"Zastosowanie przeladowania < do map<DaneOsoby, double>");
				switch (mnu2.wybierz()) {
				case 1:
					Zadania::testyJednostkoweZPrzeladowywaniaOperatorow();
					break;
				case 2:
					Zadania::przeladowaniePorownaniaASTL('s');
					break;
				case 3:
					Zadania::przeladowaniePorownaniaASTL('m');
					break;
				default:
					koniec2 = true;
					break;
				}
			} while (!koniec2);
			break;
		}
		default:
			koniec1 = true;
			break;
		}
	} while (!koniec1);
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
