#include "transport.hh"
#include<limits>



void zbierz_dane(){
	/*! \brief dane wprowadzone przezuzytkownika*/
	vector <int> dane;
	int il_fabr;
	int il_centr;
	cout<<"Podaj ilosc fabryk: ";
	cin>>il_fabr;
	cout<<"Podaj ilosc centrow dystrybucji: ";
	cin>>il_centr;
	int pom;
	for(int i = 0; i<il_fabr; i++)
		for(int k = 0; k<il_centr; k++){
			cout<<"Koszt transportu z fabryki "<<i+1<<" do magazynu "<<k+1<<" : ";
			cin>>pom;
			dane.push_back(pom);
		}
	for(int i = 0; i<il_fabr; i++){
		cout<<"Wprowadz podaz fabryki "<<i+1<<" : ";
		cin>>pom;
		dane.push_back(pom);
	}
	for(int i = 0; i<il_centr; i++){
		cout<<"Wprowadz popyt magazynu "<<i+1<<" : ";
		cin>>pom;
		dane.push_back(pom);
	}
	
	/*uruchomienie algorytmu - utworzenie klasy i rozwiazanie*/
	transport T(il_fabr, il_centr, dane);
	
	T.wypisz_mac_koszt();
	
	T.pierwsze_rozw_bazowe();
	
	T.wypisz_mac_sc();

	T.wyznacz_mac_opt();
	T.uzupelnij_mac_opt();
	T.wypisz_mac_opt();
}

void transport::pierwsze_rozw_bazowe(){
	cout<<"pierwsze rozwiazanie bazowe -"<<endl;
	
	/*przpisz podaz kazdej fabryki*/
	for(int i = 0; i<il_fabr; i++){
		macierz_sciezek.at(i).at(il_centr) = macierz_kosztow.at(i).at(il_centr);
	}
	for(int i = 0; i<il_centr; i++)
		macierz_sciezek.at(il_fabr).at(i) = macierz_kosztow.at(il_fabr).at(i);
	cout<<"ustalanie kosztow"<<endl;
	/*ustalenie kosztow*/
	for(int k = 0; k<il_centr; k++)
		for(int i = 0; i<il_fabr; i++){
			macierz_sciezek.at(i).at(k) = (macierz_sciezek.at(il_fabr).at(k)<macierz_sciezek.at(i).at(il_centr))?macierz_sciezek.at(il_fabr).at(k):macierz_sciezek.at(i).at(il_centr);
			
			macierz_sciezek.at(il_fabr).at(k) -= macierz_sciezek.at(i).at(k);
			
			macierz_sciezek.at(i).at(il_centr) -= macierz_sciezek.at(i).at(k);
		}
		/*Trzeba teraz wprowadzic ewentualne przewozy zdegenerowane*/
	/*for(int k = 0; k<il_centr; k++){
		int licznik = 0;
		int index1 = 0; int index2 = 0;
		for(int i = 0; i<il_fabr; i++){
			if(macierz_sciezek.at(i).at(k)>0) {licznik++; index1 = i; index2 = k;}
			}
			if(licznik>1){
				if(index1 == il_fabr) przejazdy_zdegenerowane.at(index1-1).at(index2) = true;
				else przejazdy_zdegenerowane.at(index1+1).at(index2) = true;	
			}

		}*/	
		/*Przepisanie poszczegolnych elementow do macierzy optymalizacji*/
		
		for(int i = 0; i<il_fabr; i++)
			for(int k = 0; k<il_centr; k++){
				if(macierz_sciezek.at(i).at(k)!=0 || przejazdy_zdegenerowane.at(i).at(k)) {macierz_optymalizacji.at(i).at(k) = macierz_kosztow.at(i).at(k);}
			}

	
}

int transport::spr_mac_opt(){
	int wsk = 0;
	for(int i = 0; i<il_fabr; i++)
		for(int k = 0; k<il_centr; k++){
			if(macierz_optymalizacji.at(i).at(k)<wsk) {
				wsk = macierz_optymalizacji.at(i).at(k);
				ind1 = i; ind2 = k;
			}
		}
	return wsk;
}

