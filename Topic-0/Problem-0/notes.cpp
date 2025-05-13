#include "notes.hpp"


void converteixNotes(float notesNumeriques[MAX_NOTES], int nEstudiants, char notesActa[MAX_NOTES],
    float& notaMinima, float& notaMaxima, float& notaMitja)
{
   int i,estudi= 0;
    float sum = 0;

    notaMaxima = notesNumeriques[0];
    notaMinima =  notesNumeriques [0];

    for (i= 0; i < nEstudiants;i++)
    {
        //administracio de lletres.
        if (notesNumeriques[i]== -1)
        {
            notesActa[i] = 'P';
        }
        else
        {
            if (notesNumeriques[i] >= 0.00 && notesNumeriques[i] <= 4.99)
            {
                notesActa[i] = 'S';
            }

            else
            {
                if (notesNumeriques[i] >= 5.00 && notesNumeriques[i] <= 6.99)
                {
                    notesActa[i] = 'A';
                }
                else
                {
                    if (notesNumeriques[i] >= 7.00 && notesNumeriques[i] <= 8.99)
                    {
                        notesActa[i] = 'N';
                    }
                    else
                    {
                        if (notesNumeriques[i] >= 9.00 && notesNumeriques[i] <= 9.99)
                        {
                            notesActa[i] = 'E';
                        }
                        else
                        {
                                notesActa[i] = 'M';
                            
                        }
                    }
                }
            }
        }
       
        //nota minima

        if (notesNumeriques[i] > notaMaxima)
        {
            notaMaxima= notesNumeriques[i];
        }
        if ((notesNumeriques[i] < notaMinima) && (notesNumeriques[i] != -1))
        {
            notaMinima= notesNumeriques[i];
        }

        // calculador de mitjana
        
        if (notesNumeriques[i] != -1)
        {
        sum = sum + notesNumeriques[i];
        estudi ++;
        }


    }
    notaMitja = sum / estudi;
    
     if (sum == 0)
    {
        notaMitja = -1;
    }
    
    


    }
