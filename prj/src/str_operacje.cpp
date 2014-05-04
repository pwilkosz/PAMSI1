
#include<iostream>
#include<sstream>
#include"str_operacje.hh"
using namespace std;

bool operator<(string s1, string s2){
	/*sprawdzam czy liczba*/
	istringstream i1(s1); istringstream i2(s2);
	int l1,l2;
	if(i1>>l1 && i2>>l2) return l1<l2;
  for(unsigned int i = 0; i<s1.length() && i<s2.length(); i++){
    if(s1[i] < s2[i]) return true;
    if(s1[i] > s2[i]) return false;
  }
  if(s1.length()<s2.length()) return true;
  else return false;
}


bool operator>(string s1, string s2){
	/*sprawdzam czy liczba*/
	istringstream i1(s1); istringstream i2(s2);
	int l1,l2;
	if(i1>>l1 && i2>>l2) return l1>l2;
  for(unsigned int i = 0; i<s1.length() && i<s2.length(); i++){
    if(s1[i] > s2[i]) return true;
    if(s1[i] < s2[i]) return false;
  }
  if(s1.length()>s2.length()) return true;
  else return false;
}

bool operator<=(string s1, string s2){
  return ((s1<s2) || (s1 == s2));
}

bool operator>=(string s1, string s2){
  return ((s1>s2) || (s1 == s2));
}

bool operator==(string s1, string s2){
	if(s1.length() != s2.length()) return false;
	else{
  		for(unsigned int i = 0; i<s1.length(); i++){
  			if(s1[i] != s2[i]) return false;
  		}
}
return true;
}