void transport::wypisz_mac_sc(){
	cout<<"wypisz macierz sciezek"<<endl;
	for(int i = 0; i<=il_fabr;i++){
		for(int k = 0; k<=il_centr; k++)
			cout<<macierz_sciezek.at(i).at(k)<<" , ";
		cout<<endl;
	}
}

void transport::wypisz_mac_koszt(){
	cout<<"wypisz macierz kosztow"<<endl;
	for(int i = 0; i<=il_fabr;i++){
		for(int k = 0; k<=il_centr; k++)
			cout<<macierz_kosztow.at(i).at(k)<<" , ";
		cout<<endl;
	}
}

void transport::wypisz_mac_opt(){
	for(int i = 0; i<=il_fabr;i++){
		for(int k = 0; k<=il_centr; k++)
			cout<<macierz_optymalizacji.at(i).at(k)<<" , ";
		cout<<endl;
	}
}

bool transport::wyznacz_mac_opt(){
	if(przeszukaj_wiersz(0)){
		for(int i = 0; i<il_fabr; i++)
			przejrzane_u.at(i) = false;
		for(int i = 0; i<il_centr; i++)
			przejrzane_v.at(i) = false;
	}
}



void transport::uzupelnij_mac_opt(){
	for(int i = 0; i<il_fabr; i++){
		for(int k = 0;k<il_centr; k++){
			macierz_optymalizacji.at(i).at(k) = macierz_optymalizacji.at(i).at(il_centr) + macierz_optymalizacji.at(il_fabr).at(k);
		}	
	}
	for(int i = 0;i<il_fabr;i++)
		for(int k = 0; k<il_centr; k++)
			macierz_optymalizacji.at(i).at(k) = macierz_kosztow.at(i).at(k) - macierz_optymalizacji.at(i).at(k);
}
/*! \brief tworzy cykl, ktory posluzy do poprawienia funkcji celu*/
void transport::aktualizuj_przejazdy(){
	/*sprawdzenia optymalnosci dokonamy osobno - mamy z gorty ind1 i ind2*/
	/*! \brief przechowuje elementy polcyklu dodatniego*/
	vector<vector<int> > polcykl_dodatni;
	/*! \brief przechowuje elementy polcyklu ujemnego*/
	vector<vector<int> > polcykl_ujemny;
	vector<int> vec_pom;
	for(int i =0; i<2; i++)
		polcykl_dodatni.push_back(vec_pom);
	for(int i = 0; i<3; i++)
		polcykl_ujemny.push_back(vec_pom);

}

bool transport::tworz_cykl_ujemny(int wiersz_start, int kolumna_start, int index1, int index2){
	if(index1 = wiersz_start || index2 == kolumna_start) return true;
	//sprawdzenie czy el. jest samotny w kolumnie!
	if(czy_element_samotny(false, index1,index2)) return false;
	//przeszukujemy wiersz
	for(int i = 0; i<il_centr; i++){
		if(i == index2) continue;
	}
}

bool transport::tworz_cykl_dodatni(int wiersz_start, int kolumna_start, int index1, int index2){
	if(index2 == kolumna_start) return true;
	else{
		/*znajdz element do cyklu, szykaj w kolumnie*/
		for(int i = 0; i<il_fabr; i++){
			if(macierz_sciezek.at(i).at(index2) != 0){
				//dodajemy element do polcyklu dodatniego

			}
		}
	}
}



