#include"algorytm.hh"
#include"statystyki.hh"
#include<time.h>

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

void algorytm::wlacz_zegar(){
  //struct timeval tp;
    struct timespec tp;
    clock_gettime(CLOCK_REALTIME, &tp);
    //gettimeofday(&tp, NULL);
    czas2 = tp.tv_nsec;
    czas1 = tp.tv_sec;
    
    
}

void algorytm::wylacz_zegar(){
  //struct timeval tp;
    //double end;
    //gettimeofday(&tp, NULL);
    struct timespec tp;
    clock_gettime(CLOCK_REALTIME, &tp);
    czas2 = static_cast<double>(tp.tv_nsec - czas2)/1E9;
    czas1 = static_cast<double>(tp.tv_sec - czas1);
    
   
    
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
  zapisz_do_gnuplot(out,sr,odchylenie);

  
}


void algorytm::wykonaj(ofstream& out){
  
  for(int i = 0; i<m; i++){
  float cz = przelicz();
  
  
 //if(porownaj()) cout<<"PROBA NR "<<i<<":  poprawna"<<endl;
 //else cout<<"PROBA NR "<<i<<":  niepoprawna"<<endl;
  
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
  cout<<n<<" "<<sr<<" "<<"0 "<<od<<endl;
 
}

float mnozenie::przelicz(){
    wlacz_zegar();
    for(int i =0; i<n; i++){
      op.tab[i] = 2*dane[i];
      }wylacz_zegar();
    float cz = czas1+czas2;
    
    return cz;
    }
          
  
float stos_tablica::przelicz(){
  wlacz_zegar();
  for(int i = 0; i<n; i++){
    stos.push(op.tab[i]);
  }
  wylacz_zegar();
  float cz = czas1+czas2;
  stos.clear();
  return cz;
}

float stos_lista::przelicz(){
  wlacz_zegar();
  for(int i = 0; i<n; i++){
    stos.push(op.tab[i]);
  }
  wylacz_zegar();
  float cz = czas1+czas2;
  
  stos.clear();
  return cz;
}

float kolejka_tablica::przelicz(){
  wlacz_zegar();
  for(int i = 0; i<n; i++){
    
    qu.enqueue(op.tab[i]);
  }
  wylacz_zegar();
  float cz = czas1+czas2;
  qu.clear();
  return cz;
}

float kolejka_lista::przelicz(){
  wlacz_zegar();
  for(int i = 0; i<n; i++){
    qu.enqueue(op.tab[i]);
  }
  wylacz_zegar();
  float cz = czas1+czas2;
  qu.clear();
  return cz;
}

float q_sort::przelicz(){
  wlacz_zegar();
  op.quick_sort(0,n-1);
  wylacz_zegar();
  float cz = czas1+czas2;
  return cz;

}

float h_sort::przelicz(){
  wlacz_zegar();
  op.heap_sort();
  wylacz_zegar();
 float cz = czas1+czas2;
  return cz;

}

float m_sort::przelicz(){
  wlacz_zegar();
  op.merge_sort(0,n-1);
  wylacz_zegar();
  float cz = czas1+czas2;
  
  return cz;

}