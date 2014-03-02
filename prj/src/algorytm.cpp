#include"algorytm.hh"

/*!
 * \file
 * \brief plik zawiera definicje metod klas zdefiniowanych w pliku algorytm.hh
 */
void algorytm::wykonaj(){
  ifstream we;
  we.open(plikWe);
  while(!we.eof()){
    char znak;
    we>>znak;
    cout<<znak<<endl;
  }
}
int algorytm::ile_danych(){
  return n;
}
vector<float> algorytm::jaki_czas(){
  return czas;
}

bool algorytm::porownaj(){
  ifstream wy, wzor;
  wy.open("przetworzone.txt");
  wzor.open(plikWz);
  int liczba1, liczba2;
  while((!wy.eof())||(!wzor.eof())){
    wy>>liczba1;
    wzor>>liczba2;
    if(liczba1 != liczba2) return false;
  }
  if(wy.eof() == wzor.eof()) return true;
  else return false;
}

void mnozenie::wykonaj(){
  ifstream we;
  we.open(plikWe);
  vector<int> dane;
  vector<int> dane_zmienione;
  int ilosc_danych;
  int ilosc_powtorzen;
  we>>ilosc_danych>>ilosc_powtorzen;
  this->n = ilosc_danych;
  int liczba;
  while(ilosc_danych !=0){
    we>>liczba;
    dane.push_back(liczba);
    --ilosc_danych;
  }
  we.close();
  
  while(ilosc_powtorzen !=0){
    ofstream wy;
    
   
    struct timeval tp;
    double start, end;
    gettimeofday(&tp, NULL);
    start = static_cast<double>(tp.tv_usec)/1E6;
  
    for(int k = 0; k<10; k++){
      wy.open("przetworzone.txt");
    for(unsigned int i = 0; i <dane.size();i++){
      
      liczba = 2* dane[i];
      wy<<liczba<<endl;
     
    }
     wy.close();
}
    gettimeofday(&tp, NULL);
    end = static_cast<double>(tp.tv_usec)/1E6;
    cout<<(end - start)<<endl;
    czas.push_back(end - start);
    
    --ilosc_powtorzen;
   
   
  }
  
if(porownaj()) cout<<"Weryfikacja poprawna"<<endl;
 else cout<<"cos nie tak"<<endl;
  }
