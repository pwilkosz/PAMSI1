#include<iostream>
#include"algorytm.hh"
#include"statystyki.hh"
#include"operacje.hh"
#include"stos.hh"
#include"tablica_asocjacyjna.hh"
#include"drzewo.hh"
#include"hashtab.hh"
#include"graf.hh"
#include"simplex.hh"
#include"transport.hh"
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

string tablica_skryptow[] = {"gnuplot skrypt1.pg","gnuplot skrypt2.pg","gnuplot skrypt3.pg",
"gnuplot skrypt4.pg","gnuplot skrypt5.pg","gnuplot skrypt6.pg",
"gnuplot skrypt7.pg","gnuplot skrypt8.pg","gnuplot skrypt9.pg",
"gnuplot skrypt10.pg","gnuplot skrypt11.pg", "gnuplot skrypt12.pg",
"gnuplot skrypt13.pg", "gnuplot skrypt14.pg", "gnuplot skrypt15.pg",
"gnuplot skrypt16.pg"};

//ifstream we("wejscie.txt");
int tabn[] = {10,100,1000,10000, 50000, 100000};
int d = 6;
int N;
int M = 10;
int wybor = 0;

ifstream plik1("plik11.txt");
ifstream plik2("plik2.txt");

ifstream plik3("klucze.txt");

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
  cout<<"* 12.tablica_asocjacyjna                                                   *"<<endl;
  cout<<"* 13.Depth first search                                                    *"<<endl;
  cout<<"* 14.Breadth first search                                                  *"<<endl;
  cout<<"* 15.Best first search                                                     *"<<endl;
  cout<<"* 16.A*                                                                    *"<<endl;
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
    case 13: {
     graf_test alg(plik1, plik2, N, M, 0);
      
      ofstream out("out1.csv");
      for(int i = 0; i<d; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    case 14: {
     graf_test alg(plik1, plik2, N, M, 1);
      
      ofstream out("out2.csv");
      for(int i = 0; i<d; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    case 15: {
     graf_test alg(plik1, plik2, N, M, 2);
      
      ofstream out("out3.csv");
      for(int i = 0; i<d; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    case 16: {
     astar alg(plik1, plik2, N, M);
      
      ofstream out("out4.csv");
      for(int i = 0; i<d; i++){
        alg.set_N(tabn[i]); 
        alg.wykonaj(out);
      }
    } break;
    default: {cout<<"Bledna opcja, sprobuj ponownie"<<wybor<<endl; wybor = 0; } break;
}//koniec switch
}

system(tablica_skryptow[wybor-1].c_str());
  
/*
graf G;
wierzcholek w(0,1);
G.dodaj_wierzcholek(w);
wierzcholek e(1,2);
G.dodaj_wierzcholek(e);
wierzcholek r(2,3);
G.dodaj_wierzcholek(r);
wierzcholek t(3,4);
G.dodaj_wierzcholek(t);
wierzcholek y(4,5);
G.dodaj_wierzcholek(y);
wierzcholek u(5,6);
G.dodaj_wierzcholek(u);
G.dodaj_krawedz(w,e,4);
G.dodaj_krawedz(w,y,19);
G.dodaj_krawedz(w,r,8);
G.dodaj_krawedz(t,y,7);
//G.dodaj_krawedz(u,y,7);
G.dodaj_krawedz(u,w,7);
G.dodaj_krawedz(t,r,7);

G.wypisz_liste();
G.best_first(3);
*/

graf G;
for(int i = 0; i<9; i++)
  G.dodaj_wierzcholek(i);
G.dodaj_krawedz(0,2);
G.dodaj_krawedz(0,6);
G.dodaj_krawedz(0,8);
G.dodaj_krawedz(1,3);
G.dodaj_krawedz(4,2);
G.dodaj_krawedz(1,5);
G.dodaj_krawedz(3,7);
G.dodaj_krawedz(7,6);
G.a_star(0,1);


/*losowanie do grafu
ofstream o1("graf1.txt");
ofstream o2("graf2.txt");
ofstream o3("graf3.txt");
ofstream o4("graf4.txt");
ofstream o5("graf5.txt");
ofstream o6("graf6.txt");
srand(time(NULL));
  
for(int i = 0; i<tabn[0]; i++)
  o1<<i<<" "<<rand()%tabn[0]<<" "<<rand()%100<<" "<<rand()%tabn[0]<<" "<<rand()%100<<" "<<rand()%tabn[0]<<" "<<rand()%100<<" "<<rand()%tabn[0]<<" "<<rand()%100<<" "<<rand()%tabn[0]<<" "<<rand()%100<<endl;

for(int i = 0; i<tabn[1]; i++)
  o2<<i<<" "<<rand()%tabn[1]<<" "<<rand()%100<<" "<<rand()%tabn[1]<<" "<<rand()%100<<" "<<rand()%tabn[1]<<" "<<rand()%100<<" "<<rand()%tabn[1]<<" "<<rand()%100<<" "<<rand()%tabn[1]<<" "<<rand()%100<<endl;

for(int i = 0; i<tabn[2]; i++)
  o3<<i<<" "<<rand()%tabn[2]<<" "<<rand()%100<<" "<<rand()%tabn[2]<<" "<<rand()%100<<" "<<rand()%tabn[2]<<" "<<rand()%100<<" "<<rand()%tabn[2]<<" "<<rand()%100<<" "<<rand()%tabn[2]<<" "<<rand()%100<<endl;

for(int i = 0; i<tabn[3]; i++)
  o4<<i<<" "<<rand()%tabn[3]<<" "<<rand()%100<<" "<<rand()%tabn[3]<<" "<<rand()%100<<" "<<rand()%tabn[3]<<" "<<rand()%100<<" "<<rand()%tabn[3]<<" "<<rand()%100<<" "<<rand()%tabn[3]<<" "<<rand()%100<<endl;

for(int i = 0; i<tabn[4]; i++)
  o5<<i<<" "<<rand()%tabn[4]<<" "<<rand()%100<<" "<<rand()%tabn[4]<<" "<<rand()%100<<" "<<rand()%tabn[4]<<" "<<rand()%100<<" "<<rand()%tabn[4]<<" "<<rand()%100<<" "<<rand()%tabn[4]<<" "<<rand()%100<<endl;

for(int i = 0; i<tabn[5]; i++)
  o6<<i<<" "<<rand()%tabn[5]<<" "<<rand()%100<<" "<<rand()%tabn[5]<<" "<<rand()%100<<" "<<rand()%tabn[5]<<" "<<rand()%100<<" "<<rand()%tabn[5]<<" "<<rand()%100<<" "<<rand()%tabn[5]<<" "<<rand()%100<<endl;

*/

zbierz_dane();
//cout<<"zmienna niebazowa: "<<S.wez_zmienna_niebazowa()<<" , zmienna bazowa: "<<S.zmienna_bazowa_do_wymiany()<<endl;

//cout<<"zamien zwraca: "<<S.zamien(1,5)<<endl;



return 0;
}

