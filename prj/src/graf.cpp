#include"graf.hh"
#include<sstream>
#include<cstdlib>
tablica_asocjacyjna<int> vec;

void graf::dodaj_wierzcholek(){
	lista_incydencji.push_back(vec);
	int rozm = lista_incydencji.size();
	ostringstream s; s<<(--rozm);
	cout<<s.str()<<endl;
	tab.dodaj(s.str(), false);
}

void graf::dodaj_wierzcholek(wierzcholek w){
	cout<<"dodjae"<<endl;
	lista_incydencji.push_back(vec);
	int rozm = lista_incydencji.size();
	ostringstream s; s<<(--rozm);
	cout<<s.str()<<endl;
	tab.dodaj(s.str(), false);
	cout<<"dodano"<<endl;
}

void graf::dodaj_krawedz(wierzcholek w1, wierzcholek w2, unsigned int waga){
	dodaj_krawedz(w1.id, w2.id, waga);
}

void graf::dodaj_krawedz(unsigned int id1, unsigned int id2, unsigned int waga){
	if((id1>lista_incydencji.size() && id2>lista_incydencji.size())|| lista_incydencji[id1].czy_blokada()||lista_incydencji[id2].czy_blokada()) cout<<"w grafie nie ma takich wierzchołków"<<endl;
	else{
		ostringstream s1, s2; s1<<id1; s2<<id2;
		lista_incydencji.at(id1).dodaj(s2.str(), waga);
		lista_incydencji.at(id2).dodaj(s1.str(), waga);
	}
}
void graf::sasiedztwo(unsigned int id){
	if(id<lista_incydencji.size() && !lista_incydencji[id].czy_blokada()){
		for(int i = 0;i < lista_incydencji[id].zlicz_elementy(); i++){
			
			cout<<"( "<<lista_incydencji[id].wez_id(i)<<", "<<lista_incydencji[id].wez(i)<<" ) "; 
		} cout<<endl;
	}
	else{cout<<"Zly indeks"<<endl;}
}
void graf::sasiedztwo(wierzcholek w){
	sasiedztwo(w.id);}


void graf::wypisz_liste(){cout<<"wypisuje"<<endl;
int licznik = 0;
	for(vector<tablica_asocjacyjna<int> >::iterator it = lista_incydencji.begin(); it!= lista_incydencji.end(); it++){
		if(it->czy_blokada()){++licznik; continue;}
		cout<<licznik<<": ";
		for(int i = 0;i < it->zlicz_elementy(); i++){
			
			cout<<"( "<<it->wez_id(i)<<", "<<it->wez(i)<<" ) "; 
		}
		cout<<endl;
		++licznik;}}

bool graf::czy_sasiad(unsigned int id1, unsigned int id2){
	if((id1>lista_incydencji.size() && id2>lista_incydencji.size())|| !lista_incydencji[id1].zlicz_elementy()) return false;
	else{
		ostringstream s2; s2<<id2;
		return lista_incydencji[id1].znajdz(s2.str());
	}
}
bool graf::czy_sasiad(wierzcholek w1, wierzcholek w2){
	return czy_sasiad(w1.id, w2.id);
}


void graf::usun_krawedz(unsigned int id1, unsigned int id2){
	cout<<"usun: "<<id1<<" "<<id2<<endl;
	if(id1>lista_incydencji.size() || id2>lista_incydencji.size()) cout<<"nie ma takich wezlow"<<endl;
	else{
		ostringstream s1, s2; s1<<id1; s2<<id2;
		lista_incydencji[id1].usun(s2.str());
		lista_incydencji[id2].usun(s1.str());
	}
}
void graf::usun_krawedz(wierzcholek w1, wierzcholek w2){
	usun_krawedz(w1.id, w2.id);
}
void graf::usun_wierzcholek(unsigned int id){
	if(id>lista_incydencji.size()) cout<<"nie ma takiego wezla"<<endl;
	else{
		lista_incydencji[id].zablokuj();
	}
}
void graf::usun_wierzcholek(wierzcholek w){
	usun_wierzcholek(w.id);
}

int graf::przeszukaj_wezel(int id){
	cout<<"Przeszukuje: "<<id<<endl;
	ostringstream s; s<<id;
	//jezeli nieodwiedzone
	
		tab.ustaw(s.str(), true);
		for(int i = lista_incydencji[id].zlicz_elementy() -1; i>=0; i--){ 
			if(lista_incydencji[atoi(lista_incydencji[id].wez_id(i).c_str())].czy_blokada()){ continue;}
			if(tab.pobierz(lista_incydencji[id].wez_id(i))) continue;
			cout<<"klade na stos: "<<lista_incydencji[id].wez_id(i)<<endl;
			S.push(lista_incydencji[id].wez_id(i));
			
		}
		if(S.is_empty()) return 0;
		else {
			return przeszukaj_wezel(atoi(S.pop().c_str()));
		}
	

	//gdy odwiedzone
	
	}

void graf::dfs(){
	
	przeszukaj_wezel(0);

}

