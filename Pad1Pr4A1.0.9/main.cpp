#include "aufgabe1.h"
#include "aufgabe2.h"
#include "aufgabe3.h"
#include "aufgabe4.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <string>

using namespace std;


void aufgabe1() {

    //Erstellung des Arrays
    srand(time(NULL));
    //eingabe von k und border. k ist die größe des arrays, border der Bereich der Werte von 0 bis Border
    int* array {0};
    int k {};

    cout << "Bitte geben Sie die gewuenschte groesse des Arrays an und in welchen Bereich sich die Werte befinden sollen" << endl;
    cin >> k;
    //Erstellung des Arrays mit der größe von k
    array = new int[k];
    //den Stellen im Array werden die Stellen im Vektor zugeordnet
    for (int i=0; i < k; i++){
        array[i] = rand();
    }
    //erstellung des Arrays abgeschlossen

    //Auswahl des gewollten Suchalgorithmus
    int a {};
    cout << "Bitte suchalgorithmus auswaehlen: BubbleSort = 1, SelectionSort = 2, InsertionSort = 3" << endl;
    cin >> a;

    if(a == 1) {
        //BubbleSort
        clock_t start = clock();
        for (int i = 1; i < k; i++) // n-1 Durchläufe
            for (int j = k - 1; j >= i; j--) {// variable Anzahl von Schritten in
                // einem Durchlauf
                if (array[j - 1] > array[j]) { // vertauschen zweier Elemente falls noetig
                    int tmp = array[j - 1];
                    array[j - 1] = array[j];
                    array[j] = tmp;
                }
            }
        clock_t ende= clock();
        double elapsedTime = double(ende - start) / CLOCKS_PER_SEC;
        //Ausgabe der Zeit
        cout << "Dauer BubbleSort: " << elapsedTime << " Sekunden" << endl;
    }

    else if(a == 2) {
        // Sortieren ueber Selection Sort
        clock_t start = clock();
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
        clock_t ende= clock();
        double elapsedTime = double(ende - start) / CLOCKS_PER_SEC;
        //Ausgabe der Zeit
        cout << "Dauer SelectionSort: " << elapsedTime << " Sekunden" << endl;
    }

    else if(a == 3) {
        // Sortieren ueber Insertion Sort
        clock_t start = clock();
        for (int i = 1; i < k; i++) { // Durchläufe
            int tmp = array[i];
            int j = i - 1;
            while (j >= 0 && tmp < array[j]) { // verschieben größerer Elemente
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = tmp; // einfügen an richtiger Stelle
        }
        clock_t ende= clock();
        double elapsedTime = double(ende - start) / CLOCKS_PER_SEC;
        //Ausgabe der Zeit
        cout << "Dauer InsertionSort: " << elapsedTime << " Sekunden" << endl;
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
    //InsertionSort mit binärer Suche implementiernen, Laufzeit messen; insertionSort mit vektor, laufzeit messen
    //Erstellung des Arrays
    srand(time(NULL));
    int* array {0};
    int k {};
    cout << "Bitte geben Sie die gewuenschte Groesse an"<< endl;
    cin >> k;
    //Erstellung des Arrays mit der größe von k
    array = new int[k];
    vector<int> randomNumberVec(k);
    //den Stellen im Array werden die Stellen im Vektor zugeordnet
    for (int i=0; i < k; i++){
        array[i] = rand();
    }
    //erstellung des Arrays abgeschlossen
    for(int i = 0; i < k; i++) {
        randomNumberVec.at(i) = rand();
    }
    //erstellen des Vektors abgeschlossen
    int a {};
    cout << "Bitte Algorithmus auswaehlen: Insertion Sort mit Array = 1 oder Vektor = 2" << endl;
    cin >> a;

    if(a == 1) {
        /*
        // Sortieren ueber Insertion Sort
        clock_t start = clock();
        for (int i = 1; i < k; i++) { // Durchläufe
            int tmp = array[i];
            for(int j = i - 1; j >= 0 && tmp < array[j]; j--) { // verschieben größerer Elemente
                array[j + 1] = array[j];
            }
            //Binäre Suche
            int min = array[0];
            int max = (sizeof (array) / sizeof (*array)-1); //letzter Index
            int guess {};
            while(min <= max) {
                guess = (int)(((max + min) / 2) + 0.5);
                if(tmp == array[guess]) {
                    array[] = tmp;
                }
                else if(array[guess] < tmp) {
                    min = guess + 1;
                }
                else {
                    max = guess - 1;
                }
            }
        }

        clock_t ende= clock();
        double elapsedTime = double(ende - start) / CLOCKS_PER_SEC;
        //Ausgabe der Zeit
        cout << "Dauer InsertionSort: " << elapsedTime << " Sekunden" << endl;
        */

        clock_t start = clock();
        for (int i = 1; i < k; i++) { // Durchläufe
            int tmp = array[i];
            int min = 0;
            int max = i;
            int mid;
            while(min <= max)
            {
                mid = ((max + min) /2) -1;
                if(tmp < array[mid])
                {
                    max = mid - 1;
                }
                else if (tmp > array[mid])
                {
                    min = mid + 1;
                }
                else
                {
                    tmp = mid;
                    break;
                }
            }
            array[i] = array[tmp];
        }
        clock_t ende= clock();
        double elapsedTime = double(ende - start) / CLOCKS_PER_SEC;
        //Ausgabe der Zeit
        cout << " Dauer InsertionSort: " << elapsedTime << " Sekunden" << endl;

        //Ausgabe um zu sehen ob das Array sortiert ist
        if(k < 21)
        {
            for(int i = 1; i < k; i++)
            {
                cout << array[i] << endl;
            }
        }
    }

    else if(a == 2) {
        //start des Insertion Sort
        clock_t start = clock();
        for (int i = 1; i < int(randomNumberVec.size()); i++) { // Durchläufe
            int tmp = randomNumberVec.at(i);
            int min = 0;
            int max = i - 1;
            int mid;
            while(min <= max)
            {
                mid = (max + min) /2;
                if(tmp < randomNumberVec.at(mid))
                {
                    max = mid - 1;
                }
                else if (tmp > randomNumberVec.at(mid))
                {
                    min = mid + 1;
                }
                else
                {
                    break;
                }
            }
            randomNumberVec.at(i) = tmp;
        }
        clock_t ende= clock();
        double elapsedTime = double(ende - start) / CLOCKS_PER_SEC;
        //Ausgabe der Zeit
        cout << " Dauer InsertionSort: " << elapsedTime << " Sekunden" << endl;

        //Ausgabe um zu sehen ob der Vektor sortiert ist
        if(int(randomNumberVec.size()) < 21)
        {
            for(int i = 1; i < k; i++)
            {
                cout << randomNumberVec.at(i) << endl;
            }
        }
    }

    //löschen um speicherplatz freizugeben
    delete [] array;
    array = NULL;
}

void aufgabe3()
{
    //Stromanbieter
    //eingabe des jahresverbrauchs in kwh, liste der stromanbieter in aufsteigender reihenfolge des jahrespreises ausgeben
    //InsertionSort ODER BubbleSort ODER SelectionSort
    //cin name des gewählten stromanbieters, mit binärer suche suchen, passende ausgabe
    //Funktionen: sort, search, calculate

    //liste erstellen

    listPowerProvider list[6];
    list[0].name = "BEV Energie";
    list[0].monthly = 17.78;
    list[0].kWH = 0.2455;
    list[0].bonus = 185;
    list[1].name = "EMMA Energie";
    list[1].monthly = 11.50;
    list[1].kWH = 0.2489;
    list[1].bonus = 240;
    list[2].name = "Vattenfall";
    list[2].monthly = 12.40;
    list[2].kWH = 0.2532;
    list[2].bonus = 275;
    list[3].name = "enerSwitch";
    list[3].monthly = 11.85;
    list[3].kWH = 0.2423;
    list[3].bonus = 230;
    list[4].name = "123energie";
    list[4].monthly = 13.86;
    list[4].kWH = 0.2441;
    list[4].bonus = 250;
    list[5].name = "RHEINPOWER";
    list[5].monthly = 13.10;
    list[5].kWH = 0.2477;
    list[5].bonus = 241;

    double use;
    string powerProvider;
    cout << "Stromtarife vergleichen" << endl;
    cout << "Bitte geben Sie ihren Jahresverbrauch in kWH an:" << endl;
    cin >> use;

    //sortieren und ausgeben
    sort(list, use);

    //Auswahl des Stromanbieters
    cin.ignore();
    cout << "Geben sie den Namen ihres gewaehlten Stromanbieters an:" << endl;
    std :: getline(std:: cin, powerProvider);

    //Suche nach namen des Anbieters und passende Ausgabe
    search(list, powerProvider, use);
}

void aufgabe4()
{
    //Funktion: bool istPalindrom(string);
    //was muss geändert werden damit es für satzpalindrome funktioniert?
    //satzzeichen, großbuchstaben und leerzeichen ignorieren
    //eingabe vermeintliches palindrom, ausgabe ob ja oder nein.

    string satz;
    cin.ignore();
    cout << "Geben Sie bitte ihren Satz ein";
    getline(cin, satz);

    if(isPalindrom(satz) == true)
        cout << "Der Satz ist ein Palindrom" << endl;

    else
        cout << "Der Satz ist kein Palindrom" << endl;
}

int main()
{
    int input = 9;
    while(input != 0)
    {
        cout << "Welche Aufgabe soll ausgefuehrt werden?" << endl << "Mit 0 wird die Anwendung beendet." << endl;
        cin >> input;
        switch (input) {
        case 0: break;
        case 1: aufgabe1(); cout << endl; break;
        case 2: aufgabe2(); cout << endl; break;
        case 3: aufgabe3(); cout << endl; break;
        case 4: aufgabe4(); cout << endl; break;
        default: cout << "Diese Eingabe ist ungueltig. Versuchen sie es nochmal" << endl;
        }
    }
}



