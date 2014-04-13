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
	unsigned long hash(string k){
		long h = 0;
		for(unsigned int i = 0; i<k.length(); i++){
			h = abs(h*101 + abs(k[i]));	
		}
		return h;
	}
	void dodaj(string k, TYP v){
		
		int i =0;
		unsigned long ind = hash(k)%dlugosc;
		
		while(tab[ind].zajety){
			ind = (ind + i)%dlugosc;
			i+=1889;
			
		}
		tab[ind].wart = v; tab[ind].klucz = k; tab[ind].zajety = true;
	}
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