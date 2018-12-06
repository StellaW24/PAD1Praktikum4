#include <iostream>

#ifndef AUFGABE3_H
#define AUFGABE3_H

#endif // AUFGABE3_H

using namespace std;

struct listPowerProvider {
    string name;
    double monthly;
    double kWH;
    int bonus;
}static list[6];

double calculate(double use, double kwh, double monthly, int bonus);

void sort(listPowerProvider list[], double use);

void search(listPowerProvider list[], string name, double use);
