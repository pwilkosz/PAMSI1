#ifndef SIMPLEX_HH
#define SIMPLEX_HH
#include<vector>
using namespace std;
class simplex{
	/*! \brief wektor zawierający elementy bazowe ukladu*/
	vector<int> baza;
	/*! \brief wektor zawierający elementy niebazowe ukladu*/
	vector<int> nie_baza;
	/*! \brief tablica reprezentująca uklad w postaci dopelnieniowej*/
	vector< vector <float> > uklad;
	/*! \brief koszty dla kazdej zmiennej */
	/*Z tego chyba zrezygnuje, lepiej miec koszty i postac dopelnieniowa w jednym miejscu*/
	vector<float> koszt;
public:
	/*! \brief konstruktor*/
	simplex(){}
	~simplex(){}
	/*! \brief metoda pelni role komunikacji z uzytkownikiem*/
	void interfejs();
	/*! \brief metoda szuka wsrod zbioru zmiennych niebazowych tej, ktora 
	mozna wykorzystac do obliczen, powinna ona miec nieujemny wspolczynnik funkcji celu
	\return zmienna niebazowa do wymiany ze zmienna bazowa
	*/
	int wez_zmienna_niebazowa();
	/*! \brief metoda wyznacza maksymalna wartosc zmiennej niebazowej, aby spelnic
	warunki brzegowe
	\return zmienna bazowa, ktora zamieniamy ze zmienna niebazowa
	*/
	float zmienna_bazowa_do_wymiany();
	/*! \brief zamienia zmienna bazowa i niebazowa zachowujac zbior rozwiazan dopuszczalnych
	\param [in] zm1 - numer zmiennej nie zawierajacej sie w bazie
	\param [in] zm2 - numer zmiennej zawierajacej sie w bazie
	\return true - gyd pomyslnie dokonano zamiany zmiennych bazowych i niebazowych, false w przeciwnym wypadku
	*/
	bool zamien(unsigned int zm1, unsigned int zm2);
	/*! \brief uaktuania uklad dopelnieniowy
	\param [in] id - indeks elementu, ktoremu przypisujemy "nowa" wartosc
	\param [in] temp - wektor zawierajacy wyrazenie opisujace wchodzaca zmienna niebazowa
		*/
	void wstaw(int id, vector<float> temp);
	void wypisz_uklad();
	/*! \brief wyznacza funkcje celu
	\return wartosc funkcji celu
	*/
	float Z();
	/*! \brief rozwiazuje uklad dopelnienipowy*/
	void rozwiaz();
};


#endif