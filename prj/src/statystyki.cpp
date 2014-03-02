#include "statystyki.hh"

float srednia (vector<float>& tab){
  float suma;
  unsigned int licznik = 0;
  
  
  while(licznik != tab.size()){
    suma +=tab[licznik];
    
    licznik++;}
  return static_cast<float>(suma/licznik);
  
}

float odchylenie_standardowe(float srednia, vector<float>& tab){
  float suma;
  unsigned int licznik;
  for(licznik = 0; licznik<tab.size(); licznik++)
    suma += powf(tab[licznik] - srednia, 2);
  return static_cast<float> (sqrt(suma/licznik));
}
