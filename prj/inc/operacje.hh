#ifndef OPERACJE_HH
#define OPERACJE_HH
#define ROZMIAR 9
#include<cstdlib>
#include<iostream>
using namespace std;
/*!
 * \brief Klasa modeluje tablice z danymi i metody sluzace do operacji na niej*/
class operacje{
	public:
	/*!
	 * \brief ilosc elementow w tablicy
	 */
	int n;
	/*! 
	 * \brief tablica z liczbami*/	
	float* tab; 		
	/*!
	 * \brief konstruktor bezparametryczny
	 */
	operacje();
	/*!
	 * \brief konstruktor parametryczny - alokuje pamiec w dynamicznej tablicy \p tab \p 
     * \param [in] N - ilosc elementow w tablicy; parametr przypisywany do pola \p n \p w klasie, oraz alokuje pamiec o takim wlasnie rozmiarze
	  */
	operacje(int N){
		n = N;
		tab = new float[n];
		
	}
	/*!
	 * \brief Metoda zamienia 2 elementy tablicy 
	 * \param [in] - i - element tablicy
	 * \param [in] - j - element tablicy
	 * \return true - gdy elementy nie wykraczaja poza zakres tablicy
	 		   false - w przeciwnym przypadku
	 		   	*/
  bool zamien_elementy(int i, int j);
  	/*!
  	 * \brief metoda odwraca wszystkie elementy tablicy*/
  void odwroc_tablice();
  /*!
   * \brief metoda dodaje element do tablicy, alokujac dodatkowa pamiec
   * \param [in] e - element, ktory nalezy dolaczyc do tablicy*/

  void dodaj_element(float e);
  /*!
   * \brief metoda dodaje elementy do tablicy
   * \param [in] tab2 - tablica, ktora nalezy dolaczyc
   * \param [in] rozm - rozmiar tablicy tab2
   */
  void dodaj_elementy(float* tab2, int rozm);
  /*!
   * \brief Przeciazenie operatora przypisania; przypisuje elementy tablicy \p tab1 \p do tablicy bedacej polem klasy
   * \param [in] tab1 - tablica, ktorej zawartosc przypisujemy */
  void operator = (float* tab1);
  /*!
   * \brief Przeciazenie operatora porownania; metoda porownuje zawartosci dwoch tablic
   * \param [in]  tab1 - tablica, ktorej wartosci porownujemy
   * \return true - gdy zawartsoc tablic jest identyczna
             false - w przeciwnym przypadku*/
  bool operator == (float* tab1);

};

#endif
