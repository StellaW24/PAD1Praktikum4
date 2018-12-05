#ifndef AUFGABE1_H
#define AUFGABE1_H

#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

//border is the border of the random int, k is the amount of random int you want to get out of
//the used numbers are pushed_back in randomnumber
void randomNumbers(vector<int>& randomNumberVec , int k, int border);

//void randomArray(long& array, int& k);
//das meiste wird nicht benutzt

void insertionSort(long array);

void selectionSort(long array);

void bubbelSort(long array[]);

void arrayAusgabe(long array[], int k);

#endif // AUFGABE1_H
