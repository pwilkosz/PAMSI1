#ifndef ALGORYTM_HH
#define ALGORYTM_HH
#include<iostream>
#include<fstream>
#include<vector>
#include<ctime>
#include<sys/time.h>
#include<sys/types.h>
#include"operacje.hh"
#include"stos.hh"

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
  algorytm(ifstream &plik1, ifstream &plik2, int N, int M): n(N), m(M), op(N) { wczytaj(plik1);wczytaj_wzor(plik2);}
  /*!
   * \brief funkcja dokonuje operacji na pliku wejsciowym, wywoluje metody odpowiedzialne za pomiar czasu oraz za porownanie 
    wyniku operacji z plikiem wzorcowym
   */
  void wykonaj();
  /*!
   * \brief Metoda wczytuje plik wejsciowy do tablicy \p dane oraz do obiektu \p op klasy \p operacje   
    * \param [in] plik - strumien pliku wejsciowego
    */
  bool wczytaj(ifstream &plik);
  /*!
   * \brief Metoda wczytuje plik wzorcowy do tablicy \p dane_wz 
    * \param [in] plik - strumien pliku wejsciowego
    */
  
  bool wczytaj_wzor(ifstream &plik);
  /*!
   * \brief Metoda odpowiada za przetworzenie danych wejsciowych zgodnie z zadanym algorytmem
    */
  virtual void przelicz();
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
  float wlacz_zegar();
   /*!
    * \brief Metoda wyacza pomiar czasu poprzez wlaczenie funkcji \p gettimeofday i przechowanie czasu w zmiennej \p end 
    * \return end - zmienna pamietajaca czas poprzedzajacy wykonanie algorytmu
    */
  float wylacz_zegar();
  /*!
    * \brief Metoda zapisuje tablice \p czas do pliku \p wyjscie.csv  */
  void zapisz_do_csv();
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
  void przelicz();
  };

class stos_tablica: public algorytm{
  stack_array<float> stos;
public:
  stos_tablica(ifstream& plik1, ifstream& plik2, int N, int M,flag F):algorytm(plik1,plik2,N,M){stos.f = F;cout<<"SIEMA"<<endl;}
  void przelicz();
};

class stos_lista: public algorytm{
  stack_list<float> stos;
public:
  stos_lista(ifstream& plik1, ifstream& plik2, int N, int M) :algorytm(plik1,plik2,N,M){}
  void przelicz();
};
#endif