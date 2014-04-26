#include"graf.hh"
#include<sstream>
tablica_asocjacyjna<int> vec;

void graf::dodaj_wierzcholek(wierzcholek w){
	cout<<"dodjae"<<endl;
	lista_incydencji.push_back(vec);
	//ostringstream s; s<<w.id;
	//lista_incydencji.at(w.id).dodaj(s.str(), w.waga);
	cout<<"dodano"<<endl;
}

void graf::dodaj_krawedz(wierzcholek w1, wierzcholek w2, unsigned int waga){
	dodaj_krawedz(w1.id, w2.id, waga);
}

void graf::dodaj_krawedz(unsigned int id1, unsigned int id2, unsigned int waga){
	if(id1>lista_incydencji.size() && id2>lista_incydencji.size()) cout<<"w grafie nie ma takich wierzchołków"<<endl;
	else{
		ostringstream s1, s2; s1<<id1; s2<<id2;
		lista_incydencji.at(id1).dodaj(s2.str(), waga);
		lista_incydencji.at(id2).dodaj(s1.str(), waga);
	}
}
void graf::sasiedztwo(unsigned int id){
	if(id<lista_incydencji.size()){
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
