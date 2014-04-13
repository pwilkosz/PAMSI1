#ifndef HASHTAB_HH
#define HASHTAB_HH
#include<vector>

/*!
	\file 
	Plik zawiera definicje klasy reprezentujacej tablice haszujaca
*/
/*! \brief pojedynczy element tablicy haszujacej*/
template<typename TYP>
class el_tab{
public:
	/*!
	\brief identyfikator
	*/
	string klucz;
	/*! 
		\brief
		wartosc pola
		*/
	TYP wart;
	/*! 
\brief flaga informujaca, czy pole jest zajete
		*/
	bool zajety;
	el_tab():zajety(false){}
	~el_tab(){}
};
/*!
	\brief
	modeluje tablice haszujca w oparciu o kontener klasy el_tab
	*/
template<typename TYP>
class hashtab{
	/*! \brief dlugosc tablicy*/
	int dlugosc;
	/*! \brief tablica haszujaca*/
	vector<el_tab<TYP> > tab;
public:
	/*! \brief ustawia dlugosc tablicy */
	void ustaw_dlugosc(int d){dlugosc = d;}
	/*! \brief konstruktor bezparametryczny*/
	hashtab(){}
	/*! \brief konsruktor parametryczny
		\param [in] N - rozmiar tablicy
		*/
	hashtab(int N):tab(N){ ustaw_dlugosc(N);}
	/*! \brief funkcja haszujaca
		\return h - liczba, ktora po kompresji bedzie indeksem danego elementu
	*/
	unsigned long hash(string k){
		long h = 0;
		for(unsigned int i = 0; i<k.length(); i++){
			h = abs(h*101 + abs(k[i]));	
		}
		return h;
	}
	/*! \brief metoda dodaje element do tablicy hasuzjacej*/
	void dodaj(string k, TYP v){
		
		int i =0;
		unsigned long ind = hash(k)%dlugosc;
		
		while(tab[ind].zajety){
			ind = (ind + i)%dlugosc;
			i+=1889;
			
		}
		tab[ind].wart = v; tab[ind].klucz = k; tab[ind].zajety = true;
	}
	/*! \brief metoda szuka zadanego elementu w oparciu o klucz
	\param [in] k - klucz elementu
	\return znaleziony element*/
	el_tab<TYP>* znajdz(string k){
		
		int i = 0;
		unsigned long ind = hash(k)%dlugosc;
		if(!tab[ind].zajety) {return NULL;}
		else{
			while(tab[ind].klucz!= k){
				ind = (ind + i)%dlugosc;
				i+=1889;  }
			}
			
			return &tab[ind];
	}
	/*! \brief usuwa element jesli znajduje sie w tablicy
	\param [in] k - klucz*/
	void usun(string k){
		if(znajdz(k)) znajdz(k)->zajety = false;
		else cout<<"nie znaleziono"<<endl;
	}
	void wypisz(){
		for(int i = 0; i<dlugosc; i++)
			cout<<tab[i].zajety<<endl;
	}
};

#endif