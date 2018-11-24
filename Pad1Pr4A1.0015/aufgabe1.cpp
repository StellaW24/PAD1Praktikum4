#include "aufgabe1.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <string>

using namespace std;

void randomNumbers(vector<int>randomNumberVec, int k, int border) {
    int randomNumber {};
    int tempNumber {};
//grenze der Zufallszahlen muss größer gleich der Anzahl an gewünschten Zufallszahlen sein
    if(k > border) {
        cerr << "Error Code: 404" << endl;
    }
    else {
//Die Anzahl an hinzugefügten Zahlen darf nicht größer als numAnzahl sein
        while(randomNumberVec.size() < k){
//Es werden zufallszahlen von 0 bis 7 ausgegeben
            do{
                tempNumber = rand()%border;
            }while(tempNumber < 0 || tempNumber > border);
//Wenn die zufallszahl schon innerhalb des Vektors für gefundene Zahlen liegt, dann soll nichts passieren
            if(std::find(randomNumberVec.begin(), randomNumberVec.end(), tempNumber) != randomNumberVec.end()){
                //cout << "gefunden" << endl;
//Wenn jedoch die zahl nicht gefunden wurde, so soll sie in den gefunden Vektor
            } else {
                randomNumberVec.push_back(tempNumber);
                randomNumber = tempNumber;
                //hier mit den Zahlen das array füllen
            }
        }
    }
    //Ausgabe des Vektors mit den Zufallszahlen
    cout <<"Anzahl an Zufallszahlen:_" << randomNumberVec.size() << endl;
    for(size_t i = 0; i < randomNumberVec.size(); ++i) {
        cout << randomNumberVec[i] << " ";
    }
    cout << endl;
}


//Beispiel für die übergabe eines Arrays in einer Funktion
void tabellenausgabe2D(int (*T)[3], unsigned int n) {
  // alternativ: void tabellenausgabe(int T[][3], size_t n)
  for (unsigned int i = 0; i < n; ++i) {
    for (unsigned int j = 0; j < 3; ++j) {
      std::cout << T[i][j] << ' ';
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}




//test arrayfüllen
/*
void fillArray() {
    for(int i = 0; i < 8;i++ ) {
        for(int j = 0; j < 0; j++) {

        }
    }
}
*/

//Example for implementation in main function
/*
 * int main() {
 *
 *  randomNumbers(vector<int>randomNumberVec, int k, int border);
 *
 * }
*/
