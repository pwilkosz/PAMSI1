#ifndef STOS_HH
#define STOS_HH
#include<list>


using namespace std;

enum flag{plus1, x2};

template <typename TYP>
class stack_list{
	list<TYP> st;
public:
	bool is_empty(){return st.empty();}
	int size(){return st.size();}
	void push(TYP& element){st.push_back(element);}
	TYP pop(){
		TYP temp = st.back();
		st.pop_back();
		return temp; 
	}
	void clear(){
		while(!is_empty())
			pop();
	}
};
template <typename TYP>
class stack_array{
	TYP* st;
	int s, sp; 
public:
	flag f;
	stack_array(){st = new TYP[0]; s = 0; sp = 0;} 
	stack_array(flag F):f(F){st = new TYP[0]; s = 0; sp = 0;}
	bool is_empty(){
		if(s == 0) return true;
		return false;
	}
	int size(){return s;}
	void push(TYP& element){
			if(f == plus1){
				int new_size = s + 1;
				TYP* tmp = new TYP[s];
				for(int i = 0; i<s; i++)
    			tmp[i] = st[i];
    			delete[] st;
    			st = new float[new_size];
  				for(int i = 0; i<s; i++)
  					st[i] = tmp[i];
  					st[s] = element;
  					s++;
			}
			else{
				if (s == 0){
					cout<<"mamy 0"<<endl;
					if(sp == 0){
						s++;
						cout<<"s powiekszone"<<endl;
						st = new TYP[s];sp = 1;
						st[s] = element;
						cout<<"breakpoint"<<endl;
						}
					else {st[0] = element; s++;}
				}
				else{
					if(sp>s){st[s] = element; s++;}
					else{
						int new_size = 2*s; 
						sp *= 2;
						TYP* tmp = new TYP[s];
						for(int i = 0; i<s; i++)
    					tmp[i] = st[i];
    					delete[] st;
    					st = new float[new_size];
  						for(int i = 0; i<s; i++)
  						st[i] = tmp[i];
  						st[s] = element;
  						s++;
					}
				}
			}
		}
	
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
		 		if(s <= 0.25*sp){
		 			sp = sp/2;
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
	void clear(){
		while(!is_empty())
			pop();
	}

};

#endif