#include "simplex.hh"
#include <iostream>
#include <cstdlib>
#include <limits>
void simplex::interfejs(){
	int il_zm;
	int il_rown;
	float k;
	cout<<"Podaj ilosc zmiennych decyzyjnych: ";
	cin>>il_zm;
	while(cin.fail()){
		cout<<"Bledny format, sprobuj ponownie: ";
		cin>>il_zm;
	}
	cout<<"Podaj ilosc rownan: ";
	cin>>il_rown;
	while(cin.fail() || (il_rown<il_zm)){
		cout<<"Bledny format, sprobuj ponownie: ";
		cin>>il_rown;
	}

	/*wprowadzenie kosztow dla kazdej zmiennej. Koszt i-tej zmiennej to element pod indeksem 'i-1'*/
	for(int i = 0; i<il_zm; i++){
		cout<<"wprowadz koszt dla zmiennej nr "<<i+1<<": ";
		cin>>k;
		koszt.push_back(k);
	}
	for(int i =0; i<il_rown;i++)
		koszt.push_back(0);

	/*Tworzenie struktury do przechowania danych*/
	vector<float> vec;
	uklad.push_back(vec);
	/*wyraz wolny*/
	uklad.at(0).push_back(0);
	/*Przepisanie kosztow*/
	for(int i = 0; i<(il_zm+il_rown); i++)
		uklad.at(0).push_back(koszt[i]);
	for(int i = 1; i<=(il_zm + il_rown); i++){
		uklad.push_back(vec);
		for(int k = 0; k<=(il_zm+il_rown); k++)
		uklad.at(i).push_back(0);
	}

	/*Wczytam dane jak bede juz mial strukture danych*/
	cout<<"Podaj kolejne wspolczynniki: "<<endl;
	for(int i = 1; i<=il_rown; i++)
		for(int k = 1; k<=il_zm; k++){
			cout<<"pozycja: ( "<<i<<", "<<k<<" ): ";
			cin>>uklad.at(i+il_zm).at(k);
			if(uklad.at(i+il_zm).at(k)<0) cout<<"gdzie mie z tym minusem?! Potraktuje to jako plus."<<endl;
			else uklad.at(i+il_zm).at(k) *= -1;
		}
	for(int i = 1; i<=il_rown; i++){
		cout<<"Ograniczenie "<<i<<": ";
		cin>>uklad.at(i+il_zm).at(0);
	}

	for(int i = 0; i<il_zm; i++){
		nie_baza.push_back(i+1);
		
	}
	for(int i = 0; i<il_rown;i++){
		baza.push_back(il_zm + i+1);
	}
}
void simplex::wypisz_uklad(){
	
		
		/*wypisanie ukladu zeby sprawdzic czy dobrze dziala*/
	cout<<"WYPISANIE UKLADU: "<<endl;
	for(unsigned int i = 0; i<uklad.size(); i++){
		if(i == 0){
			cout<<"Z = ";
			for(unsigned int k = 0; k<uklad.at(0).size(); k++ )
				cout<<uklad.at(0).at(k)<<" * x"<<k<<" + ";
			cout<<endl;
		}
		else{
			cout<<" X"<<i<<" = ";
			for(unsigned int k = 0; k<=(uklad.at(0).size()-1);k++)
				cout<<uklad.at(i).at(k)<<" * X"<<k<<" ";
			cout<<endl;
		}
	}
}

