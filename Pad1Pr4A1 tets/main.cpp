#include "aufgabe1.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <string>

using namespace std;






void aufgabe1()
{


    //Erstellung des Arrays
    //Zusatzkommentar: rand bildet keine wirklich zufälligen Werte!
    //vektoren für die Zufallszahlen, die an das array übergeben werden
    vector<int> randomNumberVec1;
    srand(time(NULL));
    //eingabe von k und border. k ist die größe des arrays, border der Bereich der Werte von 0 bis Border
    int* array {0};
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
    array = new int[k];
    //den Stellen im Array werden die Stellen im Vektor zugeordnet
    for (int i=0; i < k; i++){
        array[i] = randomNumberVec1[i];
    }
    //erstellung des Arrays abgeschlossen

    int a {};
    cout << "Bitte suchalgorithmus auswaehlen: BubbleSort = 1, SelectionSort = 2, InsertionSort = 3" << endl;
    cin >> a;

    if(a == 1) {
        //BubbleSort
        time_t start = time(NULL);
        for (int i = 1; i < k; i++) // n-1 Durchläufe
            for (int j = k - 1; j >= i; j--) {// variable Anzahl von Schritten in
                // einem Durchlauf
                if (array[j - 1] > array[j]) { // vertauschen zweier Elemente falls noetig
                    int tmp = array[j - 1];
                    array[j - 1] = array[j];
                    array[j] = tmp;
                }
            }
        time_t ende=time(NULL);
        //Ausgabe der Zeit
        cout << "Dauer BubbleSort: " << ende-start << " Sekunden" << endl;
    }
    else if(a == 2) {
        // Sortieren ueber Selection Sort
        time_t start=time(NULL);
        for (int i = 0; i < k-1; i++) { //Durchläufe
            int index = i; //index zeigt auf das kleinste Element
            int min = array[i]; //Wert des kleinsten Elementes
            for (int j = i+1; j < k; j++) {//suche kleinstes Element
                if (array[j] < min) { //neues kleinstes Element
                    index = j;
                    min = array[j];
                }
            }
            array[index] = array[i]; // vertausche aktuelles Element mit kleinstem Element
            array[i] = min;
        }
        time_t ende=time(NULL);
        //Ausgabe der Zeit
        cout << "Dauer Selection Sort: " << ende-start << " Sekunden" << endl;
    }
    else if(a == 3) {
        // Sortieren ueber Insertion Sort
        time_t start=time(NULL);
        for (int i = 1; i < k; i++) { // Durchläufe
            int tmp = array[i];
            int j = i - 1;
            while (j >= 0 && tmp < array[j]) { // verschieben größerer Elemente
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = tmp; // einfügen an richtiger Stelle
        }
        time_t ende = time(NULL);
        //Ausgabe der Zeit
        cout << "Dauer Insertion Sort: " << ende-start << " Sekunden" << endl;
    }
    else {
        cout << "Bitte richtige eingabe eingeben" << endl;
    }
    //Das vorher erstellte dynamische array wird, nachdem es nicht mehr gebrauchrt wird, gelöscht um den Speicher freizugeben
    delete [] array;
    array = NULL;


}

void aufgabe2()
{

    /*
    //Erstellung des Arrays
    //Zusatzkommentar: rand bildet keine wirklich zufälligen Werte!
    //vektoren für die Zufallszahlen, die an das array übergeben werden
    vector<int> randomNumberVec1;
    srand(time(NULL));
    //eingabe von k und border. k ist die größe des arrays, border der Bereich der Werte von 0 bis Border
    int* array {0};
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
    array = new int[k];
    //den Stellen im Array werden die Stellen im Vektor zugeordnet
    for (int i=0; i < k; i++){
        array[i] = randomNumberVec1[i];
    }
    //erstellung des Arrays abgeschlossen

    int a {};
    cout << "Bitte algorithmus auswaehlen:" << a << endl;
    cin >> a;
    if(a == 1) {
    // Sortieren ueber Insertion Sort
    time_t start=time(NULL);
    for (int i = 1; i < k; i++) { // Durchläufe
        int tmp = array[i];
        int j = i - 1;
        while (j >= 0 && tmp < array[j]) { // verschieben größerer Elemente
            array[j + 1] = array[j];
            j--;
        }
        //Binäre Suche
        int min = array[0];
        int max = (sizeof (array) / sizeof (*array)-1); //letzter Index
                int guess {};
        while(min <= max) {
            guess = (int)(((max + min) / 2) + 0.5);
            if(tmp == array[guess]) {
                array[j + 1] = tmp;
            }
            else if(array[guess] < tmp) {
                min = guess + 1;
            }
            else {
                max = guess - 1;
            }
        }
        //array[j + 1] = tmp; // einfügen an richtiger Stelle
    }
    time_t ende = time(NULL);
    //Ausgabe der Zeit
    cout << "Dauer Insertion Sort: " << ende-start << " Sekunden" << endl;
    }
    else if(a == 2) {
        for (int i = 1; i < randomNumberVec1.size(); i++) { // Durchläufe
            int tmp = randomNumberVec1.at(i);
            int j = i - 1;
            while (j >= 0 && tmp < randomNumberVec1.at(j)) { // verschieben größerer Elemente
                randomNumberVec1.at(j + 1) = randomNumberVec1.at(j);
                j--;
            }
            randomNumberVec1.at(j + 1) = tmp; // einfügen an richtiger Stelle
        }

        if(binary_search(randomNumberVec1.begin(), randomNumberVec1.end(), tempNumber)) {

        //Wenn die zufallszahl schon innerhalb des Vektors für gefundene Zahlen liegt, dann soll nichts passieren
        if(std::find(randomNumberVec.begin(), randomNumberVec.end(), tempNumber) != randomNumberVec.end()){



            //Wenn jedoch die zahl nicht gefunden wurde, so soll sie in den gefunden Vektor
        } else {
            auto q = lower_bound(randomNumberVec1.begin(), randomNumberVec1.end(), tempNumber);
            randomNumberVec1.insert(q, tempNumber);
            randomNumber = tempNumber;
        }
    }
    }
            */
}
void aufgabe3()
{
}

void aufgabe4()
{
}

int main()
{
    int input = 9;
    while(input != 0)
    {
        cout << endl;
        cout << "Welche Aufgabe soll ausgefuehrt werden?" << endl << "Mit 0 wird die Anwendung beendet." << endl;
        cin >> input;
        switch (input) {
        case 0: break;
        case 1: aufgabe1(); break;
        case 2: aufgabe2(); break;
        case 3: aufgabe3(); break;
        case 4: aufgabe4(); break;
        default: cout << "Diese Eingabe ist ungueltig. Versuchen sie es nochmal" << endl;
        }
    }
}



