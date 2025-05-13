#include "operacions_data.h"

void ordenaDates(const string& nomFitxerIn, const string& nomFitxerOut)
{
    Data conjuntDates [MAX_DATES];
    
    //llegim el fitxer
    
    ifstream fitxer;
    fitxer.open(nomFitxerIn);
    
    int i = 0;
    while (!fitxer.eof())
    {
       fitxer >> conjuntDates[i];
        i++;
    }
    
    fitxer.close();
    
    int numdates = i-1;
    
    //ordenem el vector
    
    Data aux;
    
    for (int z = 0; z < numdates; z++)
    {
        for (int j= 0; j < numdates-z-1; j++)
        {
            if (conjuntDates[j + 1] < conjuntDates[j] )
            {
                aux = conjuntDates[j];
                conjuntDates[j] = conjuntDates[j + 1];
                conjuntDates[j+1] = aux;
            }
        }
    }
 
    //escribim el vector ordenat
    
    ofstream fitxer2;
    fitxer2.open(nomFitxerOut);
    
    for (int j = 0; j < numdates; j++)
    {
        fitxer2 << conjuntDates[j];
    }
}

