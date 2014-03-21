#include "operacje.hh"

bool operacje::zamien_elementy(int i, int j){
    if(i>n && j>n) return false;
    float tmp;
    tmp = tab[i];
    tab[i] = tab[j];
    tab[j] = tmp;
    return true;
    }

void operacje::odwroc_tablice(){
  //int rozmiar = sizeof(tab);
 
  float* tmp = new float[n];
  
  for(int i = 0; i<n; i++){
    tmp[i] = tab[n - 1 - i];
    
  }
  for(int i = 0; i<n; i++){
    tab[i] = tmp[i];
  }
  
}

void operacje::dodaj_element(float e){
  int rozmiar_nowy = n + 1;
  
  float* tmp = new float[n];
  
  for(int i = 0; i<n; i++){
    tmp[i] = tab[i];
  }
  
  tab = new float[rozmiar_nowy];
  
  for(int i = 0; i<n; i++){
  tab[i] = tmp[i];
  
  tab[n] = e;}
  
  
}

  void operacje::dodaj_elementy(float* tab2, int rozm){
  int rozmiar_nowy = n + rozm;
  float* tmp = new float[rozmiar_nowy];
  for(int i = 0; i<n; i++){
    tmp[i] = tab[i];
  }
  for( int j = 0; j<n; j++){
    tmp[j+n] = tab2[j];
  }
  tab = new float[rozmiar_nowy];

  for( int i = 0; i<rozmiar_nowy; i++){
    tab[i] = tmp[i];
  }
  
}

void operacje::operator = (float* tab1){
  for(int i = 0; i<n; i++){
    tab[i] = tab1[i];
  }
}

bool operacje::operator == (float* tab1){
  for(int i = 0; i<n; i++){
    if(tab[i] != tab1[i])return false;

  }
    return true;
}

void operacje::quick_sort(int l, int p){

  int i = l,j = p; 
  float x = tab[(l+p)/2];
 while(i<=j){
    while (tab[i] < x) ++i;
    while(tab[j]>x) --j;
    if(i<=j) {zamien_elementy(i,j); i++; j--; }

  }
  if(l<j) quick_sort(l,j);
  if(i<p) quick_sort(i,p);
}
void operacje::make_node(int rozmiar, int i){
  int s1 = 2*i, s2 = (2*i) + 1;
  int max;
  if(s1<=(rozmiar) && tab[s1-1]>tab[i-1]) max = s1;
  else max = i;
  if(s2<=(rozmiar) && tab[s2-1] > tab[max-1]) max = s2;
  if(max !=i){
    //zamiana 'i' i max miejscami
    float temp = tab[max-1];
    tab[max-1] = tab[i-1];
    tab[i-1] = temp;
    make_node(rozmiar, max);
  }
}

void operacje::make_heap(){
  for ( int i = (n/2); i>0; i--){
    make_node(n,i);
  }
}

void operacje::heap_sort(){
  float temp;
  make_heap();
  for(int i = n; i > 1 ; --i){
    
    temp=tab[i-1];
    tab[i-1]=tab[0];
    tab[0]=temp;
    
    make_node(i-1,1);
  }
  cout<<"N: "<<n<<endl;
}

void operacje::merge(int start, int srodek, int koniec){
  float *tab_pom = new float[(koniec-start)]; // utworzenie tablicy pomocniczej
int i = start, j = srodek+1, k = 0; // zmienne pomocnicze
 
while (i <= srodek && j < koniec){
    if (tab[j] < tab[i]){
      tab_pom[k] = tab[j];
      j++;
      }
    else{
      tab_pom[k] = tab[i];
      i++;
      }
    k++;
  }
 
  if (i <= srodek){
    while (i <= srodek){
      tab_pom[k] = tab[i];
      i++;
      k++;
    }
} 
  else{
    while (j < koniec){
      tab_pom[k] = tab[j];
      j++;
      k++;
    }
}
 
for (i = 0; i <= (koniec-start); i++)
tab[start+i] = tab_pom[i]; 

 }

void operacje::merge_sort(int start, int koniec){
  int srodek;
 
if (start != koniec)
{
srodek = (start + koniec)/2;
merge_sort(start, srodek);
merge_sort(srodek+1, koniec);
merge(start, srodek, koniec);
}

}