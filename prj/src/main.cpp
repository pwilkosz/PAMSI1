#include<iostream>
#include"algorytm.hh"
#include"statystyki.hh"
/*!
 * \file
 * \brief plik glowny
 */
using namespace std;

int main(){
  float sr;
  float odch_std;
  
  mnozenie alg("plik1.txt","plik2.txt");
  alg.wykonaj();
  // for(unsigned int i = 0; i<(alg.czas).size();i++)
  //	cout<<alg.czas[i]<<endl;
  sr = srednia(alg.czas);
  cout<<"wywolano"<<endl;
  odch_std = odchylenie_standardowe(sr, alg.czas);
  cout<<"srednia: "<<sr<<endl;
  cout<<"odchylenie: "<<odch_std<<endl;
return 0;
}
