#include "aufgabe1.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <string>

using namespace std;

void randomNumbers(std::vector<int>& randomNumberVec, int k) {

    int border {1000};
    int randomNumber {};
    int tempNumber {};
    while(randomNumberVec.size() < k){
//Es werden zufallszahlen von 0 bis border ausgegeben
        do{
            tempNumber = rand()% border;
        }while(tempNumber < 0 || tempNumber > border);
//Wenn die zufallszahl schon innerhalb des Vektors für gefundene Zahlen liegt, dann soll nichts passieren
        if(std::find(randomNumberVec.begin(), randomNumberVec.end(), tempNumber) != randomNumberVec.end()){
//Wenn jedoch die zahl nicht gefunden wurde, so soll sie in den gefunden Vektor
        } else {
            randomNumberVec.push_back(tempNumber);
            randomNumber = tempNumber;
        }
    }   
}
