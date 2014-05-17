#ifndef GRAF_HH
#define GRAF_HH
#include<vector>
#include<iostream>
#include"tablica_asocjacyjna.hh"
#include"stos.hh"
#include"kolejka.hh"
using namespace std;
/*! \file
	Plik zawiera definicje klasy wierzcholek i klasy graf
*/
class graf;
/*! \brief
	Klasa modeluje pojecie wierzcholka grafu. Nie jest to implementacja konieczna, aczkolwiek pozwala na 
	dwojakie interpertowanie wierzcholka grafu, wedle zyczen uzytkownika
*/
class wierzcholek{
	/*! \brief klasa zparzyjazniona*/
	friend class graf;
private:
	/*! \brief numer indentyfikacyjny wierzcholka*/
	int id;
	/*! \brief waga wezla, uzywana w stosunku do wierzcholka, z ktorym ow wierzcholek jest incydentny*/
	int waga;
public:
	/*! \brief konstruktor 
	\param [in] wz - id wierzcholka
	\param [in] wg - waga 
	*/
	wierzcholek(int wz, int wg):id(wz), waga(wg) {}
};
/*! \brief 
	Klasa modeluje pojecie grafu w oparciu o liste incydencji, Operacje na grafie mozliwe sa na dwa sposoby \\n
	1. Podajac wierzcholek grafu jako parametr metody \\n
	2. Podajac id wierzcholka jako parametr metody
*/
class graf{
	/*atrybuty prywatne*/
	
	//queue_array<string> Q0;
	/*! \brief przechowuje sciezke w algorytmach dfs, bfs oraz best - first*/
	stack_array<int> Q;
	/*! \brief wspolrzedna x-owa wierzcholka grafu*/
	vector<int> w_x;
	/*! \brief wspolrzedna y-owa wierzcholka grafu*/
	vector<int> w_y;
	/*! \brief wektor, ktory zawiera sciezke w algorytmie A**/
	vector<int> poprzednik;
	/*! \brief dystans wierzcholka od zadanego wezla zrodlowego*/
	vector<int> dist;
	/*! \brief estymacja odleglosci do celu w oparciu o metrykę typu Manhattan*/
	vector<int> est;

