#include<iostream>
#include"algorytm.hh"
#include"statystyki.hh"
#include"operacje.hh"
#include"stos.hh"
#include"tablica_asocjacyjna.hh"
#include"drzewo.hh"
#include"hashtab.hh"
#include<cstdlib>
#include<string>

/*!
 * \file
 * \brief plik glowny
 */
using namespace std;

int main(){

 /*
ofstream wyy("klucze.txt");
char napis[6];
for(int i = 0; i<1000000; i++){
  cout<<i<<endl;
  for(int k = 0; k<6; k++)
    napis[k] = rand()%24 + 65;
  wyy<<napis<<endl; 
}
*/
string tablica_skryptow[] = {"gnuplot skrypt1.pg","gnuplot skrypt2.pg","gnuplot skrypt3.pg","gnuplot skrypt4.pg","gnuplot skrypt5.pg","gnuplot skrypt6.pg","gnuplot skrypt7.pg","gnuplot skrypt8.pg","gnuplot skrypt9.pg","gnuplot skrypt10.pg","gnuplot skrypt11.pg", "gnuplot skrypt12.pg"};

//ifstream we("wejscie.txt");
int tabn[] = {10,100,1000,10000, 100000, 1000000};
int d = 6;
int N;
int M = 15;
int wybor = 0;

ifstream plik1("plik11.txt");
ifstream plik2("plik2.txt");
cout<<"b1"<<endl;
ifstream plik3("klucze.txt");
cout<<"b2"<<endl;
plik1>>N;
cout<<N<<endl;
while(!wybor){
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
  cout<<"* 10.BST                                                                   *"<<endl;
  cout<<"* 11.# table                                                               *"<<endl;
  cout<<"----------------------------------------------------------------------------"<<endl;
  cout<<"Twoj wybor: "<<flush;
  cin>>wybor;
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
    case 10: {
      bst alg(plik1, plik2, plik3, N, M);
      
      ofstream out("out1.csv");
      for(int i = 0; i<d; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
     case 11: {
      h_table alg(plik1, plik2, plik3, N, M);
      
      ofstream out("out2.csv");
      for(int i = 0; i<d; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    case 12: {
      tab_aso alg(plik1, plik2, plik3, N, M);
      
      ofstream out("out3.csv");
      for(int i = 0; i<d; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    default: {cout<<"Bledna opcja, sprobuj ponownie"<<wybor<<endl; wybor = 0; } break;
}
}

system(tablica_skryptow[wybor-1].c_str());
  
/*x.dodaj("pi", "liczba pi; wartosc 3.14");
x.dodaj("e", "liczba e; wartosc 2.728.");
x.dodaj("jeden", "jeden");
*/
/*cout<<x.pobierz("pi")<<endl;
x.usun("pi");
cout<<x.pobierz("pi")<<endl;
*/


return 0;
}
