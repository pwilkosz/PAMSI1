#ifndef DRZEWO_HH
#define DRZEWO_HH
#include<string>
#include<iostream>
#include"str_operacje.hh"

using namespace std;
enum syn{lewy, zaden, prawy};
template<typename TYP>
class wezel{
	int x;
	string klucz;
	TYP wart;
public:
	syn flag;
	wezel* ojciec;
	wezel* lsyn;
	wezel* psyn;
	wezel(){}
	wezel(string k, TYP v):x(0), klucz(k), wart(v){ojciec = lsyn = psyn = NULL;}
	~wezel(){}
	string wez_klucz(){return klucz;}
	TYP wez_wart(){return wart;}
	void dodaj_syna(wezel* w){
		cout<<"dodaj syna "<<x<<endl;
		x++;
		if(w->wez_klucz()<=klucz) {
			cout<<"mnijesze"<<endl;
			if(!lsyn){lsyn = w; w->flag = lewy; w->ojciec = this;}
			else lsyn->dodaj_syna(w);
		}
		else{cout<<"wieksze"<<endl;
			if(!psyn){psyn = w; w->flag = prawy; w->ojciec = this; }
			else psyn->dodaj_syna(w);
		}
	}
	wezel<TYP>* znajdz_nast(){
		if(!lsyn) return this;
		else return lsyn->znajdz_nast();
	}
};
template<typename TYP>
class drzewo{
public:
	wezel<TYP>* korzen;
	wezel<TYP>* znaleziony;
	drzewo(){korzen = NULL;}
	drzewo(string k, TYP v){korzen = new wezel<TYP>(k,v);}
	void dodaj_wezel(wezel<TYP>* W){
		if(!korzen)korzen = W;
		else korzen->dodaj_syna(W);
	}
	void dodaj(string k, TYP v){
		wezel<TYP>* w = new wezel<TYP>(k,v);
		dodaj_wezel(w);
	}
	bool znajdz(string k){
		
		return szukaj(k, korzen);
	}
	bool szukaj(string k, wezel<TYP>* w){
		
		if(w->wez_klucz() == k) {znaleziony = w;return true;}
		
		if(k <= w->wez_klucz() && w->lsyn) {return szukaj(k, w->lsyn);}
		
		else if(k >= w->wez_klucz() && w->psyn) { return szukaj(k, w->psyn);}
		else return false;
	}
	void wypisz(){
		cout<<korzen->wez_klucz()<<" "<<korzen->wez_wart()<<endl;
		cout<<korzen->psyn->wez_klucz()<<" "<<korzen->psyn->wez_wart()<<endl;
	}



	void usun(string k){
		if(znajdz(k)){
			//element jest lisciem
			if(znaleziony->lsyn == NULL && znaleziony->psyn == NULL){
				
				if(znaleziony->flag == lewy) {znaleziony->ojciec->lsyn = NULL;}
				if(znaleziony->flag == prawy) {znaleziony->ojciec->psyn = NULL; }

				delete znaleziony;

			}
			//element ma prawego syna
			else if(!(znaleziony->lsyn)){
				znaleziony->psyn->ojciec = znaleziony->ojciec;
				//sprawdzic ktorym synem jest wezel, ale co zrobic jak bedzie chodzilo o korzen? To chyba nie bedzie konieczne,
				//gdyz chodzi tu tylko o to, aby ojciec mial na kogo wskazywac
				if(znaleziony->flag == lewy){
					znaleziony->ojciec->lsyn = znaleziony->psyn;
				}
				else if(znaleziony->flag == prawy){
					znaleziony->ojciec->psyn = znaleziony->psyn;
				}
				delete znaleziony;
			}
			else if(!(znaleziony->psyn)){
				znaleziony->lsyn->ojciec = znaleziony->ojciec;
				if(znaleziony->flag == lewy){
					znaleziony->ojciec->lsyn = znaleziony->lsyn;
				}
				else if(znaleziony->flag == prawy){
					znaleziony->ojciec->psyn = znaleziony->lsyn;
				}
				delete znaleziony;
			}
			else{
				wezel<TYP>* tmp;
				if(!znaleziony->psyn->lsyn) tmp = znaleziony->psyn;
				else tmp = znaleziony->psyn->znajdz_nast();
				tmp->lsyn = znaleziony->lsyn;
				tmp->psyn = znaleziony->psyn;
				if(znaleziony->flag == lewy){
					znaleziony->ojciec->lsyn = tmp;
				}
				else if(znaleziony->flag == prawy){
					znaleziony->ojciec->psyn = tmp;
				}
				delete znaleziony;
			}
			//usun element
			
		}
		else cout<<"Nie znaleziono wezla"<<endl;
	}
	void czysc(wezel<TYP>* w){cout<<"czysc"<<endl;
		if(w->lsyn) czysc(w->lsyn);
		else if(w->psyn) {czysc(w->psyn);
		cout<<"przed delete"<<endl;}
		else delete w;
		cout<<"po delete"<<endl;
	}
	void wyczysc(){cout<<"wyczysc"<<endl;
		czysc(korzen);
	}

};

#endif