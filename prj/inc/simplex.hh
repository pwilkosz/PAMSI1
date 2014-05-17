#ifndef SIMPLEX_HH
#define SIMPLEX_HH
#include<vector>
using namespace std;
class simplex{
	/*! \brief wektor zawierający elementy bazowe ukladu*/
	vector<int> baza;
	/*1 \brief wektor zawierający elementy niebazowe ukladu*/
	vector<int> nie_baza;
	/*! \brief tablica reprezentująca uklad w postaci dopelnieniowej*/
	vector< vector <float> > uklad;
	/*! \brief koszty dla kazdej zmiennej */
	/*Z tego chyba zrezygnuje, lepiej miec koszty i postac dopelnieniowa w jednym miejscu*/
	vector<float> koszt;
public:
	simplex(){}
	~simplex(){}
	/*! \brief metoda pelni role komunikacji z uzytkownikiem*/
	void interfejs();
	/*! \brief metoda szuka wsrod zbioru zmiennych niebazowych tej, ktora 
	mozna wykorzystac do obliczen, powinna ona miec nieujemny wspolczynnik funkcji celu*/
	int wez_zmienna_niebazowa();
	/*! \brief metoda wyznacza maksymalna wartosc zmiennej niebazowej, aby spelnic
	warunki brzegowe*/
	float zmienna_bazowa_do_wymiany();
	/*! \brief zamienia zmienna bazowa i niebazowa zachowujac zbior rozwiazan dopuszczalnych*/
	bool zamien(unsigned int zm1, unsigned int zm2);
	void wstaw(int id, vector<float> temp);
	void wypisz_uklad();
	/*! \brief wyznacza funkcje celu*/
	float Z();
	/*! \brief rozwiazuje uklad dopelnienipowy*/
	void rozwiaz();
};


#endif