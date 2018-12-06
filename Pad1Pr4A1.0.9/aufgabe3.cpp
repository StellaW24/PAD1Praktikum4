#include <iostream>
#include <aufgabe3.h>

using namespace std;


double calculate(double use, double kwh, double monthly, int bonus)
{
    double yearly;
    double power;
    power = use*kwh;
    yearly = (monthly*12) + power - bonus;
    return yearly;
}

void sort(listPowerProvider list[], double use)
{
    //struct für die sortierte Liste die ausgegeben wird
    struct sortedList {
        string name;
        double yearly;
    }sorted[6];

    //sortierte liste unsortiert füllen
    for(int i = 0; i < 6; i++)
    {
        sorted[i].name = list[i].name;
        sorted[i].yearly = calculate(use, list[i].kWH, list[i].monthly, list[i].bonus);
    }

    //liste sortieren (Selection Sort)
    for(int i = 0; i < 6; i++)
    {
        int smallest = i;
        struct sortedList min[6];
        min[i] = sorted[i];
        for(int j = i+1; j < 6; j++)
        {
            if(sorted[j].yearly < min[i].yearly)
            {
                    smallest = j;
                    min[i] = sorted[j];
            }
        }
        sorted[smallest] = sorted[i];
        sorted[i] = min[i];
    }

    //Liste ausgeben
    cout << "Name" << " | " << "Kosten im ersten Jahr" << endl;
    for(int i = 0; i < 6; i++)
    {
        cout << sorted[i].name << " | " << sorted[i].yearly << endl;
    }
}

void search(listPowerProvider list[], string name, double use)
{
    //sortieren um nach name suchen zu können, wer auch immer sich das überlegt hat (Selection Sort)
    for(int i = 0; i < 6; i++)
    {
        int smallest = i;
        listPowerProvider min[6];
        min[i] = list[i];
        for(int j = i+1; j < 6; j++)
        {
            if(list[j].name < min[i].name)
            {
                    smallest = j;
                    min[i].bonus = list[j].bonus;
                    min[i].kWH = list[j].kWH;
                    min[i].monthly = list[j].monthly;
                    min[i].name = list[j].name;
            }
        }
        list[smallest].bonus = list[i].bonus;
        list[smallest].kWH = list[i].kWH;
        list[smallest].monthly = list[i].monthly;
        list[smallest].name = list[i].name;
        list[i].bonus = min[i].bonus;
        list[i].kWH = min[i].kWH;
        list[i].monthly = min[i].monthly;
        list[i].name = min[i].name;
    }

    //Suche des Namens
    int x;
    bool found = false;
    int left = 0;
    int right = 5;
    int mid = (left + right) /2;
    //binäre Suche
    while(list[left].name <= list[right].name)
    {
        mid = (left + right) /2;
        if(name < list[mid].name)
        {
            right = mid - 1;
        }
        else if (name > list[mid].name)
        {
            left = mid + 1;
        }
        else
        {
            found = true;
            x = mid;
            break;
        }
    }

    //Ausgabe
    if(found)
    {
        //Jahrespreis errechnen, ohne Einrechnen des Bonus
        double calculated = calculate(use, list[x].kWH, list[x].monthly, 0);

        cout << "Sie haben den Stromanbieter " << list[x].name << " ausgewaehlt." << endl;
        cout << "Ihre jaehrlichen Stromkosten belaufen sich auf " << calculated << "." << endl;
        cout << "Im ersten Jahr erhalten sie einen Bonus von " << list[x].bonus << " für das Wechseln ihres Stromanbieters." << endl;
        cout << "Damit zahlen sie im ersten Jahr " << calculate(use, list[x].kWH, list[x].monthly, list[x].bonus) << "." << endl;
    }
    else
    {
        cout << "Keiner der Stromanbieter hat den angegeben Namen." << endl;
    }
}