/*STARSZA WERSJA TWORZENIA MACIERZY OPTYMALIZACJI---------------------------

/*warunek stopu
	if((fabryka == il_fabr - 1) && (centrum == il_centr - 1) ) return true;

	if((fabryka == 0) && (centrum == 0)) { //tylko na poczatku taka sytuacja moze miec miejsce
		macierz_optymalizacji.at(fabryka).at(il_centr) = 0;
		macierz_optymalizacji.at(il_fabr).at(centrum) = macierz_optymalizacji.at(fabryka).at(centrum) - macierz_optymalizacji.at(fabryka).at(il_centr);
		cout<<"ustawiam pierwszy element na 0"<<endl;
	}
	
	if(fabryka == il_fabr - 1) { 
		macierz_optymalizacji.at(il_fabr).at(centrum+1) = macierz_optymalizacji.at(fabryka).at(centrum+1) - macierz_optymalizacji.at(fabryka).at(il_centr);
		return wyznacz_mac_opt(fabryka, centrum + 1 );}
	else if(centrum == il_centr -1) { 
		macierz_optymalizacji.at(fabryka+1).at(il_centr) = macierz_optymalizacji.at(fabryka+1).at(centrum) - macierz_optymalizacji.at(il_fabr).at(centrum);

		return wyznacz_mac_opt(fabryka + 1, centrum);}
	/*sprawdzic, w ktorym miejscu jest kolejny 
	else if (macierz_optymalizacji.at(fabryka + 1).at(centrum)) { 
		macierz_optymalizacji.at(fabryka+1).at(il_centr) = macierz_optymalizacji.at(fabryka+1).at(centrum) - macierz_optymalizacji.at(il_fabr).at(centrum);

		return wyznacz_mac_opt(fabryka + 1, centrum);}
	else {
		macierz_optymalizacji.at(il_fabr).at(centrum+1) = macierz_optymalizacji.at(fabryka).at(centrum+1) - macierz_optymalizacji.at(fabryka).at(il_centr);
		return wyznacz_mac_opt(fabryka, centrum + 1);}

	*/


bool transport::czy_przejrzane(vector<bool>* v){
	for(vector<bool>::iterator it = v->begin(); it != v->end(); it++)
		if(!(*it)) return false;
	return true;
}

bool transport::przeszukaj_wiersz(int ind_wiersza){
	if(czy_przejrzane(&przejrzane_u)) return true;
	if(przejrzane_u.at(ind_wiersza)) return true;
	przejrzane_u.at(ind_wiersza) = true;
	for(int i = 0; i<il_centr; i++){
		if(macierz_optymalizacji.at(ind_wiersza).at(i) || przejazdy_zdegenerowane.at(ind_wiersza).at(i)){
			//znalezlismy niezerowy element, lub zdegenerowany
			macierz_optymalizacji.at(il_fabr).at(i) = macierz_optymalizacji.at(ind_wiersza).at(i) - macierz_optymalizacji.at(ind_wiersza).at(il_centr);
			przeszukaj_kolumne(i);
		}

	}
}

bool transport::przeszukaj_kolumne(int ind_kolumny){
	if(czy_przejrzane(&przejrzane_v)) return true;
	if(przejrzane_v.at(ind_kolumny)) return true;
	przejrzane_v.at(ind_kolumny) = true;
	for(int i = 0; i<il_fabr; i++){
		if(macierz_optymalizacji.at(i).at(ind_kolumny) || przejazdy_zdegenerowane.at(i).at(ind_kolumny)){
			//znalezlismy niezerowy element, lub zdegenerowany
			macierz_optymalizacji.at(i).at(il_centr) = macierz_optymalizacji.at(i).at(ind_kolumny) - macierz_optymalizacji.at(il_fabr).at(ind_kolumny);
			przeszukaj_wiersz(i);
		}

	}
}

bool transport::czy_element_samotny(bool typ, int w, int k){
	if(typ){//SPRAWDZAMY CZY ELEMENT JEST SAMOTNY W WIERSZU
		for(int i = 0; i< il_centr; i++){
			if(i ==k) continue;
			if(macierz_sciezek.at(w).at(i) || przejazdy_zdegenerowane.at(w).at(i)) return false;

		}
		return true;
	}
	else{//czy element samotny w kolumnie
		for(int i = 0; i<il_fabr; i++){
			if(i == w) continue;
			if(macierz_sciezek.at(i).at(k) || przejazdy_zdegenerowane.at(i).at(k)) return false;
		}
		return true;
	}

}