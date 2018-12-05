#include "aufgabe1.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <string>


using namespace std;

void randomNumbers(std::vector<int>& randomNumberVec, int k, int border) {

    int randomNumber {};
    int tempNumber {};
    while(randomNumberVec.size() < k){
        //Es werden zufallszahlen von 0 bis border ausgegeben
        do{
            tempNumber = rand()% border;
        }while(tempNumber < 0 || tempNumber > border);
        //========================================================
        //sort(randomNumberVec.begin(), randomNumberVec.end());

        //Sortieren durch Insertion Sort
        for (int i = 1; i < randomNumberVec.size(); i++) { // Durchläufe
            int tmp = randomNumberVec.at(i);
            int j = i - 1;
            while (j >= 0 && tmp < randomNumberVec.at(j)) { // verschieben größerer Elemente
                randomNumberVec.at(j + 1) = randomNumberVec.at(j);
                j--;
            }
            randomNumberVec.at(j + 1) = tmp; // einfügen an richtiger Stelle
        }

        if(binary_search(randomNumberVec.begin(), randomNumberVec.end(), tempNumber)) {




        } else {
            auto q = lower_bound(randomNumberVec.begin(), randomNumberVec.end(), tempNumber);
            randomNumberVec.insert(q, tempNumber);
            randomNumber = tempNumber;
        }
    }
}









//Aufgabe 2
//=========================================================================================

//Aufgabe 3
//=========================================================================================

//Aufgabe 4
//=========================================================================================

//Konstanten
const string BEV_Energie;
const string EMMA_Energie;
const string Vattenfall;
const string enerSwitch;
const string energie;
const string RHEINPOWER;
