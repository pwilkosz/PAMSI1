#ifndef STOS_HH
#define STOS_HH
#include<list>
/*!
  * \file
  * \brief Plik zawiera definicje klasy \p Stos Zaimplementowana na 2 sposoby 
  *	1. Za pomocą listy. 
  *	2. Za pomocą tablicy 
  *	a. kazdorazowo powiekszajacej swoj rozmiar 
  *	b. powiekszajacej swoj rozmiar dwukrotnie, gdy stos sie przepelni
*/

using namespace std;
/*! 
	* \brief typ wyliczeniowy sluzacy do ustawienia sposobu zwiekszania pamieci
	*/
enum flag{plus1, x2};
/*!
 *	\brief Modeluje stos oparty na liscie STL
*/
template <typename TYP>
class stack_list{
	list<TYP> st;
public:
	/*!
		\brief 
		\return false - gdy stos nie jest pusty, true , gdy pusty
	*/
	bool is_empty(){return st.empty();}
	/*! 
	 * \brief
	 * \return rozmiar ztosu
	*/
	int size(){return st.size();}
	/*! 
	 *	\brief Dodaje element na wierzch stosu
	*/
	void push(TYP& element){st.push_back(element);}
	/*!
	  * \brief zdejmuje element z wierzchu stosu
	*/
	TYP pop(){
		TYP temp = st.back();
		st.pop_back();
		return temp; 
	}
	/*!
		\brief czysci stos
	*/
	void clear(){
		while(!is_empty())
			pop();
	}
};
/*! 
	\brief Modeluje stos w oparciu o tablice
*/
template <typename TYP>
class stack_array{
	TYP* st;
	int s, sp; 
public:
	/*!
		\brief flaga trybu zwiekszania pamieci , przyjmuje wartosc : \n
		plus1 - dla trybu kazdorazowego powiekszania pamieci \n
		x2 - dla trybu podwajania rozmiaru struktury
	*/
	flag f;
	/*!
 		\brief konstruktor bezparametryczny
	*/
	stack_array(){st = new TYP[0]; s = 0; sp = 0;} 
	/*! \brief konstruktor parametryczny - ustawia flage na zadana pozycje*/
	stack_array(flag F):f(F){st = new TYP[0]; s = 0; sp = 0;}
	/*!
		\brief 
		\return false - gdy stos nie jest pusty, true , gdy pusty
	*/
	bool is_empty(){
		if(s == 0) return true;
		return false;
	}
	/*! 
	\brief
	\return rozmiar ztosu
	*/
	int size(){return s;}
	/*! 
		\brief Dodaje element na wierzch stosu w zaleznosci od wybranego trybu powiekszania tablicy
	*/
	void push(TYP element){ 
			if(f == plus1){
				int new_size = s + 1;
				TYP* tmp = new TYP[s];
				for(int i = 0; i<s; i++)
    			tmp[i] = st[i];
    			delete[] st;
    			st = new TYP[new_size];
  				for(int i = 0; i<s; i++)
  					st[i] = tmp[i];
  					st[s] = element;
  					s++;
  					delete[] tmp;
			}
			else{ 
				if (s == 0){ 
					
					if(sp == 0){ 
						s++;
						
						st = new TYP[s];sp = 1;
						
						st[sp-1] = element;
						
						
						}
					else {st[0] = element; s++;}
				}
				else{
					if(sp>s){st[s] = element; s++; }
					else{
						int new_size = 2*s; 
						sp *= 2;
						TYP* tmp = new TYP[s];
						for(int i = 0; i<s; i++)
    					tmp[i] = st[i];
    					delete[] st;
    					st = new TYP[new_size];
  						for(int i = 0; i<s; i++)
  						st[i] = tmp[i];
  						st[s] = element;
  						s++;
  						delete[] tmp;
					}
				}

			}
		}
	/*! \brief zdejmuje element ze stosu*/
	TYP pop(){
		TYP tmp;
		if(is_empty()){ cerr<<"stos pusty"<<endl; return 0;}
		else{
			s--;
			tmp = st[s];
			if(f == plus1){	
		 		if(is_empty()){
		 			delete[] st;
		 			st = new TYP[s];
		 			return tmp;
		 		}
		 		else{
		 			TYP* new_st = new TYP[s];
		 			for(int i = 0; i <s; i++ ) new_st[i] = st[i];
		 			delete[] st;
		 			st = new TYP[s];
		 			for(int i = 0; i<s; i++) st[i] = new_st[i];
		 			delete[] new_st;
		 		}}
		 	else{
		 		if(sp <= 0.25*s){
		 			s = s/2;
		 			TYP* new_st = new TYP[s];
		 			for(int i = 0; i<s; i++){
		 				st[i] = new_st[i];
		 			}
		 			delete[] st;
		 			st = new TYP[sp];
		 			for(int i = 0; i<s; i++){
		 				st[i] = new_st[i];
		 			}
		 			delete[] new_st;
		 		}}
		 		
		 		
		 		
		 	
		 		return tmp;
		 	}
		
	}
	/*! \brief czysci stos*/
	void clear(){
		while(!is_empty())
			pop();
	}

};

#endif