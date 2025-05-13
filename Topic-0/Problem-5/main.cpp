#include "punt.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;


void mostraBool(bool valor)
{
    if (valor)
        cout << "TRUE ";
    else
        cout << "FALSE ";
}


int main()
{
    float grade = 10.0;
    float reduccio = 2.0;
    Punt punts[30];
    int nPunts;
    float d;

    fstream fitxerTest;

    string nomFitxer;
    nomFitxer = "punts.txt";
    fitxerTest.open(nomFitxer);
    fitxerTest >> nPunts;
    cout << "Comment :=>> N. de punts: " << nPunts << endl;
    cout << "Comment :=>> Coordenades dels punts: ";

    int i = 0;
    while (!fitxerTest.eof())
    {
        fitxerTest >> punts[i].x >> punts[i].y;
        mostraPunt(punts[i]);
        i = i + 1;
    }
    cout << endl;
    fitxerTest.close();

    cout << "Comment :=>> -----" << endl;

    cout << endl << endl;
    cout << "Comment :=>> INICIANT TEST" << endl;
    cout << "Comment :=>> =============" << endl;
    cout << "Comment :=>> " << endl;
    cout << "Grade :=>> " << grade << endl;

    for (int i = 0; i < nPunts - 1; i++)
    {
        for (int j = i + 1; j < nPunts; j++)
        {
            d = sqrt(pow(punts[i].x - punts[j].x, 2) + pow(punts[i].y - punts[j].y, 2));
            if (distanciaPunts(punts[i], punts[j]) != d)
            {
                grade -= reduccio;
            }
        }
    }
    if (grade < 0)
        grade = 0.0;
    if (grade == 10.0)
        cout << "Comment :=>> Final del test sense errors" << endl;
    cout << "Grade :=>> " << grade << endl;

    return 0;
}
