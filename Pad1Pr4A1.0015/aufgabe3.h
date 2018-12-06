#include <iostream>
#include "string.h"
//#include <string>

#ifndef AUFGABE3_H
#define AUFGABE3_H

#endif // AUFGABE3_H

struct listPowerProvider {
    String name;
    double monthly;
    double kWH;
    int bonus;
}static list[6];

double calculate(double use, double kwh, double monthly, int bonus);

void sort(listPowerProvider list[], double use);

void search(string name, struct listPowerProvider list[]);
