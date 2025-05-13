#include "assignatura.h"

Assignatura::Assignatura()
{
    nomAssig = " ";
    
}
Assignatura::Assignatura(string nom)
{
    nomAssig = nom;
    nEstudiants = 0;
    
}
Assignatura::Assignatura(string nom, int nEstudiants2, string estudiants2 [][2])
{
    // es posible que hagis d eposar <= si no va
    nomAssig = nom;
    nEstudiants = nEstudiants2;
    
    for (int i = 0; i < nEstudiants; i++)
    {
        llistaEstudiants[i].inicialitza(estudiants2[i][1],estudiants2[i][0]);
    }
    
}

bool Assignatura:: afegeixNota(string niu, float nota)
{
    //fem una cerca per trobar si el estudiant
    
    int j = 0;
    bool esta = false;
    bool res = false;
    
    while ((j < nEstudiants) && (!esta))
    {
        if (llistaEstudiants[j].getNiu() == niu)
        {
            esta = true;
            
        }
        else
        {
            j++;
        }
    }
    
    //comprovem que no tingui el maxim de notes
    
    
    if (esta)
    {
        res = llistaEstudiants[j].afegeixNota(nota);
    }
    
    return res;
}

float Assignatura::calculaNotaMitjana(string niu)
{
    float res = -1;
    bool esta = false;
    int j = 0;
    
    //trobem la posicio del estudaint
    
    while ((j < nEstudiants) && (!esta))
    {
        if (llistaEstudiants[j].getNiu() == niu)
        {
            esta = true;
            
        }
        else
        {
            j++;
        }
    }
    
    if (esta)
    {
        res = llistaEstudiants[j].calculaNotaMitjana();
    }
    
    return res;
}









