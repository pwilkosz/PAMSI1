#include"algorytm.hh"
#include"statystyki.hh"


/*!
 * \file
 * \brief plik zawiera definicje metod klas zdefiniowanych w pliku algorytm.hh
 */
float algorytm::przelicz(){for(int i = 0; i<n ; i++){cout<<"KROK: "<<i<<endl; cout<<dane[i]<<endl;}return 0;}
bool algorytm::wczytaj(ifstream& plik){
 
  dane = new float[n];
  
  for(int i = 0; i<n; i++){
    plik>>dane[i];
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
    start = static_cast<float>(tp.tv_usec)/1E3;
    return start;
}

float algorytm::wylacz_zegar(){
  struct timeval tp;
    double end;
    gettimeofday(&tp, NULL);
    end = static_cast<float>(tp.tv_usec)/1E3;
    return end;
}

void algorytm::zapisz_do_csv(ofstream& out){
  ofstream tab_czas("wyjscie.csv");
  tab_czas<<"Proba [m],"<<"Czas"<<endl;
  for(int i =0; i<m; i++){
      tab_czas<<(i+1)<<","<<czas[i]<<endl;
  }
  float sr = srednia(czas,m);
  float odchylenie = odchylenie_standardowe(sr,czas,m);
  tab_czas<<"Srednia,"<<sr<<endl;
  tab_czas<<"Odchylenie,"<<odchylenie<<endl;
  cout<<"zapisano do wyjscie.csv"<<endl;
  zapisz_do_gnuplot(out,sr,odchylenie);
  
}


void algorytm::wykonaj(ofstream& out){
  
  for(int i = 0; i<m; i++){
  float cz = przelicz();
  
  
  if(porownaj()) cout<<"PROBA NR "<<i<<":  poprawna"<<endl;
  else cout<<"PROBA NR "<<i<<":  niepoprawna"<<endl;
  
  czas[i] = cz;
 
  op = dane;
  
}

zapisz_do_csv(out);


}

bool algorytm::porownaj(){
 
    return op == dane_wz;
  }

  

void algorytm::zapisz_do_gnuplot(ofstream& out, float sr, float od){
  
  
  out<<n<<" "<<sr<<" "<<"0 "<<od<<endl;
 
}

float mnozenie::przelicz(){
    float start = wlacz_zegar();
    for(int i =0; i<n; i++){
      op.tab[i] = 2*dane[i];
      }float end = wylacz_zegar();
    float cz = end - start;
    if(cz<0) cz += 1000;
    return cz;
    }
          
  
float stos_tablica::przelicz(){
  float start = wlacz_zegar();
  for(int i = 0; i<n; i++){
    stos.push(op.tab[i]);
  }
  float end = wylacz_zegar();
  float cz = end - start;
  if(cz<0) cz += 1000;
  stos.clear();
  return cz;
}

float stos_lista::przelicz(){
  float start = wlacz_zegar();
  for(int i = 0; i<n; i++){
    stos.push(op.tab[i]);
  }
  float end = wylacz_zegar();
  float cz = end - start;
  if(cz<0) cz += 1000;
  stos.clear();
  return cz;
}

float kolejka_tablica::przelicz(){
  float start = wlacz_zegar();
  for(int i = 0; i<n; i++){
    
    qu.enqueue(op.tab[i]);
  }
  float end = wylacz_zegar();
  float cz = end - start;
  if(cz<0) cz += 1000;
  qu.clear();
  return cz;
}

float kolejka_lista::przelicz(){
  float start = wlacz_zegar();
  for(int i = 0; i<n; i++){
    qu.enqueue(op.tab[i]);
  }
  float end = wylacz_zegar();
  float cz = end - start;
  if(cz<0) cz += 1000;
  qu.clear();
  return cz;
}

float q_sort::przelicz(){
  float start = wlacz_zegar();
  op.quick_sort(0,n-1);
  float end = wylacz_zegar();
  float cz = end - start;
  if(cz<0) cz += 1000;
  return cz;

}

float h_sort::przelicz(){
  float start = wlacz_zegar();
  op.heap_sort();
  float end = wylacz_zegar();
  float cz = end - start;
  if(cz<0) cz += 1000;
  return cz;

}

float m_sort::przelicz(){
  float start = wlacz_zegar();
  op.merge_sort(0,n-1);
  float end = wylacz_zegar();
  float cz = end - start;
  if(cz<0) cz += 1000;
  cout<<"jestem w przelicz"<<endl;
  return cz;

}