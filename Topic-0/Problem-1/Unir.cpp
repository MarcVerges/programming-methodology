#include "Unir.hpp"



bool cercaElement(int vector[], int mida, int valor)
{
    bool condicio = false;
    int i = 0;
    
    while ((i< mida) && (!condicio))
    {
        if (valor == vector[i])
        {
            condicio = true;
        }
        else
        {
            i++;
        }
    }
    return condicio;
}



int cercaPosicio(int vector[], int mida, int valor)
{
    int i = 0;
    bool condicio = false;
    
    while ((i < mida) && (!condicio))
    {
        if (valor < vector [i])
        {
            condicio = true;
        }
        else
        {
            i++;
        }
    }
    return i;

}

void afegeixOrdenadament(int vector[], int& mida, int valor)
{
    int i;
    int posicio;

    posicio = cercaPosicio(vector,mida,valor);
    
    for (int i = mida - 1; i >= posicio; i--)
    {
        vector[i+1] = vector [i];
    }
    vector[posicio] = valor;
}



void uneixVectors(int vector1[], int mida1, int vector2[], int mida2, int vectorUnio[], int& midaUnio)
{
    midaUnio = 0;
  
    for (int i = 0; i <mida1 ; i ++)
    {
        afegeixOrdenadament(vectorUnio, midaUnio, vector1[i]);
        midaUnio ++;
    }
    
    for (int i  = 0; i < mida2 ; i++)
    {
        if (!cercaElement(vectorUnio, midaUnio, vector2[i]))
        {
            afegeixOrdenadament(vectorUnio, midaUnio, vector2[i]);
            midaUnio ++ ;
        }
    }
}

void uneixVectorsOrdenats(int vector1[], int mida1, int vector2[], int mida2, int vectorUnio[], int& midaUnio)
{
    midaUnio = 0;
  
    for (int i = 0; i <mida1 ; i ++)
    {
        vectorUnio[i] = vector1[i];
        midaUnio ++;
    }
    
    for (int i  = 0; i < mida2 ; i++)
    {
        if (!cercaElement(vectorUnio, midaUnio, vector2[i]))
        {
            afegeixOrdenadament(vectorUnio, midaUnio, vector2[i]);
            midaUnio ++ ;
        }
    }
  
}
