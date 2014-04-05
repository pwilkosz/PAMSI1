#include<iostream>
#include"algorytm.hh"
#include"statystyki.hh"
#include"operacje.hh"
#include"stos.hh"
#include"tablica_asocjacyjna.hh"
#include<cstdlib>
#include<string>

/*!
 * \file
 * \brief plik glowny
 */
using namespace std;

int main(){/*
string tablica_skryptow[] = {"gnuplot skrypt1.pg","gnuplot skrypt2.pg","gnuplot skrypt3.pg","gnuplot skrypt4.pg","gnuplot skrypt5.pg","gnuplot skrypt6.pg","gnuplot skrypt7.pg","gnuplot skrypt8.pg","gnuplot skrypt9.pg"};

ifstream we("wejscie.txt");
int tabn[] = {10,100,1000,10000, 500000, 1000000};
int d = 6;
int N;
int M = 10;
int wybor = 0;
ifstream plik1("plik11.txt");
ifstream plik2("plik2.txt");
plik1>>N;
while(we>>wybor){
  /*------------------------MENU----------------------------------*/
  /*
  cout<<"***************MENU*********************************************************"<<endl;
  cout<<"* 1. Wypelnienie stosu  - lista                                            *"<<endl;
  cout<<"* 2. Wypelnienie stosu  - tablica na biezaco zmieniajaca pamiec            *"<<endl;
  cout<<"* 3. Wypelnienie stosu  - tablica podwajajaca pamiec                       *"<<endl;
  cout<<"* 4. Wypelnienie kolejki  - lista                                          *"<<endl;
  cout<<"* 5. Wypelnienie kolejki  - tablica na biezaco zmieniajaca pamiec          *"<<endl;
  cout<<"* 6. Wypelnienie kolejki  - tablica podwajajaca pamiec                     *"<<endl;
  cout<<"* 7. Sortowanie quicksort                                                  *"<<endl;
  cout<<"* 8. Sorotwanie heapsort                                                   *"<<endl;
  cout<<"* 9. Sortowanie mergesort                                                  *"<<endl;
  cout<<"----------------------------------------------------------------------------"<<endl;
  cout<<"Twoj wybor: "<<flush;
  
  cout<<endl;
  switch(wybor){
    case 1: {
      stos_lista alg(plik1, plik2, N, M);

      
      ofstream out("out1.csv");
      for(int i = 0; i<d; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    case 2: {
      stos_tablica alg(plik1, plik2, N, M, plus1);
     
      ofstream out("out1.csv");
      for(int i = 0; i<d; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    case 3: {
      stos_tablica alg(plik1, plik2, N, M, x2);
     
      ofstream out("out1.csv");
      for(int i = 0; i<d; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    case 4: {
      kolejka_lista alg(plik1, plik2, N, M);
      
      ofstream out("out1.csv");
      for(int i = 0; i<d; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    case 5: {
      kolejka_tablica alg(plik1, plik2, N, M, plus1);
      
      ofstream out("out1.csv");
      for(int i = 0; i<d; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    case 6: {
      kolejka_tablica alg(plik1, plik2, N, M, x2);
      
      ofstream out("out1.csv");
      for(int i = 0; i<d; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    case 7: {
      q_sort alg(plik1, plik2, N, M);
      
      ofstream out("out1.csv");
      for(int i = 0; i<d; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
        
      }
    } break;
    case 8: {
      h_sort alg(plik1, plik2, N, M);
      
      ofstream out("out1.csv");
      for(int i = 0; i<d; i++){
        alg.set_N(tabn[i]); 
        cout<<"n :"<<tabn[i]<<endl;;
        alg.wykonaj(out);
      }
    } break;
    case 9: {
      m_sort alg(plik1, plik2, N, M);
      
      ofstream out("out1.csv");
      for(int i = 0; i<d; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    default: {cout<<"Bledna opcja, sprobuj ponownie"<<wybor<<endl; wybor = 0; } break;
}}


system(tablica_skryptow[wybor-1].c_str());
  */
/*x.dodaj("pi", "liczba pi; wartosc 3.14");
x.dodaj("e", "liczba e; wartosc 2.728.");
x.dodaj("jeden", "jeden");
*/
/*cout<<x.pobierz("pi")<<endl;
x.usun("pi");
cout<<x.pobierz("pi")<<endl;
*/

tablica_asocjacyjna<float> x;

x.dodaj("e", 2.72);
x.dodaj("jeden", 1);
x.dodaj("dwa", 2);
x.dodaj("ec", 5-3.14);

x.usun("ec");
x.pobierz("e");
cout<<x.pobierz("jeden")<<endl;

return 0;
}
