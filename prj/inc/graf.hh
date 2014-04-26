#ifndef GRAF_HH
#define GRAF_HH
#include<vector>
#include<iostream>
#include"tablica_asocjacyjna.hh"
using namespace std;

class graf;
class wierzcholek{
	friend class graf;
private:
	int id;
	int waga;
public:
	wierzcholek(int wz, int wg):id(wz), waga(wg) {}
};

class graf{
	/*atrybuty prywatne*/
	vector<tablica_asocjacyjna<int> > lista_incydencji;
public:
	graf(){}
	//graf(int il_wezlow){ lista_incydencji = new vector<vector<wierzcholek> >[il_wezlow];}
	bool czy_sasiad(unsigned int id1, unsigned int id2);
	bool czy_sasiad(wierzcholek w1, wierzcholek w2);
	void sasiedztwo(wierzcholek w);
	void dodaj_wierzcholek(wierzcholek w);
	void dodaj_krawedz(unsigned int id1, unsigned int id2, unsigned int waga);
	void dodaj_krawedz(wierzcholek w1, wierzcholek w2, unsigned int waga);
	void sasiedztwo(unsigned int id);
	void usun_krawedz(wierzcholek w1, wierzcholek w2);
	void usun_wierzcholek(wierzcholek w);
	void wypisz_liste();
};


#endif

