#ifndef STATYSTYKI_HH
#define STATYSTYKI_HH

/*!
 * \file
 *\brief plik zawiera dekalracje funkcji odpowiedzialnych za przeprowadznaie statystyk
 */

#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
/*!
 * \brief funckja oblicza wartosc srednia
 * \param tab - kontener zawierajacy czasy wykonania algorytmu
 * \return wartosc srednia
 */
float srednia (float* tab, int rozmiar);
/*!
 * \brief funckja oblicza odchylenie standardowe
 * \param tab - kontener zawierajacy czasy wykonania algorytmu
 * \param srednia - wartosc srednia
 * \return odchylenie standardowe
 */
float odchylenie_standardowe(float srednia, float* tab, int rozmiar);

#endif
