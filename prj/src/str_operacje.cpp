
#include<iostream>
#include"str_operacje.hh"
using namespace std;
/*! \brief 
  funkcja sluzaca do alfabetycznego porzadkowania napisow
  \return true, gdy s1 wyzej w porzadku alfabetycznym niz s2, false w przeciwnym przypadku
    */
bool operator<(string s1, string s2){
	
  for(unsigned int i = 0; i<s1.length() && i<s2.length(); i++){
    if(s1[i] < s2[i]) return true;
    if(s1[i] > s2[i]) return false;
  }
  if(s1.length()<s2.length()) return true;
  else return true;
}

/*! \brief
  funkcja sluzaca do alfabetycznego porzadkowania napisow
  \return true, gdy s1 nizej w porzadku alfabetycznym niz s2, false w przeciwnym przypadku
*/
bool operator>(string s1, string s2){
  for(unsigned int i = 0; i<s1.length() && i<s2.length(); i++){
    if(s1[i] > s2[i]) return true;
    if(s1[i] < s2[i]) return false;
  }
  if(s1.length()>s2.length()) return true;
  else return true;
}
/*! \brief
  \return true, gdy s1 jest wyzej w porzadku alfabrtycznym niz s2 lub gdy oba stringi sa sobie rowne, false, gdy s2 jest wyzej w porzadku alfabetycznym niz s1
*/
bool operator<=(string s1, string s2){
  return ((s1<s2) || (s1 == s2));
}
/*! \brief
\return true, gdy s1 jest nizej w porzadku alfabrtycznym niz s2 lub gdy oba stringi sa sobie rowne, false, gdy s1 jest wyzej w porzadku alfabetycznym niz s2
*/
bool operator>=(string s1, string s2){
  return ((s1>s2) || (s1 == s2));
}
/*! \brief 
  \return true, gdy łańcuchy są identyczne
*/
bool operator==(string s1, string s2){
	if(s1.length() != s2.length()) return false;
	else{
  		for(unsigned int i = 0; i<s1.length(); i++){
  			if(s1[i] != s2[i]) return false;
  		}
}
return true;
}
