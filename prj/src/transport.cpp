#include "transport.hh"




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

	T.wyznacz_mac_opt(0,0);
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
		for(int i = 0; i<il_fabr; i++){cout<<i<<endl;
			macierz_sciezek.at(i).at(k) = (macierz_sciezek.at(il_fabr).at(k)<macierz_sciezek.at(i).at(il_centr))?macierz_sciezek.at(il_fabr).at(k):macierz_sciezek.at(i).at(il_centr);
			cout<<"bb"<<endl;
			macierz_sciezek.at(il_fabr).at(k) -= macierz_sciezek.at(i).at(k);
			cout<<"bbb"<<endl;
			macierz_sciezek.at(i).at(il_centr) -= macierz_sciezek.at(i).at(k);
		}
		/*Przepisanie poszczegolnych elementow do macierzy optymalizacji*/
		cout<<"przepisanie"<<endl;
		for(int i = 0; i<il_fabr; i++)
			for(int k = 0; k<il_centr; k++){cout<<i<<k<<endl;cout<<il_centr<<endl;
				if(macierz_sciezek.at(i).at(k)!=0) {macierz_optymalizacji.at(i).at(k) = macierz_kosztow.at(i).at(k);}
			}
}

int transport::spr_mac_opt(){
	int wsk = 0;
	for(int i = 0; i<il_fabr; i++)
		for(int k = 0; k<il_centr; k++){
			if(macierz_optymalizacji.at(i).at(k)<wsk) wsk = macierz_optymalizacji.at(i).at(k);
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

bool transport::wyznacz_mac_opt(int fabryka, int centrum){cout<<fabryka<<centrum<<endl;
	
	/*warunek stopu*/
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
	/*sprawdzic, w ktorym miejscu jest kolejny */
	else if (macierz_optymalizacji.at(fabryka + 1).at(centrum)) { 
		macierz_optymalizacji.at(fabryka+1).at(il_centr) = macierz_optymalizacji.at(fabryka+1).at(centrum) - macierz_optymalizacji.at(il_fabr).at(centrum);

		return wyznacz_mac_opt(fabryka + 1, centrum);}
	else {
		macierz_optymalizacji.at(il_fabr).at(centrum+1) = macierz_optymalizacji.at(fabryka).at(centrum+1) - macierz_optymalizacji.at(fabryka).at(il_centr);
		return wyznacz_mac_opt(fabryka, centrum + 1);}

	/*Uzupelnienie wszystkich pol macierzy*/


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