	//tablica_asocjacyjna<bool> tab2;
	/*! \brief struktura sluzaca do przechowywania grafu, zawiera informacje, czy wierzcholek byl odwiedzony*/
	tablica_asocjacyjna<bool> tab;
	/*! \brief lista incydencji grafu*/
	vector<tablica_asocjacyjna<int> > lista_incydencji;
public:
	/*! \brief Konstruktor nieparametryczny - ustala sposob zarzadzania pamiecia na stosie*/
	graf():Q(x2){}
	/*! \brief Dodaje wierzcholek do wezla, wierzcholkom przypisuje sie identyfikatory bedace kolejnymi liczbami naturalnymi.
	Dodany wierzcholek nie posiada krawedzi incydentnych
	*/
	void dodaj_wierzcholek();
	/*! \brief Sprawdza czy podane wierzcholki sa polaczone krawedzia - odwolanie poprzez identyfikatory
	\param [in] id1 - id 1. wierzcholka
	\param [in] id2 - id 2. wierzcholka
	\return true - gdy sa sasiadami, false - gdy nie sa
	*/
	bool czy_sasiad(unsigned int id1, unsigned int id2);
	/*! \brief Sprawdza czy podane wierzcholki sa polaczone krawedzia - odwolanie poprzez obiekt klasy wierzcholek
	\param [in] w1 - pierwszy wierzcholek
	\param [in] w2 - drugi wierzcholek
	\return true - gdy sa sasiadami, false - gdy nie sa
	*/
	bool czy_sasiad(wierzcholek w1, wierzcholek w2);
	/*! \brief wypisuje wszystkie wierzcholki polaczone krawedzia z podanym wierzcholkiem - odwolanie poprzez obiekt typu wierzcholek
	\param [in] w - zadany wierzcholek
	*/
	void sasiedztwo(wierzcholek w);
	/*! \brief Dodaje wierzcholek do grafu, metoda dedykowana do algorytmu A* - algorytm ustawia wezly grafu na siatce, nadajac 
	im jednoczesnie wspolrzedne kartezjanskie
	\param [in] id - id wierzcholka, wg ktorego wyliczamy jego wspolrzedne
	*/
	void dodaj_wierzcholek(int id);
	/*! \brief Dodaje wierzcholek do wezla, wierzcholkom przypisuje sie identyfikatory bedace kolejnymi liczbami naturalnymi.
	Dodany wierzcholek nie posiada krawedzi incydentnych
	*/
	void dodaj_wierzcholek(wierzcholek w);
	/*! \brief dodaje krawedz pomiedzy zadane wierzcholki. Waga krawedzi jest wyznaczana w sposob losowy. Najkrotsza odlegloscia miedzy wezlami,
	jest odleglosc wezlow w sensie metryki typu Manhattan
	\param [in] id1 - id pierwszego wezla
	\param [in] id2 - id drugiego wezla
	*/
	void dodaj_krawedz(unsigned int id1, unsigned int id2);
	/*! \brief Dodaje krawedz o wadze waga pomiedzy 2 wezly - odwolanie poprzez identyfikatory wierzcholkow
	\param [in] id1 - id 1. wierzcholka
	\param [in] id2 - id 2. wierzcholka
	\param [in] waga - waga krawedzi
	*/
	void dodaj_krawedz(unsigned int id1, unsigned int id2, unsigned int waga);
	/*! \brief Dodaje krawedz o wadze waga pomiedzy 2 wezly - odwolanie poprzez obiekty typu wierzcholek
	\param [in] w1 - pierwszy wierzcholek
	\param [in] w2 - drugi wierzcholek
	\param [in] waga - waga krawedzi
	*/
	void dodaj_krawedz(wierzcholek w1, wierzcholek w2, unsigned int waga);
	/*! \brief wypisuje wszystkie wierzcholki polaczone krawedzia z podanym wierzcholkiem - odwolanie poprzez identyfikator wierzcholka
	\param [in] id - id wierzcholka
	*/
	void sasiedztwo(unsigned int id);
	/*! \brief usuwa krawedz spomiedzy 2 wierzcholkow - odwolanie poprzez identyfikatory wierzcholkow
	\param [in] id1 - id 1. wierzcholka
	\param [in] id2 - id 2. wierzcholka
	*/
	void usun_krawedz(unsigned int id1, unsigned int id2);
		/*! \brief usuwa krawedz spomiedzy 2 wierzcholkow - odwolanie poprzez obiekt typu wierzcholek
		\param [in] w1 - pierwszy wierzcholek
		\param [in] w2 - drugi wierzcholek
		*/
	void usun_krawedz(wierzcholek w1, wierzcholek w2);
	/*! \brief usuwa podany wierzcholek, a scislej, ustawia flage w strukturze tablicy asocjacyjnej, przez co dany wierzcholek jest niewidoczny dla 
	uzytkownika
	\param [in] id - id wierzcholka
	*/
	void usun_wierzcholek(unsigned int id);
	/*! \brief usuwa podany wierzcholek, a scislej, ustawia flage w strukturze tablicy asocjacyjnej, przez co dany wierzcholek jest niewidoczny dla 
	uzytkownika
	\param [in] w - wierzcholek ktory trzeba usunac
	*/
	void usun_wierzcholek(wierzcholek w);
	/*! \brief wypisuje pelna liste incydencji grafu*/
	void wypisz_liste();
	/*! \brief usuwa wszystkie obiekty z listy inceydencji grafu*/
	void wyczysc(){lista_incydencji.clear();}
	/*! \brief Jeżeli wezel nei byl odwiedzony, odklada na stos wszystkie jego nieodwiedzone nastepniki i rekurencyjnie je przeszukuje
	\param [in] id - id wezla, ktory ma byc przeszukany
	\param [in] wzor - id wezla, ktorego szukamy
	\return informacja, czy wezel zostal znaleziony
	*/
	bool przeszukaj_wezel(int id, int wzor);
	/*! \brief Metoda przeszukuje wglab caly graf 
	\param [in] id - wezel, ktorego szukamy
	 */
	void dfs(int id);
	/*! \brief Jeżeli wezel nei byl odwiedzony, odklada do kolejki wszystkie jego nieodwiedzone nastepniki i rekurencyjnie je przeszukuje
	\param [in] id - id wezla, ktory ma byc przeszukany
	\param [in] wzor - id wezla, ktorego szukamy
	\return informacja, czy wezel zostal znaleziony
	*/
	bool przeszukaj_wezel_1(int id, int wzor);
	/*! \brief Metoda przeszukuje wszerz caly graf 
	\param [in] id - wezel, ktorego szukamy
	 */
	void bfs(int id);
	/*! \brief Jeżeli wezel nei byl odwiedzony, odklada do tablicy asocjacyjnej wszystkie jego nieodwiedzone nastepniki i rekurencyjnie je przeszukuje,
	poczynajac od tego, do ktorego mamy najkrotsza sciezke
	\param [in] id - id wezla, ktory ma byc przeszukany
	\param [in] wzor - id wezla, ktorego szukamy
	\return informacja, czy wezel zostal znaleziony
	*/
	bool przeszukaj_wezel_2(int id, int wzor);
	/*! \brief Metoda przeszukuje graf, poczynajac od najkrotszej sciezki 
	\param [in] id - wezel, ktorego szukamy
	 */
	void best_first(int id);
	/*! \brief Metoda przeszukuje wyszukuje zadany element grafu w mysl algorytmu A*.
		\param [in] id - id wezla zrodlowego
		\param [in] wzor - wezel docelowy
	*/
	void a_star(int id, int wzor);

	void rysuj();


};	



#endif