bool simplex::zamien(unsigned int zm1, unsigned int zm2){
	int ind1, ind2;
	/*znajdz id1 w niebazie*/
	for(unsigned int l = 0; l<=nie_baza.size();l++){
		if(l == nie_baza.size()) {return false;}
		if(nie_baza.at(l) == zm1) {ind1 = l; break; }
	}
	/*znajdz id2 w bazie*/
	for(unsigned int l = 0; l<=baza.size();l++){
		if(l == baza.size()) return false;
		if(baza.at(l) == zm2){ind2 = l; break;}
	}
	/*z rowania bazowego wyznaczyc zmienna niebazowa*/
	/*stworz nowy wektor i przepisz do niego elementy ze zmienionym znakiem*/
	/*wektor wyznacza zmienna ktora weszla do bazy*/
	vector<float> temp;
	for(unsigned int i = 0; i < uklad.at(zm2).size(); i++){
		if(i == zm1) temp.push_back(0);
		else if(i == zm2) temp.push_back(1);
		else temp.push_back(-uklad.at(zm2).at(i));
	}
	/*Teraz jeszcze podzielmy wekor przez wiadomo co*/
	for(unsigned int i = 0; i<temp.size();i++){
		temp.at(i) = temp.at(i)/uklad.at(zm2).at(zm1);
		
	}
	/*zamieniamy elementy w wektorze*/
	nie_baza.erase(nie_baza.begin() + ind1);
	nie_baza.push_back(zm2);
	baza.erase(baza.begin() + ind2);
	baza.push_back(zm1);
	wstaw(zm1,temp);
	return true;
}
/*! \brief metoda aktualizuje uklad dopelnieniowy*/
void simplex::wstaw(int id, vector<float> temp){ 
	/*wyzeruj wszystkie niebazowe*/
	vector<float>temp1;
	temp1 = temp;
	
	for(unsigned int i = 0; i<nie_baza.size(); i++){
		vector<float>::iterator it = uklad.at(nie_baza.at(i)).begin();
		vector<float> nowy(uklad.at(0).size(), 0);
		uklad.at(nie_baza.at(i)).clear();
		uklad.at(nie_baza.at(i)).insert(it,nowy.begin(),nowy.end());

	}
	uklad.at(id) = temp;
	/*Teraz podstawiamy nowa zmienna bazowa*/
	/*Aktualizacja ukladu, zrobimy troche osobno dla funkcji celu*/
	for(unsigned int k = 0; k<temp1.size(); k++){
			temp1.at(k) = temp1.at(k)*uklad.at(0).at(id);
			
		}
		uklad.at(0).at(id) = 0;
	for (unsigned int k = 0; k<temp1.size(); k++){
			/*sumowanie elementow*/
			uklad.at(0).at(k) = uklad.at(0).at(k) + temp1.at(k);
		}
	temp1 = temp;
	
	for(unsigned int i = 0; i<baza.size(); i++){
		for(unsigned int k = 0; k<temp1.size(); k++){
			temp1.at(k) = temp1.at(k)*uklad.at(baza.at(i)).at(id);
		}
		uklad.at(baza.at(i)).at(id) = 0;
		
		for (unsigned int k = 0; k<temp1.size(); k++){
			/*sumowanie elementow*/
			uklad.at(baza.at(i)).at(k) = uklad.at(baza.at(i)).at(k) + temp1.at(k);
		}
		temp1 = temp;
	}
		

	temp1 = temp;
	}
int simplex::wez_zmienna_niebazowa(){
	for(unsigned int i = 0; i<nie_baza.size(); i++){
		if(uklad.at(0).at(nie_baza.at(i))>0) return nie_baza.at(i);
	}
	return 0;
}

float simplex::zmienna_bazowa_do_wymiany(){
	/*wez zmienna niebazowa*/
	vector<float> do_min;
	int nb = wez_zmienna_niebazowa();
	
	if(nb == 0) return 0;
	else{
		/*dla kazdej zmiennej bazowej wyznacz zaleznosc od zmiennej niebazowej*/
		for(unsigned int i = 0; i<baza.size(); i++){
			
			if(uklad.at(baza.at(i)).at(nb) >= 0) do_min.push_back(numeric_limits<float>::max());
			else{
				float a = uklad.at(baza.at(i)).at(0)/(-uklad.at(baza.at(i)).at(nb));
				do_min.push_back(a);
			}
		}
	}
	/*bierzemy najmniejsza ilosc z podanej tablicy*/
	/*Ale jak sprawdzic o ktora zmienna chodzi
	zmienna bazowa ma ten sam indeks co w do_min!!
	*/
	int indeks_min = -1;
	float wart_min = numeric_limits<float>::max();
	for(unsigned int i = 0; i<do_min.size(); i++){
		if(do_min.at(i)<wart_min) {
			wart_min = do_min.at(i);
			indeks_min = i;
		}
		
	}
	
	return baza.at(indeks_min);
}

float simplex::Z(){
	return uklad.at(0).at(0);
}
/*! \brief rozwiazuje uklad*/
void simplex::rozwiaz(){
	/*Rozwiazywanie ukladu dopelnieniowego, warunki stopu:
	- zmienna przechowujaca aktualna wartosc funkcji celu
	- dopoki nastepna wartosc funkcji celu nie jest mniejsza od poprzedniej ->
	-> zamieniaj punkty bazy ->wylicz funkcje celu
	*/
	float cel = -1;
	int N = wez_zmienna_niebazowa();
	int B = 1; //zmienna bazowa
	while(N!=0 && Z()>cel){
		cel = Z();
		B = zmienna_bazowa_do_wymiany();
		zamien(N,B);
		N = wez_zmienna_niebazowa();
	
	}
	cout<<"ROZWIAZANIE OPTYMALNE -> MAKSYMALNY ZYSK: "<<Z()<<endl;
}