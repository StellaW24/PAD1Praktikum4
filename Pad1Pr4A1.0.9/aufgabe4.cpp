#include "aufgabe4.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <string>

using namespace  std;
//Funktion um von einem Satz das Palindrom zu bestimmen
bool isPalindrom(string satz) {
    //linke seite und rechte seite des satzes
    int leftl {0};
    int rightl = satz.size();

    //alles in kleinbuchstaben
    for(int i = 0; i < rightl; i++)
        satz[i] = tolower(satz[i]);

    //eigentlicher Vergleich von beiden Seiten
    while (leftl <= rightl) {
        if(!(satz[leftl] >= 'a' && satz[leftl] <= 'z' ))
            leftl++;

        else if(!(satz[rightl] >= 'a' && satz[rightl] <= 'z'))
            rightl--;

        else if(satz[leftl] == satz[rightl])
            leftl++, rightl--;

        else
            return false;

    }
    //Nur wenn die schleife komlpett durchläuft gibt es den wert true zurück
    return true;

}
