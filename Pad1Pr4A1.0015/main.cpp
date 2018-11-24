#include "aufgabe1.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <ctime>
#include <string>

using namespace std;


int main() {
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
