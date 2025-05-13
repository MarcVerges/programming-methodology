#include "estudiant.h"
#include <iostream>

//crear funcio que imprimexi el NIU.

string Estudiant:: getNiu()
{
    return niu;
}

//crear funcio que et permeti escriure el nom.

void Estudiant:: setNiu(string NIU)
{
    niu = NIU;
}
//crear funcio que imprimexi el nom.

string Estudiant::getNom()
{
    return nom;
}

//crear funcio que et permeti escriure el nom.

void Estudiant::setNom(string c)
{
    nom = c;
}

//crear funcio que permet incormporar una nota i retrona i s'ha pogut fer

bool Estudiant::afegeixNota(float nota)
{
    bool esPot = false;
    int j = 0;
    
    //comporva si es pot escriure
    while ((j < MAX_NOTES) && (!esPot))
    {
        if (notes[j] == -1)
        {
            notes [j] = nota;
            esPot = true;
        }
        else
        {
            j++;
        }
    }
    return esPot;
}

//crear funcio que calcula la mitjana si no te cap nota retron -1

float Estudiant:: calculaNotaMitjana()
{
    int j = 0;
    float sum = 0;
    //contador de el numero de notes
    
    for (int i = 0;i < MAX_NOTES; i++)
    {
        if (notes[i] != -1)
        {
            sum = sum + notes[i];
            j++;
        }
       
    }
    if (j != 0)
    {
        return (sum/j);
    }
    else
    {
        return -1;
    }
    
}
