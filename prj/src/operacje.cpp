#include "operacje.hh"

bool operacje::zamien_elementy(int i, int j){
    if(i>n && j>n) return false;
    float tmp;
    tmp = tab[i];
    tab[i] = tab[j];
    tab[j] = tmp;
    return true;
    }

void operacje::odwroc_tablice(){
  //int rozmiar = sizeof(tab);
 
  float* tmp = new float[n];
  
  for(int i = 0; i<n; i++){
    tmp[i] = tab[n - 1 - i];
    
  }
  for(int i = 0; i<n; i++){
    tab[i] = tmp[i];
  }
  
}

void operacje::dodaj_element(float e){
  int rozmiar_nowy = n + 1;
  
  float* tmp = new float[n];
  
  for(int i = 0; i<n; i++){
    tmp[i] = tab[i];
  }
  
  tab = new float[rozmiar_nowy];
  
  for(int i = 0; i<n; i++){
  tab[i] = tmp[i];
  
  tab[n] = e;}
  
  
}

  void operacje::dodaj_elementy(float* tab2, int rozm){
  int rozmiar_nowy = n + rozm;
  float* tmp = new float[rozmiar_nowy];
  for(int i = 0; i<n; i++){
    tmp[i] = tab[i];
  }
  for( int j = 0; j<n; j++){
    tmp[j+n] = tab2[j];
  }
  tab = new float[rozmiar_nowy];

  for( int i = 0; i<rozmiar_nowy; i++){
    tab[i] = tmp[i];
  }
  
}

void operacje::operator = (float* tab1){
  for(int i = 0; i<n; i++){
    tab[i] = tab1[i];
  }
}

bool operacje::operator == (float* tab1){
  for(int i = 0; i<n; i++){
    if(tab[i] != tab1[i])return false;

  }
    return true;
}

