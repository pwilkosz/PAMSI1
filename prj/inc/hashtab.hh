#ifndef HASHTAB_HH
#define HASHTAB_HH
#include<vector>
template<typename TYP>
class el_tab{
public:
	string klucz;
	TYP wart;
	bool zajety;
	el_tab():zajety(false){}
	~el_tab(){}
};
template<typename TYP>
class hashtab{
	int dlugosc;
	vector<el_tab<TYP> > tab;
public:
	void ustaw_dlugosc(int d){dlugosc = d;}
	hashtab(){}
	hashtab(int N):tab(N){ ustaw_dlugosc(N);}
	int hash(string k){
		int h = 0;
		for(unsigned int i = 0; i<k.length(); i++){
			h = abs(h*101 + abs(k[i]));	
		}
		return h;
	}
	void dodaj(string k, TYP v){
		
		int i =1;
		int ind = hash(k)%dlugosc;
		
		while(tab[ind].zajety){
			ind = (ind + i)%dlugosc;
			i*=113;  
		}
		tab[ind].wart = v; tab[ind].klucz = k;
	}
	el_tab<TYP>* znajdz(string k){
		cout<<"k "<<k<<endl;
		int i = 1;
		int ind = hash(k)%dlugosc;
		if(!tab[ind].zajety) return NULL;
		else{
			while(tab[ind].klucz!= k){
				ind = (ind + i)%dlugosc;
				i*=113;  
			}
			
			return &tab[ind];}
	}
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