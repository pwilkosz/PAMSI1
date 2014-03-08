#include<iostream>
#include"algorytm.hh"
#include"statystyki.hh"
#include"operacje.hh"
/*!
 * \file
 * \brief plik glowny
 */
using namespace std;

int main(){
int N;
int M = 10;
ifstream plik1("plik1.txt");
ifstream plik2("plik2.txt");
plik1>>N;

mnozenie alg(plik1, plik2, N, M);

alg.wykonaj();

float* times = alg.jaki_czas();
cout<<times[4]<<endl;

  
return 0;
}
