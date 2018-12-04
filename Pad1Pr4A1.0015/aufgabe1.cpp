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
        //Wenn die zufallszahl schon innerhalb des Vektors für gefundene Zahlen liegt, dann soll nichts passieren
        if(std::find(randomNumberVec.begin(), randomNumberVec.end(), tempNumber) != randomNumberVec.end()){
        //Wenn jedoch die zahl nicht gefunden wurde, so soll sie in den gefunden Vektor
        } else {
            randomNumberVec.push_back(tempNumber);
            randomNumber = tempNumber;
        }
    }   
}




//Erstellung des Arrays
void randomArray() {
    //Zusatzkommentar: rand bildet keine wirklich zufälligen Werte!
    //vektoren für die Zufallszahlen, die an das array übergeben werden
    vector<int> randomNumberVec1;
    srand(time(NULL));
    //eingabe von k und border. k ist die größe des arrays, border der Bereich der Werte von 0 bis Border
    long* array = 0;
    int k {};
    int border {};
    cout << "Bitte geben Sie die gewuenschte groesse des Arrays an und in welchen Bereich sich die Werte befinden sollen" << endl;
    cin >> k >> border;
    if (border <= k) {
        cerr << "Halten Sie sich an die Anweisung!" << endl;
    }
    else
    //Funktionsaufruf für randomNumbers
    randomNumbers(randomNumberVec1, k, border);
    //Erstellung des Arrays mit der größe von k
    array = new long[k];
    //den Stellen im Array werden die Stellen im Vektor zugeordnet
    for (int i=0; i < k; i++){
        array[i] = randomNumberVec1[i];
    }
    //Das Array wird hier zu kontroll-zwecken ausgegeben, wird für die Aufgabe1 nicht gebraucht
    cout << "Ausgabe des Arrays:" << endl;
    cout << endl;
    for( int i=0; i < k; i++){
        cout <<array[i] << " ";
    }
    //Das vorher erstellte dynamische array wird, nachdem es nicht mehr gebrauchrt wird, gelöscht um den Speicher freizugeben
    //delete [] array;
    //array = NULL;
}



void bubbleSort(long array[]) {
    const int max = 10;
    int n = 0, zahl;
    array[max];
    //do {  //Einlesen der Daten
    //cout << "Bitte positive ganze Zahlen eingeben (0 fuer Abbruch): ";
    //cin >> zahl;
    //A[n] = zahl;
    //if (zahl) n++; //n enthaelt Anzahl der Elemente
    //}
    //while (zahl && n < max);
    // Sortieren
    for (int i = 1; i < n; i++) // n-1 Durchläufe
    for (int j = n - 1; j >= i; j--) {// variable Anzahl von Schritten in
    // einem Durchlauf
    if (array[j - 1] > array[j]) { // vertauschen zweier Elemente falls noetig
    int tmp = array[j - 1];
    array[j - 1] = array[j];
    array[j] = tmp;
    }
    }
    // Ausgeben
    for (int i = 0; i < n; i++)
    cout << array[i] << " ";
    cout << endl;
}

int testausgabe(int n) {
    cin >> n;
    cout << "Hallo dies ist eine Testausgabe" << endl;
    cout << n << endl;
    return 0;
}

