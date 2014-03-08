#include"algorytm.hh"



/*!
 * \file
 * \brief plik zawiera definicje metod klas zdefiniowanych w pliku algorytm.hh
 */
void algorytm::przelicz(){for(int i = 0; i<n ; i++){cout<<"KROK: "<<i<<endl; cout<<dane[i]<<endl;}}
bool algorytm::wczytaj(ifstream& plik){
 
  dane = new float[n];
  
  for(int i = 0; i<n; i++){
    plik>>dane[i];
    cout<<dane[i]<<endl;
    if(plik.fail()){cerr<<"Wystapil problem z wczytaniem pliku"; return false;}
  }
    op = dane;
    return true;
}
bool algorytm::wczytaj_wzor(ifstream& plik){
 
  dane_wz = new float[n];
  for(int i = 0; i<n; i++){
    plik>>dane_wz[i];
    if(plik.fail()){cerr<<"Wystapil problem z wczytaniem pliku wzorcowego"; return false;}
  }
    return true;
}
int algorytm::ile_danych(){
  return n;
}
float* algorytm::jaki_czas(){
  return czas;
}

float algorytm::wlacz_zegar(){
  struct timeval tp;
    double start;
    gettimeofday(&tp, NULL);
    start = static_cast<double>(tp.tv_usec)/1E6;
    return start;
}

float algorytm::wylacz_zegar(){
  struct timeval tp;
    double end;
    gettimeofday(&tp, NULL);
    end = static_cast<double>(tp.tv_usec)/1E6;
    return end;
}
void algorytm::wykonaj(){
  czas = new float[m];
  for(int i = 0; i<m; i++){
  float start= wlacz_zegar();
  przelicz();
  float cz = wylacz_zegar() - start;
  if(porownaj()) cout<<"PROBA NR "<<i<<":  poprawna"<<endl;
  else cout<<"PROBA NR "<<i<<":  niepoprawna"<<endl;
  czas[i] = cz;
  op = dane;
  
}
zapisz_do_csv();
}

bool algorytm::porownaj(){
 
    return op == dane_wz;
  }

  void algorytm::zapisz_do_csv(){
  ofstream tab_czas("wyjscie.csv");
  tab_czas<<"Proba [m],"<<"Czas"<<endl;
  for(int i =0; i<m; i++){
      tab_czas<<(i+1)<<","<<czas[i]<<endl;
  }
}

void mnozenie::przelicz(){
    for(int i =0; i<n; i++){
      op.tab[i] = 2*dane[i];
          }
          
  }

