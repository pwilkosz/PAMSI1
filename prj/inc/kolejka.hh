#ifndef KOLEJKA_HH
#define KOLEJKA_HH
#include<list>
#include"stos.hh"
using namespace std;

/*!
	* \file
  * \brief Plik zawiera definicje klasy Kolejka Zaimplementowanej na 2 sposoby 
  	1. Za pomocą listy. 
  	2. Za pomocą tablicy 
  	a. kazdorazowo powiekszajacej swoj rozmiar 
  	b. powiekszajacej swoj rozmiar dwukrotnie, gdy kolejka sie przepelni
*/
/*!
	\brief Modeluje kolejke oparta na liscie STL
*/
template<typename TYP>
class queue_list{
list<TYP> q;
public:
	/*!
		\brief 
		\return false - gdy kolejka nie jest pusta, true , gdy pusta
	*/
	bool is_empty(){return q.empty();}
	/*! 
	\brief
	\return rozmiar kolejki
	*/
	int size(){return q.size();}
	/*! \brief dodaje element*/
	void enqueue(TYP& element){q.push_back(element);}
	/*! \brief usuwa element*/
	TYP dequeue(){
		TYP temp = q.front();
		q.pop_front();
		return temp; 
	}
	/*! \brief czysci stos*/
	void clear(){
		while(!is_empty())
			dequeue();
	}
};
/*! 
	\brief Modeluje kolejke w oparciu o tablice
*/
template<typename TYP>
class queue_array{
	TYP* q;
	int s, sp;
public:
	/*!
		\brief flaga trybu zwiekszania pamieci , przyjmuje wartosc : 
		plus1 - dla trybu kazdorazowego powiekszania pamieci 
		x2 - dla trybu podwajania rozmiaru struktury
	*/
	flag f;
	/*!
 		\brief konstruktor bezparametryczny
	*/
	queue_array(){q = new TYP[0]; s = 0; sp = 0;}
	/*! \brief konstruktor parametryczny - ustawia flage na zadana pozycje*/
	queue_array(flag F):f(F) {q = new TYP[0]; s = 0;sp = 0;}
	/*! \brief 
		\return rozmiar kolejki
				
		*/
	int size(){return s;}
		/*!
		\brief 
		\return false - gdy kolejka nie jest pusta, true , gdy pusta
	*/
	bool is_empty(){
		if(s == 0) return true;
		return false;
	}
	/*! 
		\brief Dodaje element na poczatek kolejki w zaleznosci od wybranego trybu powiekszania tablicy
	*/
	void enqueue(TYP& element){
		if(s==0){
			s++; 
			q = new TYP[s];
			q[0] = element;
			sp = 1;
		}
		else{
		/*Dla plus1*/
		if(f == plus1){
			TYP* tmp = new TYP[s];
			for(int i = 0; i<s; i++)
				tmp[i] = q[i];
			delete[] q;
			q = new TYP[s+1];
			for(int i = 0; i<s; i++)
				q[i] = tmp[i];
			delete[] tmp;
			q[s] = element;
			s++;
		}
		/*Dla x2*/
		else{
			if(sp>s){	//gdy nie trzeba powiekszac tablicy
				q[s] = element;
				s++;
				
			}
			else{		//gdy trzeba powiekszac tablice
				int new_size = 2*s;
				sp =sp*2;
				TYP* tmp = new TYP[s];
				for(int i = 0; i<s; i++)
					tmp[i] = q[i];
				delete[] q;
				q = new TYP[new_size];
				for(int i = 0; i<s; i++)
					q[i] = tmp[i];
				q[s] = element;
				s++;
				delete[] tmp;
			}
		}
		
	}
	}
	/*! \brief usuwa element z konca kolejki*/
	TYP dequeue(){
		if(is_empty()) {cerr<<"kolejka pusta!"<<endl; return 0;}
		TYP temp = q[0];
		if(s == 1){
			delete[] q;
			s = 0;
		}
		else{
			/*Dla plus1*/
			if(f == plus1){
				TYP* tmp = new TYP[s-1];
				for(int i = 0; i<(s-1); i++)
					tmp[i] = q[i+1];
				delete[] q;
				s--;
				q = new TYP[s];
				for(int i = 0; i<s; i++)
					q[i] = tmp[i];
				delete[] tmp;
			}
			/*Dla plus2*/
			else{
				if(s<0.25*sp){		//gdy trzeba zmniejszac tablcie
					sp = sp/2;
					TYP* tmp = new TYP[s];
					for(int i = 0; i<(s-1); i++)
						tmp[i] = q[i+1];
					delete[] q;
					q = new TYP[sp];
					for(int i = 0; i<(s-1); i++)
						q[i] = tmp[i];
					delete[] tmp;
				}
				else{				//gdy nie zmniejszamy
					for(int i = 0; i<(s-1); i++ )
						q[i] = q[i+1];

				}
			}
			s--;
		}
		return temp;
	}
	/*! \brief czysci kolejke*/
	void clear(){
		while(!is_empty()){
			dequeue();
		}
	}
};

#endif