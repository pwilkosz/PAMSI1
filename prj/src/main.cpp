#include<iostream>
#include"algorytm.hh"
#include"statystyki.hh"
#include"operacje.hh"
#include"stos.hh"
/*!
 * \file
 * \brief plik glowny
 */
using namespace std;

int main(){

int N;
int M = 5;
ifstream plik1("plik11.txt");
ifstream plik2("plik2.txt");
plik1>>N;
stos_lista alg(plik1, plik2, N, M);
int tabn[] = {10,100,1000,10000};
ofstream out("out1.csv");
for(int i = 0; i<4; i++){
alg.set_N(tabn[i]);
alg.wykonaj();
alg.zapisz_do_gnuplot(out);
}

  
return 0;
}
