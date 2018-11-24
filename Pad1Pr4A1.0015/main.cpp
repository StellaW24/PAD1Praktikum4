#include "aufgabe1.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <string>

using namespace std;


void aufgabe1() {
    vector<int>randomNumberVec {};
    int k {};
    int border {};
    cout << "bitte erst anzahl an gewuenschten Zahlen eingeben, danach die grenze" <<endl;
    cin >> k >> border;

    srand(time(NULL));

    randomNumbers(randomNumberVec, k, border);

    //Beispiel für die übergabe eines Arrays in einer Funktion
    int feld1[][3] = {{1, 2, 3}, {4, 5, 6}};
    tabellenausgabe2D(feld1, 2);
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
            case 1: aufgabe1(); break;
            case 2: break; // aufgabe2()
            case 3: break; // aufgabe3()
            case 4: break; // aufgabe4()
            default: cout << "Diese Eingabe ist ungueltig. Versuchen sie es nochmal" << endl;
        }
    }
}
