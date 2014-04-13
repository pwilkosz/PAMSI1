#ifndef DRZEWO_HH
#define DRZEWO_HH
#include<string>
#include<iostream>
#include"str_operacje.hh"
/*! \file
	Plik zawiera definicje klasy reprezentujacej drzewo binarne
	*/
using namespace std;
/*! \brief typ wyliczeniowy, określa, czyim synem jest dany element drzewa*/
enum syn{lewy, zaden, prawy};
/*! \brief modeluje pojedynczy wezel drzewa*/
template<typename TYP>
class wezel{
	/*! \brief klucz sluzacy do wyszukiwania*/
	string klucz;
	/*! \brief wartosc wezla*/
	TYP wart;
public:
	/*! \brief okresla, czyim synem jest wezel*/
	syn flag;
	/*! \brief wskaznik na ojca danego wezla*/
	wezel* ojciec;
	/*! \brief wskaznik na lewego syna wezla*/
	wezel* lsyn;
	/*! \brief wskaznik na prawego syna wezla*/
	wezel* psyn;
	/*! \brief konstruktor bezparametryczny*/
	wezel(){}
	/*! \brief konstruktor parametryczny
	\param [in] k - klucz
	\param [in] v - wartosc

	*/
	wezel(string k, TYP v):klucz(k), wart(v){ojciec = lsyn = psyn = NULL;}
	/*! \brief destruktor*/
	~wezel(){}
	/*! \brief 
	\return klucz wezla
	*/
	string wez_klucz(){return klucz;}
	/*! \brief 
	\return wartosc wezla
	*/
	TYP wez_wart(){return wart;}
	/*!
	\brief dodaje syna do danego wezla
	*/
	void dodaj_syna(wezel* w){
		
		if(w->wez_klucz()<=klucz) {
			
			if(!lsyn){lsyn = w; w->flag = lewy; w->ojciec = this; }
			else {lsyn->dodaj_syna(w);}
		}
		else{
			if(!psyn){psyn = w; w->flag = prawy; w->ojciec = this; }
			else {psyn->dodaj_syna(w);}
		}
	}
	wezel<TYP>* znajdz_nast(){
		if(!lsyn) return this;
		else return lsyn->znajdz_nast();
	}
};
/*! 
	\brief modeluje binarne drzewo przeszukiwan
	*/
template<typename TYP>
class drzewo{
public:
	/*! \brief korzen drzewa*/
	wezel<TYP>* korzen;
	/*! \brief znaleziony wezel w drzewie*/
	wezel<TYP>* znaleziony;
	/*! \brief konstruktor bezparametryczny */
	drzewo(){korzen = NULL;}
	/*! \brief konstruktor parametryczny - przypisuje korzeniowi klucz i wartosc*/
	drzewo(string k, TYP v){korzen = new wezel<TYP>(k,v);}
	/*! \brief dodaje wezel do drzewa
		\param [in] W - utworzony uprzednio wezel
	*/
	void dodaj_wezel(wezel<TYP>* W){
		if(!korzen) korzen = W;
		else korzen->dodaj_syna(W);
	}
	/*! \brief dodaje wezel do drzewa
		\param [in] k - klucz wezla
		\param [in] v = wartosc wezla
	*/
	void dodaj(string k, TYP v){
		wezel<TYP>* w = new wezel<TYP>(k,v);
		
		dodaj_wezel(w);
	}
	/*! \brief szuka wezla o zadanym kluczu
	\param [in] k - klucz 
	\return true, gdy znaleziono, w przeciwnym wypadku zwraca false
	*/
	bool znajdz(string k){
		
		return szukaj(k, korzen);
	}
	/*! \brief sprawdza, czy w danym wezle znajduje sie szukany klucz
	\param [in] k - klucz
	\param [in] w - wezel, w ktorym sprawdzany jest klucz
	\return true, gdy znaleziono, false w przeciwnym przypadku
	*/
	bool szukaj(string k, wezel<TYP>* w){
		
		if(w->wez_klucz() == k) {znaleziony = w;return true;}
		
		if(k <= w->wez_klucz() && w->lsyn) {return szukaj(k, w->lsyn);}
		
		else if(k >= w->wez_klucz() && w->psyn) { return szukaj(k, w->psyn);}
		else return false;
	}
	


	/*! \brief usuwa element o kluczu k, jezeli zostanie on znaleizony
	\param [in] k - klucz wezla, ktory nalezy usunac
	*/
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
	/*! \brief rekursywne czyszczenie wezla
	\param [in] w - czyszczony wezel
	*/
	void czysc(wezel<TYP>* w){
		if(w->lsyn) czysc(w->lsyn);
		else if(w->psyn) czysc(w->psyn);
		
		else usun(w->wez_klucz());
		
	}
	/*! \brief czysci cale drzewo*/
	void wyczysc(){
		czysc(korzen);
	}

};

#endif