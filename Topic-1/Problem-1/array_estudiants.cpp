#include "estudiant.h"

void afegeixEstudiant(Estudiant estudiants[], int nEstudiants, string nom, string niu)
{
    estudiants[nEstudiants + 1].setNom(nom);
    estudiants[nEstudiants + 1].setNiu(niu);
    
    for (int i = 0; i < MAX_NOTES; i++)
    {
        estudiants[nEstudiants + 1].notes[i] = -1;
    }
    

}

bool afegeixNota(Estudiant estudiants[], int nEstudiants, string niu, float nota)
{
    //fem una cerca del estudiant
    int i = 0;
    bool res = false;
    bool esta = false;
   
    while ((i < nEstudiants) && (!res) && (!esta))
    {
        if (estudiants[i].getNiu() == niu )
        {
            res = estudiants[i].afegeixNota(nota);
            esta = true;
        }
        else
        {
            i++;
        }
    }
    if ((esta == true) && (res == true))
    {
        return true;
    }
    else
    {
        return false;
    }
 
}

float calculaNotaMitjana(Estudiant estudiants[], int nEstudiants, string niu)
{
    int i = 0;
    bool esta = false;
    float mitjana = 0;
    
    while ((i < nEstudiants) && (!esta))
    {
        if (estudiants[i].getNiu() == niu )
        {
            mitjana = estudiants[i].calculaNotaMitjana();
            esta = true;
           
        }
        else
        {
            i++;
        }
    }
    
    if ((mitjana == -1) || (!esta))
    {
        return -1;
    }
    else
    {
        return mitjana;
    }
}
