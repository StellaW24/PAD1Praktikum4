#ifndef AUFGABE1_H
#define AUFGABE1_H

#include <iostream>
#include <vector>

using namespace std;

//border is the border of the random int, k is the amount of random int you want to get out of
//the used numbers are pushed_back in randomnumber
void randomNumbers(vector<int>randomNumberVec, int k, int border);


//Beispiel zur Übergabe eines Arrays in einer Funktion
void tabellenausgabe2D(int (*T)[3], unsigned int n);


#endif // AUFGABE1_H
