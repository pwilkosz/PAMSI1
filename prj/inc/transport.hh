#ifndef TRANSPORT_HH
#define TRANSPORT_HH

#include<vector>
#include<iostream>

using namespace std;


class transport{
/*Pola prywatne*/
int il_fabr;
int il_centr;
/*! \brief potencjal centra dystryucji*/
vector <bool> v;
/*! \brief potencjal fabryki*/
vector <bool> u;
vector <vector<int> > macierz_kosztow;
vector <vector<int> > macierz_sciezek;
vector <vector<int> > macierz_optymalizacji;
/*Pola publiczne*/
public:
transport(int il_fabryk, int il_centrow, vector<int> &dane){
	il_fabr = il_fabryk;
	il_centr = il_centrow;
	vector<int> vec;
	for(int i = 0; i<=il_fabryk; i++){
		macierz_kosztow.push_back(vec);
		macierz_sciezek.push_back(vec);
		macierz_optymalizacji.push_back(vec);
	}
	
	for(int i = 0; i<il_fabryk; i++){
		for(int k = 0; k<il_centrow; k++)
		macierz_kosztow.at(i).push_back(dane.at(i*il_fabryk + k));
	}
	for(int i = 0; i<il_fabryk; i++){
		macierz_kosztow.at(i).push_back(dane.at(il_fabryk*il_centrow + i));
	}
	
	for(int i = 0; i<il_centrow; i++){
		macierz_kosztow.at(il_fabryk).push_back(dane.at(il_fabryk*il_centrow + il_fabryk + i));
	}
	macierz_kosztow.at(il_fabryk).push_back(0);
	
	for(int i = 0; i<=il_fabryk; i++)
		for(int k = 0; k<=il_centrow; k++){
			macierz_sciezek.at(i).push_back(0);
		}
	for(int i = 0; i<=il_fabryk; i++)
		for(int k = 0; k<=il_centrow; k++){
			macierz_optymalizacji.at(i).push_back(0);
		}
	for(int i = 0; i<il_centrow; i++)
		v.push_back(false);
	for(int i = 0; i<il_fabryk; i++)
		u.push_back(false);	
}

void pierwsze_rozw_bazowe();

/*! \brief szuka najmnijeszego elementu w macierzy, zwraca jego pozycje.*/
int spr_mac_opt();

void wypisz_mac_koszt();

void wypisz_mac_sc();

void wypisz_mac_opt();

bool wyznacz_mac_opt(int fabryka, int centrum);

void uzupelnij_mac_opt();

};


/*! \brief metoda zbiera dane, aby uruchomic algorytm optymalizacyjny.
	Jest to zrobione inaczej, niż w przypadku algorytmu simplex celem ewentualnego stworzenia GUI
*/
void zbierz_dane();

#endif