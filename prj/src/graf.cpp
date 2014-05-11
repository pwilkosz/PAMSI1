#include"graf.hh"
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<cmath>

tablica_asocjacyjna<int> vec;

void graf::dodaj_wierzcholek(){
	lista_incydencji.push_back(vec);
	int rozm = lista_incydencji.size();
	ostringstream s; s<<(--rozm);
	cout<<s.str()<<endl;
	tab.dodaj(s.str(), false);
}

void graf::dodaj_wierzcholek(wierzcholek w){
	
	lista_incydencji.push_back(vec);
	int rozm = lista_incydencji.size();
	ostringstream s; s<<(--rozm);
	cout<<s.str()<<endl;
	tab.dodaj(s.str(), false);
	
}

void graf::dodaj_wierzcholek(int id){
	lista_incydencji.push_back(vec);
	int rozm = lista_incydencji.size();
	ostringstream s; s<<(--rozm);
	cout<<s.str()<<endl;
	tab.dodaj(s.str(), false);
	//tab2.dodaj(s.str(), false);
	poprzednik.push_back(0);
	dist.push_back(0);
	est.push_back(0);
	w_x.push_back((id%100)*10);
	w_y.push_back((id/100)*10);
}

void graf::dodaj_krawedz(int id1, int id2){ 
	srand(time(NULL));
	if((id1>lista_incydencji.size() && id2>lista_incydencji.size())|| lista_incydencji[id1].czy_blokada()||lista_incydencji[id2].czy_blokada()) cout<<"w grafie nie ma takich wierzchołków"<<endl;
	else{
		ostringstream s1, s2; s1<<id1; s2<<id2;
		
		int waga = (abs(w_x[id1] - w_x[id2]) + abs(w_y[id1] - w_y[id2])) -10;//rand()%50;
		
		lista_incydencji.at(id1).dodaj(s2.str(), waga);
	
		lista_incydencji.at(id2).dodaj(s1.str(), waga);
	}
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


void graf::wypisz_liste(){
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

bool graf::przeszukaj_wezel(int id, int wzor){
	stack_array<string> S(x2);

	ostringstream s; s<<id;
	
	if(id == wzor) {;return true;}
	else{
	
		tab.ustaw(s.str(), true);
		for(int i = lista_incydencji[id].zlicz_elementy() -1; i>=0; i--){ 
			if(lista_incydencji[atoi(lista_incydencji[id].wez_id(i).c_str())].czy_blokada()) continue;
			if(tab.pobierz(lista_incydencji[id].wez_id(i))) continue;
			
			S.push(lista_incydencji[id].wez_id(i));
			
		
			
		}
		
		
		while(!S.is_empty()){ 
			int idd = atoi(S.pop().c_str());
			if(przeszukaj_wezel(idd,wzor)){
				
				Q.push(idd);
				return true;
			}
		}
		return false;

	}
	
	}

void graf::dfs(int id){
	przeszukaj_wezel(0,id);
	//if(przeszukaj_wezel(0,id)){
		//wypisanie sciezki
	//	while(!Q.is_empty())
	//		cout<<Q.pop()<<" --> ";
	//}
	//else cout<<"nie znaleziono sciezki"<<endl;
	tab.wyczysc();
}

bool graf::przeszukaj_wezel_1(int id, int wzor){
	
	queue_array<string> S(x2);
	
	ostringstream s; s<<id;
	
	if(id == wzor) return true;
	else{
	
		tab.ustaw(s.str(), true);
		for(int i = lista_incydencji[id].zlicz_elementy() -1; i>=0; i--){ 
			if(lista_incydencji[atoi(lista_incydencji[id].wez_id(i).c_str())].czy_blokada()) continue;
			if(tab.pobierz(lista_incydencji[id].wez_id(i))) continue;
			
			S.enqueue(lista_incydencji[id].wez_id(i));
		
			
		}
		
		
		while(!S.is_empty()){ 
			int idd = atoi(S.dequeue().c_str());
			if(przeszukaj_wezel_1(idd,wzor)){
				Q.push(idd);
				return true;
			}
		}
		return false;

	}
	
	
	}

void graf::bfs(int id){
	przeszukaj_wezel_1(0,id);
	/*
	if(przeszukaj_wezel_1(0,id)){
		//wypisanie sciezki
		while(!Q.is_empty())
			cout<<Q.pop()<<" --> ";
	}
	else cout<<"nie znaleziono sciezki"<<endl;
*/
	tab.wyczysc();
}

bool graf::przeszukaj_wezel_2(int id, int wzor){

	tablica_asocjacyjna<string> S;
	
	ostringstream s; s<<id;
	
	if(id == wzor) return true;
	else{
	
		tab.ustaw(s.str(), true);
		for(int i = lista_incydencji[id].zlicz_elementy() -1; i>=0; i--){ 
			if(lista_incydencji[atoi(lista_incydencji[id].wez_id(i).c_str())].czy_blokada()) continue;
			if(tab.pobierz(lista_incydencji[id].wez_id(i))) continue;
			
			ostringstream p;
			p<<lista_incydencji[id].wez(i);
			

			S.dodaj(p.str(), lista_incydencji[id].wez_id(i));
		
			
		}
		
		
		for(int l = 0; l<S.zlicz_elementy(); l++){ 
			int idd = atoi(S.wez(l).c_str());
			if(przeszukaj_wezel_2(idd,wzor)){
				Q.push(idd);
				return true;
			}
		}
		return false;

	}
	
	
}

void graf::best_first(int id){
	przeszukaj_wezel_2(0,id);
	
	//if(przeszukaj_wezel_2(0,id)){
		//wypisanie sciezki
	//	while(!Q.is_empty())
	//		cout<<Q.pop()<<" --> ";
	//}
	//else cout<<"nie znaleziono sciezki"<<endl;
	tab.wyczysc();
}

void graf::rysuj(){
	ofstream dot("graf.dot");

	dot<<"digraph G{"<<endl;
	for(int i = 0; i<lista_incydencji.size(); i++){
		for(int j = 0; j<lista_incydencji[i].zlicz_elementy(); j++){
			dot<<i<<" -> "<<lista_incydencji[i].wez_id(j)<<"[label = \""<<lista_incydencji[i].wez(j)<<"\"];"<<endl;
		}
	}
	dot<<"}"<<endl;
}

void graf::a_star(int id, int wzor){ 
	tablica_asocjacyjna<int> nie_przejrzane;
	
	nie_przejrzane.dodaj("0", id);
	//tab2.ustaw(s.str(), false);
	while(nie_przejrzane.zlicz_elementy()){ 
		
		int temp = nie_przejrzane.wez(0);
		
		ostringstream s; s<<temp;
		if(temp == wzor) break;
		nie_przejrzane.usun(nie_przejrzane.wez_id(0));
		
		tab.ustaw(s.str(), true);
		
		for(int i = lista_incydencji[temp].zlicz_elementy() -1; i>=0; i--){
			string k = lista_incydencji[temp].wez_id(i);
			ostringstream s1; 
			
			if(lista_incydencji[atoi(lista_incydencji[temp].wez_id(i).c_str())].czy_blokada()) continue;
			
			if(tab.pobierz(k)) continue;
			//cout<<"b3"<<endl;
			//cout<<" przeszukuje: "<<k<<endl;
			//if(tab2.pobierz(k)) continue; //jezeli jest w tych do odwiedzenia
			poprzednik[atoi(lista_incydencji[temp].wez_id(i).c_str())] = temp; 
			dist[atoi(k.c_str())] = dist[temp] + lista_incydencji[temp].wez(i);
			//cout<<"b4"<<endl;
			est[atoi(k.c_str())] = abs(w_y[wzor] - w_y[atoi(k.c_str())]) + abs(w_x[wzor] - w_x[atoi(k.c_str())]);
			s1<<(dist[atoi(k.c_str())] + est[atoi(k.c_str())]);
			//cout<<"b5"<<endl;
			nie_przejrzane.dodaj(s1.str(), atoi(k.c_str()));
			//cout<<"b6"<<endl;

		}
	}
	
	//for(int l = 0; l<9; l++)
	//	cout<<" "<<l<<": "<<poprzednik[l]<<endl;
	tab.wyczysc();

}