#include "statystyki.hh"

float srednia (float* tab, int rozmiar){
  float suma;
  int licznik = 0;
  
  
  while(licznik != rozmiar){
    suma +=tab[licznik];
    
    licznik++;}
  return static_cast<float>(suma/licznik);
  
}

float odchylenie_standardowe(float srednia, float* tab, int rozmiar){
  float suma = 0;
  int licznik;
  for(licznik = 0; licznik<rozmiar; licznik++)
    suma += powf(tab[licznik] - srednia, 2);
  return static_cast<float> (sqrt(suma/licznik));
}
