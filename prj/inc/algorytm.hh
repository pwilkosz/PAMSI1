#ifndef ALGORYTM_HH
#define ALGORYTM_HH
#include<iostream>
#include<fstream>
#include<vector>
#include<time.h>
#include<sys/time.h>
#include<sys/types.h>
#include"operacje.hh"
#include"stos.hh"
#include"kolejka.hh"
#include"drzewo.hh"
#include"hashtab.hh"
#include"tablica_asocjacyjna.hh"
#include"graf.hh"
using namespace std;

/*!
 * \file
 * \brief Definicja klas wykonujacych operacje na zestawie danych wejsciowych
 *  
 * 
 * 
 *
 *
 *
 *
 *
 *
 *
 */

/*!
 * \brief Definicja klasy algorytm
 * Jest to klasa bazowa, ktora ma za zadanie wczytac, 
 * przetworzyc i porownac dane z plikiem wzorcowym. */
class algorytm{
protected:
  
  
 
 /*!
   * \brief Tablica liczb wczytana z pliku
    */
   float* dane;

   /*!
    * \brief tablica liczb zawartych w pliku wzorcowym
     */
   float* dane_wz;


  /*!
    * \brief ilosc danych w pliku
    */
  int n;
   /*!
  * \brief ilosc powtorzen
    */
  int m;
  /*!
  * \brief klasa zawierajaca tablice i metody do operacji na niej
  */
    operacje op;
    double czas1,czas2;
public:
  /*!
   * \brief zawiera wyniki dzialania algorytmu
   */
  float* czas;
  

  /*!
   * \brief konstruktor kopiujacy - przekazuje informacje o nazwach plikow, ktore zapisywane sa do pol klasy
   * \param [in] plik1 - plik wejsciowy
   * \param [in] plik2 - plik wzorcowy
   * \param [in] N - ilosc danych wejsciowych
   * \param [in] M - ilosc powtorzen
   */
  algorytm(ifstream &plik1, ifstream &plik2, int N, int M): n(N), m(M), op(N) { wczytaj(plik1);wczytaj_wzor(plik2);czas = new float[m];}
  /*!
   * \brief funkcja dokonuje operacji na pliku wejsciowym, wywoluje metody odpowiedzialne za pomiar czasu oraz za porownanie 
    wyniku operacji z plikiem wzorcowym
   */
  void wykonaj(ofstream& out);
  /*!
   * \brief Metoda wczytuje plik wejsciowy do tablicy \p dane oraz do obiektu \p op klasy \p operacje   
    * \param [in] plik - strumien pliku wejsciowego
    */
  bool wczytaj(ifstream &plik);
  /*!
   * \brief metoda ustawia wartosc n
  */
   void set_N(int wart){n = wart; op.n = wart;}
  /*!
   * \brief Metoda wczytuje plik wzorcowy do tablicy \p dane_wz 
    * \param [in] plik - strumien pliku wejsciowego
    */
  
  bool wczytaj_wzor(ifstream &plik);
  /*!
   * \brief Metoda odpowiada za przetworzenie danych wejsciowych zgodnie z zadanym algorytmem
    */
  virtual float przelicz();
  /*!
   * \brief porownuje przetworzony dane z danymi wzorcowymi
   * \return true - gdy pliki zgodne
   *         false - w przeciwnym przypadku
   */
  bool porownaj();
  /*!
   * \return ilosc liczb wejsciowych
   */
  int ile_danych();
  /*!
    * \return tablica \p czas z danymi pomiarowymi czasu wykonywania algorytmu*/
  float* jaki_czas();
  /*!
    * \brief Metoda wlacza pomiar czasu poprzez wlaczenie funkcji \p gettimeofday i przechowanie czasu w zmiennej \p start 
    * \return start - zmienna pamietajaca czas poprzedzajacy wykonanie algorytmu
    */
  void wlacz_zegar();
   /*!
    * \brief Metoda wyacza pomiar czasu poprzez wlaczenie funkcji \p gettimeofday i przechowanie czasu w zmiennej \p end 
    * \return end - zmienna pamietajaca czas poprzedzajacy wykonanie algorytmu
    */
  void wylacz_zegar();
  /*!
    * \brief Metoda zapisuje tablice \p czas do pliku \p wyjscie.csv  */
  void zapisz_do_csv(ofstream& out);
  /*!
   * \brief metoda zapisuje do pliku .csv parametry takie jak: srednia, ilosc liczb, odchylenie standardowe
  */
   void zapisz_do_gnuplot(ofstream& out,float sr, float od);
};
/*!
 * \brief modeluje algorytm dokonujacy mnozenia kazdego elementu pliku wejsciowego przez 2
 */
class mnozenie: public algorytm{
public:
  /*!
   * /brief konstruktor przekazuje do pol klasy informacje o nazwach pliku wejsciowego i wzorcowego
   * \param [in] plik1 - plik wejsciowy
   * \param [in] plik2 - plik wzorcowy
   * \param [in] N - ilosc danych wejsciowych
   * \param [in] M - ilosc powtorzen
   */
  mnozenie(ifstream& plik1, ifstream& plik2, int N, int M) :algorytm(plik1,plik2,N,M){}
  
  /*!
   * \brief wykonuje zalozony algorytm mnozenia elementow tablicy przez 2
   */
  float przelicz();
  };
