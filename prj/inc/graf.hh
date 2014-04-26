#ifndef GRAF_HH
#define GRAF_HH
#include<vector>
#include<iostream>
#include"tablica_asocjacyjna.hh"
#include"stos.hh"
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
	stack_array<string> S;
	tablica_asocjacyjna<bool> tab;
	vector<tablica_asocjacyjna<int> > lista_incydencji;
public:
	graf():S(x2){}
	//graf(int il_wezlow){ lista_incydencji = new vector<vector<wierzcholek> >[il_wezlow];}
	void dodaj_wierzcholek();
	bool czy_sasiad(unsigned int id1, unsigned int id2);
	bool czy_sasiad(wierzcholek w1, wierzcholek w2);
	void sasiedztwo(wierzcholek w);
	void dodaj_wierzcholek(wierzcholek w);
	void dodaj_krawedz(unsigned int id1, unsigned int id2, unsigned int waga);
	void dodaj_krawedz(wierzcholek w1, wierzcholek w2, unsigned int waga);
	void sasiedztwo(unsigned int id);
	void usun_krawedz(unsigned int id1, unsigned int id2);
	void usun_krawedz(wierzcholek w1, wierzcholek w2);
	void usun_wierzcholek(unsigned int id);
	void usun_wierzcholek(wierzcholek w);
	void wypisz_liste();
	void wyczysc(){lista_incydencji.clear();}
	int przeszukaj_wezel(int id);
	void dfs();
};


#endif

