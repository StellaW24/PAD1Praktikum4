#include "aufgabe1.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <string>

using namespace std;





void aufgabe1() {

    vector<int> randomNumberVec;
    vector<int> randomNumberVec1;

    srand(time(NULL));

    long* array = 0;
    int n = rand()%9;
    long t = n + 1;
    int y = 5;

    randomNumbers(randomNumberVec1, t);

    array = new long[t];
    for (int i=0; i < t; i++){
        array[i] = randomNumberVec1[i];
    }
    for( int i=0; i < t; i++){
        cout <<array[i] << " ";
    }
    cout << endl;
    delete [] array;
    array = NULL;
}

void aufgabe2()
{
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