/*!
  \brief klasa utworzona na potrzeby pomiaru czasu wypełnienia struktury
*/
class stos_tablica: public algorytm{
  stack_array<float> stos;
public:
  /*!
    \brief konstruktor - ustawia flage w zadany stan
    */
  stos_tablica(ifstream& plik1, ifstream& plik2, int N, int M,flag F):algorytm(plik1,plik2,N,M){stos.f = F;}
  float przelicz();
};
/*!
  \brief klasa utworzona na potrzeby pomiaru czasu wypełnienia struktury
*/
class stos_lista: public algorytm{
  stack_list<float> stos;
public:
  stos_lista(ifstream& plik1, ifstream& plik2, int N, int M) :algorytm(plik1,plik2,N,M){}
  float przelicz();
};
/*!
  \brief klasa utworzona na potrzeby pomiaru czasu wypełnienia struktury
*/
class kolejka_tablica: public algorytm{
  queue_array<float> qu;
public:
   /*!
    \brief konstruktor - ustawia flage w zadany stan
    */
  kolejka_tablica(ifstream& plik1, ifstream& plik2, int N, int M,flag F):algorytm(plik1,plik2,N,M){qu.f = F;}
  float przelicz();
};
/*!
  \brief klasa utworzona na potrzeby pomiaru czasu wypełnienia struktury
*/
class kolejka_lista: public algorytm{
  queue_list<float> qu;
public:
  kolejka_lista(ifstream& plik1, ifstream& plik2, int N, int M) :algorytm(plik1,plik2,N,M){}
  float przelicz();
};
/*!
 * \brief klasa reprezentuje dane poddane sortowaniu szybkiemu
*/
class q_sort: public algorytm{
public:
  /*! \brief konstruktor klasy*/
  q_sort(ifstream& plik1, ifstream& plik2, int N, int M) :algorytm(plik1,plik2,N,M){}
  /*! \brief metoda dokonujaca sortowania danych*/
  float przelicz();
};
/*! \brief klasa reprezentuje dane poddane sortowaniu przez kopcowanie */
class h_sort: public algorytm{
public:
  /*! \brief konstruktor klasy*/
  h_sort(ifstream& plik1, ifstream& plik2, int N, int M) :algorytm(plik1,plik2,N,M){}
  /*! \brief metoda dokonujaca sortowania danych*/
  float przelicz();
};

/*! \brief klasa reprezentuje dane poddane sortowaniu przez scalanie*/
class m_sort: public algorytm{
public:
  /*! \brief konstruktor*/
  m_sort(ifstream& plik1, ifstream& plik2, int N, int M) :algorytm(plik1,plik2,N,M){}
  /*! \brief metoda dokonujaca sortowania danych*/
  float przelicz();
};
/*! \brief 
  Modeluje drzewo binarne przeznaczone do testowania szybkosci wyszukiwnaia
*/
class bst: public algorytm{
  drzewo<float> d;
  string* klucze;
public:
  void wczytaj_klucze(ifstream& plik);
  bst(ifstream&  plik1, ifstream& plik2, ifstream& plik3, int N, int M) :algorytm(plik1,plik2,N,M){
    klucze = new string[N]; 
    wczytaj_klucze(plik3);
    for(int i = 0; i<N; i++){
      d.dodaj(klucze[i], dane[i]);
     cout<<i<<endl;
    }
  }
  ~bst(){d.wyczysc();}
  float przelicz();
  
};
/*! \brief 
  Modeluje tablice haszujaca przeznaczona do testowania szybkosci wyszukiwnaia
*/
class h_table: public algorytm{
  /*! \brief tablica kluczy*/
  string* klucze;
public:
  /*! \brief wczytywanie kluczy
  \param [in] plik - strumien z kluczmai uzytymi podczas testow
  */
  void wczytaj_klucze(ifstream& plik);
  /*! \brief konstruktor*/
  h_table(ifstream&  plik1, ifstream& plik2, ifstream& plik3, int N, int M) :algorytm(plik1,plik2,N,M){
    klucze = new string[N];
    wczytaj_klucze(plik3);}
  float przelicz();
  };

/*! \brief 
  Modeluje tablice asocjacyjna przeznaczona do testowania szybkosci wyszukiwnaia
*/
  class tab_aso: public algorytm{
    /*! \brief tablica asocjacyjna*/
  tablica_asocjacyjna<float> d;//to trzeba gdzie indziej
  /*! \brief wczytywanie kluczy
  \param [in] plik - strumien z kluczmai uzytymi podczas testow
  */
  string* klucze;
public:
   /*! \brief wczytywanie kluczy
  \param [in] plik - strumien z kluczmai uzytymi podczas testow
  */
  void wczytaj_klucze(ifstream& plik);
  /*! \brief konstruktor*/
  tab_aso(ifstream&  plik1, ifstream& plik2, ifstream& plik3, int N, int M) :algorytm(plik1,plik2,N,M){
    klucze = new string[N]; 
    wczytaj_klucze(plik3);
    for(int i = 0; i<200000; i++){
      d.dodaj(klucze[i], dane[i]);
      cout<<i<<endl;
    }
    
  }
  float przelicz();
  
};
/*! \brief modeluje strukture grafów uzytych do badan*/
class graf_test: public algorytm{
  /*! \ grafy, na ktorych testuje sie algorytmu przeszukiwania*/
  graf G1,G2,G3,G4,G5,G6;
public:
  /*! \brief informuje o tym, jaki algorytm zastosowac*/
  int typ;
  /*! \brief na podstawie danych z pliku, tworzone sa grafy*/
  void wczytaj_graf();
  /*! \brief konstruktor*/
  graf_test(ifstream&  plik1, ifstream& plik2,  int N, int M, int t) :algorytm(plik1,plik2,N,M){wczytaj_graf(); typ = t;}
  float przelicz();
};

#endif