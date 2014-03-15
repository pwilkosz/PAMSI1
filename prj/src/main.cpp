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
int M = 20;
ifstream plik1("plik1.txt");
ifstream plik2("plik2.txt");
plik1>>N;

stos_tablica alg(plik1, plik2, N, M, x2);

alg.wykonaj();

  
return 0;
}
