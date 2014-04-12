#ifndef STR_OPERACJE_HH
#define STR_OPERACJE_HH

#include<string>
using namespace std;
/*! \brief 
  funkcja sluzaca do alfabetycznego porzadkowania napisow
  \return true, gdy s1 wyzej w porzadku alfabetycznym niz s2, false w przeciwnym przypadku
    */
bool operator<(string s1, string s2);

/*! \brief
  funkcja sluzaca do alfabetycznego porzadkowania napisow
  \return true, gdy s1 nizej w porzadku alfabetycznym niz s2, false w przeciwnym przypadku
*/
bool operator>(string s1, string s2);
/*! \brief
  \return true, gdy s1 jest wyzej w porzadku alfabrtycznym niz s2 lub gdy oba stringi sa sobie rowne, false, gdy s2 jest wyzej w porzadku alfabetycznym niz s1
*/
bool operator<=(string s1, string s2);
/*! \brief
\return true, gdy s1 jest nizej w porzadku alfabrtycznym niz s2 lub gdy oba stringi sa sobie rowne, false, gdy s1 jest wyzej w porzadku alfabetycznym niz s2
*/
bool operator>=(string s1, string s2);
/*! \brief 
  \return true, gdy łańcuchy są identyczne
*/
bool operator==(string s1, string s2);
#endif