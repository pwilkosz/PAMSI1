#ifndef TABLICA_ASOCJACYJNA_HH
#define TABLICA_ASOCJACYJNA_HH
#include<iostream>
#include<string>
#include<list>
#include<cstdlib>
#include"str_operacje.hh"
using namespace std;

/*! 
	\file
	Plik zawiera definicje klasy tablica_asocjacyjna, oraz definicje funkcji pomocniczych jako przeciazen operatorow porownania dla klasy typu string*/

/*! \brief 
	Klasa modeluje tablice asocjacyjna 
*/
template<typename TYP>
class tablica_asocjacyjna{
	/*! \brief Tablica zawierajaca klucze poszukiwan*/
	string* key;
	/*! \brief Tablica zawierajaca wartosci*/
	TYP* value;
	/*! \brief rozmiar tablicy*/
	int s;
	/*! \brief rozmiar danych zapelniajacych tablice*/
	int sp;
	/*! \brief flaga informujaca o tym, czy dany klucz znaleziono w zbiorze*/
	bool found;
	/*! \brief 
		Metoda ktora umieszcza wartosc oraz jej klucz w zadanym mejscu. Gdy wartosc z kluczem jest dodawana w srodek struktury, dane na prawo od niej 
		przesuwane sa o jeden w prawo. Gdy istnieje potrzeba powiekszenia tablicy, stosuje sie znany juz radzaj gospodarowania pamiecia,
		gdzie rozmiar tablicy jest podwajany, co jest korzystne ze wzgledu na zlozonosc obliczeniowa
	 */
	void insert(int ind,string k, TYP v){
		if(sp == s){// powieksz rozmiar tablicy
			
			string* tmp1 = new string[s];
			TYP* tmp2 = new TYP[s];
			for (int i = 0; i<sp; i++){//przepisanie do tablicy zastepczej
			
				tmp1[i] = key[i];
				tmp2[i] = value[i];

			}
			delete[] key; delete[] value;
			s = 2*sp;
			
			key = new string[s]; value = new TYP[s];
			if(ind!=0){
				for(int i = 0; i<ind; i++){
					key[i] = tmp1[i];
					value[i] = tmp2[i];
				}
			}
			
			key[ind] = k;
			value[ind] = v;
			if(ind<sp){
				for(int i = ind + 1; i<sp+1; i++){
					key[i] = tmp1[i-1];
					value[i] = tmp2[i-1];
			}}
			sp++;
			
			delete[] tmp1; delete[] tmp2;
		}
		else{//zrob miejsce na zmienna 
			if(ind == sp) {key[sp] = k; value[sp] = v;sp++;}
			else{
			for(int i = sp; i>ind; i--){
				
				key[i] = key[i-1];
				value[i] = value[i-1];
			}
			key[ind] = k; value[ind] = v;
			sp++;
		}
	}}
	/*! \brief
		Metoda szuka pozycji, w ktora nalezy dodac element, aby tablica  byla posortowana alfabetycznie
	*/
	void wstaw(string k, TYP v, int ind_l, int ind_r){
		if(ind_l == ind_r){
			if(k<=key[ind_l])
			insert(ind_l,k,v);
			else insert(ind_l+1,k,v);
		}
		else{ 
			int c = (ind_l + ind_r)/2;
			if(k == key[c]) {insert(c,k,v);}
			else if(k<key[c]) {wstaw(k,v,ind_l, c);}
			else {wstaw(k,v,c+1, ind_r);}
		}
	}
	/*! \brief 
		Metoda szuka w zbiorze zadanego klucza (przeszukiwanie binarne), gdy element zostanie odnaleziony, tzn jest zawarty w strukturze, flaga found ustawiana jest na wartosc true 
		\return indeks szukanego elementu
	*/
	int znajdz(string k, int ind_l, int ind_r){
			
			//cout<<k<</*" "<<key[ind_l]<<" "<<key[ind_r]<<*/endl;
			if(k == key[ind_l]) {found = true;return ind_l;}
			if(k == key[ind_r]) {found = true; return ind_r;}
			int c = (ind_l + ind_r)/2;
			
			if(k<key[c]) return znajdz(k, ind_l, c);
			else if(k>key[c]) return znajdz(k, c, ind_r);
			else if (k == key[c]) {found = true; return c;}
			else {found = false; return 0;}
		}
	
public:
	/*! \brief 
		Konstruktor klasy; ustawia nastepujace parametry
		\verbatim
		s = 0 newline
		sp = 0 newline
		found = false
		\endverbatim
	*/
	tablica_asocjacyjna(): s(0), sp(0), found(0){}
	/*! \brief 
		Metoda dodaje element do struktury. Gdy (uwzgledniajac porzadek alfabetyczny) element ma stac w skrajnym miejscu tablicy, dodawany jest od razu.
		W przeciwnym razie funkcja \p wstaw \p szuka odpowiedniego miejsca.
		Ponadto metoda tworzy pamiec dla struktury, gdy uprzednio jest ona pusta
	*/
	void dodaj(string k, TYP v){
		
		
		/*--------- wstawianie elementu ---------------*/
		if(czy_pusta()) {key = new string[1]; value = new TYP[1]; key[0] = k; value[0] = v;s = 1; sp = 1; }
		/*Gdy mamy zapęłnioną uprzednio tablicę*/
		else{ 
			if(k<key[0]) {insert(0,k, v);}
			else if (k>key[sp-1]) {insert(sp,k, v);}
			else {;wstaw(k, v, 0, sp-1);}
		}
	}
	/*! \brief 
		Metoda usuwa zadany element, korzystajac z funkcji znajdz 
	*/
	void usun(string k){
		if(czy_pusta()) cout<<"SLOWNIK PUSTY!"<<endl;
		else{//usuwanie wybranego elementu
			int ind = znajdz(k, 0, sp-1);
			if (found){
				for(int i = ind; i<sp; i++){
					key[i] = key[i+1];
					value[i] = value[i+1];
				}
				sp--;
			}
			else cout<<"NIE ZNALEZIONO ELEMENTU"<<endl;
		}
		found = false;
	}
	/*! \brief 
		Metoda zwraca uzytkownikowi szukany element, pod warunkiem, ze jest on w zbiorze
		\return szukany element
		Gdy slownik jest pusty lub szukany element nie istnieje, uzytkownik zostaje o tym poinformowany
	*/
	TYP pobierz(string k){
		if(czy_pusta()) {cout<<"SLOWNIK PUSTY!"<<endl; return 0;}
		else{
			TYP v = value[znajdz(k, 0, sp-1)];
			if(found) return v;
			else {cout<<"NIE ZNALEZIONO ELEMENTU"<<endl; return 0;}
		}
		found = false;
	}

	bool znajdz(string k){
		pobierz(k);
		return found;
	}
	/*! \brief
		\return true, gdy stos jest pusty, false w przeciwnym wypadku
	*/
	bool czy_pusta(){return (s==0);}
	/*! \brief
		\return ilosc elementow w strukturze
	*/
	
	int zlicz_elementy(){return sp;}

	void wypisz(){
		for(int i = 0; i<10; i++)
			cout<<key[i]<<endl;
	}
};


#endif