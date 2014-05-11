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
    cout<<"krok "<<i<<endl;
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

void bst::wczytaj_klucze(ifstream& plik){
  for(int i = 0; i<n; i++)
    plik>>klucze[i];
}

float bst::przelicz(){
  wlacz_zegar();
  d.znajdz(klucze[rand()%n]);
  wylacz_zegar();
  float cz = czas1+ czas2;

  
  return cz;
}
void h_table::wczytaj_klucze(ifstream& plik){
  cout<<n<<endl;
  for(int i = 0; i<n; i++)
    plik>>klucze[i];
  
}
float h_table::przelicz(){
  hashtab<float> H(n);
  
  for (int i = 0; i<n; i++){
    H.dodaj(klucze[i],1.3);
    
      }
  
  
      wlacz_zegar();
      //for(int z = 0; z<100;z++);
        
       
        
      H.znajdz(klucze[rand()%n]);
       
      wylacz_zegar();
        float cz = czas1 + czas2;

        return cz;
}

void tab_aso::wczytaj_klucze(ifstream& plik){
 
  for(int i = 0; i<n; i++){
    plik>>klucze[i];

  }
  cout<<"wczytano"<<endl;
}

float tab_aso::przelicz(){
  
  
  wlacz_zegar();
  d.znajdz(klucze[rand()%n]);
  wylacz_zegar();
  float cz = czas1+ czas2;

  
  return cz;
}

void graf_test::wczytaj_graf(){
  int id, wg, nr, il;
  ifstream in1("graf1.txt");
  ifstream in2("graf2.txt");
  ifstream in3("graf3.txt");
  ifstream in4("graf4.txt");
  ifstream in5("graf5.txt");
  ifstream in6("graf6.txt");
  for(int i = 0; i<10; i++)
    G1.dodaj_wierzcholek();
  for(int i = 0; i<100; i++)
    G2.dodaj_wierzcholek();
  for(int i = 0; i<1000; i++)
    G3.dodaj_wierzcholek();
  for(int i = 0; i<10000; i++)
    G4.dodaj_wierzcholek();
  for(int i = 0; i<50000; i++)
    G5.dodaj_wierzcholek();
  for(int i = 0; i<100000; i++)
    G6.dodaj_wierzcholek();
 
  /*dodano wierzcholki, teraz tworzymy liste incydencji*/
  for(int i = 0; i<10; i++){
    in1>>nr;
    for(int k = 0; k<5; k++){
      in1>>id>>wg;
      G1.dodaj_krawedz(i,id,wg);
    }
  }
  for(int i = 0; i<100; i++){
    in2>>nr;
    for(int k = 0; k<5; k++){
      in2>>id>>wg;
      G2.dodaj_krawedz(i,id,wg);
    }
  }
  for(int i = 0; i<1000; i++){
    in3>>nr;
    for(int k = 0; k<5; k++){
      in3>>id>>wg;
      G3.dodaj_krawedz(i,id,wg);
    }
  }
  for(int i = 0; i<10000; i++){
    in4>>nr;
    for(int k = 0; k<5; k++){
      in4>>id>>wg;
      G4.dodaj_krawedz(i,id,wg);
    }
  }
  for(int i = 0; i<50000; i++){
    in5>>nr;
    for(int k = 0; k<5; k++){
      in5>>id>>wg;
      G5.dodaj_krawedz(i,id,wg);
    }
  }
  for(int i = 0; i<100000; i++){
    in6>>nr;
    for(int k = 0; k<5; k++){
      in6>>id>>wg;
      G6.dodaj_krawedz(i,id,wg);
    }
  }
 G1.rysuj();
 
}
float graf_test::przelicz(){
  srand(time(NULL));
  if(typ == 0){
    wlacz_zegar();
    switch(n){
      case 10: G1.dfs(rand()%n); break;
      case 100: G2.dfs(rand()%n); break;
      case 1000: G3.dfs(rand()%n); break;
      case 10000: G4.dfs(rand()%n); break;
      case 50000: G5.dfs(rand()%n); break;
      case 100000: G6.dfs(rand()%n); break;
    }
  }
  else if(typ == 1){
    wlacz_zegar();
    switch(n){
      case 10: G1.bfs(rand()%n); break;
      case 100: G2.bfs(rand()%n); break;
      case 1000: G3.bfs(rand()%n); break;
      case 10000: G4.bfs(rand()%n); break;
      case 50000: G5.bfs(rand()%n); break;
      case 100000: G6.bfs(rand()%n); break;
    }
  }
  else if(typ ==2){
    wlacz_zegar();
    switch(n){
      case 10: G1.best_first(rand()%n); break;
      case 100: G2.best_first(rand()%n); break;
      case 1000: G3.best_first(rand()%n); break;
      case 10000: G4.best_first(rand()%n); break;
      case 50000: G5.best_first(rand()%n); break;
      case 100000: G6.best_first(rand()%n); break;
    }
  }
  
  wylacz_zegar();
  float cz = czas1 + czas2;
  return cz;
}


void astar::wczytaj_graf(){
  int id, wg, nr, il;
  ifstream in1("graf1.txt");
  ifstream in2("graf2.txt");
  ifstream in3("graf3.txt");
  ifstream in4("graf4.txt");
  ifstream in5("graf5.txt");
  ifstream in6("graf6.txt");
   for(int i = 0; i<10; i++)
    G1.dodaj_wierzcholek(i);
  for(int i = 0; i<100; i++)
    G2.dodaj_wierzcholek(i);
  for(int i = 0; i<1000; i++)
    G3.dodaj_wierzcholek(i);
  for(int i = 0; i<10000; i++)
    G4.dodaj_wierzcholek(i);
  for(int i = 0; i<50000; i++)
    G5.dodaj_wierzcholek(i);
  for(int i = 0; i<100000; i++)
    G6.dodaj_wierzcholek(i);

   for(int i = 0; i<10; i++){
    in1>>nr;
    for(int k = 0; k<5; k++){
      in1>>id>>wg;
     
      G1.dodaj_krawedz(i,id);
      
    }
  }
  for(int i = 0; i<100; i++){
    in2>>nr;
    for(int k = 0; k<5; k++){
      in2>>id>>wg;
      G2.dodaj_krawedz(i,id);
    }
  }
  for(int i = 0; i<1000; i++){
    in3>>nr;
    for(int k = 0; k<5; k++){
      in3>>id>>wg;
      G3.dodaj_krawedz(i,id);
    }
  }
  for(int i = 0; i<10000; i++){
    in4>>nr;
    for(int k = 0; k<5; k++){
      in4>>id>>wg;
      G4.dodaj_krawedz(i,id);
    }
  }
  for(int i = 0; i<50000; i++){
    in5>>nr;
    for(int k = 0; k<5; k++){
      in5>>id>>wg;
      G5.dodaj_krawedz(i,id);
    }
  }
  for(int i = 0; i<100000; i++){
    in6>>nr;
    for(int k = 0; k<5; k++){
      in6>>id>>wg;
      G6.dodaj_krawedz(i,id);
    }
  }

}

float astar::przelicz(){
   wlacz_zegar();
    switch(n){
      case 10: G1.a_star(0, rand()%n); break;
      case 100: G2.a_star(0, rand()%n); break;
      case 1000: G3.a_star(0, rand()%n); break;
      case 10000: G4.a_star(0, rand()%n); break;
      case 50000: G5.a_star(0, rand()%n); break;
      case 100000: G6.a_star(0, rand()%n); break;
    }
     wylacz_zegar();
  float cz = czas1 + czas2;
  return cz;
}