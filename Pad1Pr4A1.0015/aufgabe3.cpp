#include <iostream>

using namespace std;

struct listPowerProvider {
    string name;
    double monthly;
    double kWH;
    int bonus;
}static list[6];

double calculate(double use, double kwh, double monthly, int bonus)
{
    double yearly;
    double power;
    power = use*kwh;
    yearly = (monthly*12) + power - bonus;
    return yearly;
}

void sort(struct listPowerProvider list[], double use)
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

void search(string name, double use, struct listPowerProvider list[])
{
    //sortieren um nach name suchen zu können, wer auch immer sich das überlegt hat (Selection Sort)
    for(int i = 0; i < 6; i++)
    {
        int smallest = i;
        struct listPowerProvider min[6];
        min[i] = list[i];
        for(int j = i+1; j < 6; j++)
        {
            if(list[j].name < min[i].name)
            {
                    smallest = j;
                    min[i] = list[j];
            }
        }
        list[smallest] = list[i];
        list[i] = min[i];
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

        cout << "Sie haben den Stromanbieter " << list[x].name << " ausgewählt." << endl;
        cout << "Ihre jährlichen Stromkosten belaufen sich auf " << calculated << "." << endl;
        cout << "Im ersten Jahr erhalten sie einen Bonus von " << list[x].bonus << " für das Wechseln ihres Stromanbieters." << endl;
        cout << "Damit zahlen sie im ersten Jahr " << calculate(use, list[x].kWH, list[x].monthly, list[x].bonus) << "." << endl;
    }
    else
    {
        cout << "Keiner der Stromanbieter hat den angegeben Namen." << endl;
    }
}

/*
//versuch ob das hier funktioniert, soll nicht hier sein am ende
void aufgabe3()
{
    //Stromanbieter
    //eingabe des jahresverbrauchs in kwh, liste der stromanbieter in aufsteigender reihenfolge des jahrespreises ausgeben
    //InsertionSort ODER BubbleSort ODER SelectionSort
    //cin name des gewählten stromanbieters, mit binärer suche suchen, passende ausgabe
    //Funktionen: sort, search, calculate

    //liste erstellen
    struct listPowerProvider {
        string name;
        double monthly;
        double kWH;
        int bonus;
    };
    struct listPowerProvider list[6];
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
    //sort(list, use);      //schmeißt fehlermeldung. Warum?

    //Auswahl des Stromanbieters
    cout << "Geben sie den Namen ihres gewählten Stromanbieters an:" << endl;
    getline(std:: cin, powerProvider);

    //Suche nach namen des Anbieters und passende Ausgabe
    //search(powerProvider, list);

    //test calculate
    double monthly = list[4].monthly;
    double kHW = list[4].kWH;
    int bonus = list[4].bonus;
     cout << calculate(use, kHW, use, bonus) << endl;
}
*/
