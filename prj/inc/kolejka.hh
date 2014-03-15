#ifndef KOLEJKA_HH
#define KOLEJKA_HH
#include<list>
#include"stos.hh"
using namespace std;



template<typename TYP>
class queue_list{
list<TYP> q;
public:
	bool is_empty(){return q.empty();}
	int size(){return q.size();}
	void enqueue(TYP& element){q.push_back(element);}
	TYP dequeue(){
		TYP temp = q.front();
		q.pop_front();
		return temp; 
	}
	void clear(){
		while(!is_empty())
			dequeue();
	}
};

template<typename TYP>
class queue_array{
	TYP* q;
	int s, sp;
public:
	flag f;
	queue_array(){q = new TYP[0]; s = sp = 0;}
	queue_array(flag F):f(F) {q = new TYP[0]; s = sp = 0;}
	int size(){return s;}
	bool is_empty(){
		if(s == 0) return true;
		return false;
	}
	void enqueue(TYP& element){
		if(s==0){
			s++;
			q = new TYP[s];
			q[0] = element;
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
				
			}
		}
		s++;
	}
	}
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
	void clear(){
		while(!is_empty()){
			dequeue();
		}
	}
};

#endif