#include<iostream>
#include"algorytm.hh"
#include"statystyki.hh"
#include"operacje.hh"
#include"stos.hh"
#include<cstdlib>
/*!
 * \file
 * \brief plik glowny
 */
using namespace std;

int main(){


int N;
int M = 5;
char wybor = 0;
ifstream plik1("plik1.txt");
ifstream plik2("plik2.txt");
plik1>>N;
while(wybor == 0){
  /*------------------------MENU----------------------------------*/
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
  cin>>wybor;
  cout<<endl;
  switch(wybor){
    case '1': {
      stos_lista alg(plik1, plik2, N, M);
      int tabn[] = {10,100,1000,10000};
      ofstream out("out1.csv");
      for(int i = 0; i<4; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    case '2': {
      stos_tablica alg(plik1, plik2, N, M, plus1);
      int tabn[] = {10,100,1000,10000};
      ofstream out("out1.csv");
      for(int i = 0; i<4; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    case '3': {
      stos_tablica alg(plik1, plik2, N, M, x2);
      int tabn[] = {10,100,1000,10000};
      ofstream out("out1.csv");
      for(int i = 0; i<4; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    case '4': {
      kolejka_lista alg(plik1, plik2, N, M);
      int tabn[] = {10,100,1000,10000};
      ofstream out("out1.csv");
      for(int i = 0; i<4; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    case '5': {
      kolejka_tablica alg(plik1, plik2, N, M, plus1);
      int tabn[] = {10,100,1000,10000};
      ofstream out("out1.csv");
      for(int i = 0; i<4; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    case '6': {
      kolejka_tablica alg(plik1, plik2, N, M, x2);
      int tabn[] = {10,100,1000,10000};
      ofstream out("out1.csv");
      for(int i = 0; i<4; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    case '7': {
      q_sort alg(plik1, plik2, N, M);
      int tabn[] = {10,100,1000,10000};
      ofstream out("out1.csv");
      for(int i = 0; i<4; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    case '8': {
      h_sort alg(plik1, plik2, N, M);
      int tabn[] = {10,100,1000,10000};
      ofstream out("out1.csv");
      for(int i = 0; i<4; i++){
        alg.set_N(tabn[i]); 
        cout<<"n :"<<tabn[i]<<endl;;
        alg.wykonaj(out);
      }
    } break;
    case '9': {
      m_sort alg(plik1, plik2, N, M);
      int tabn[] = {10,100,1000,10000};
      ofstream out("out1.csv");
      for(int i = 0; i<4; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    default: {cout<<"Bledna opcja, sprobuj ponownie"<<endl; wybor = 0; } break;
}}


system("gnuplot skrypt.pg");
  
return 0;
}
