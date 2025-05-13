#include "biblioteca.h"


Biblioteca::Biblioteca()
{
    
}

void Biblioteca::afegeixLlibre(const Llibre& llibreAPosar)
{
    llibresGenerals[nLlibres].setAutor(llibreAPosar.getAutor());
    llibresGenerals[nLlibres].setTitol(llibreAPosar.getTitol());
    llibresGenerals[nLlibres].setnExemplars(llibreAPosar.getnExemplars());
    nLlibres++;
}

int Biblioteca::prestaLlibre(const string &titol, int &codiExemplar)
{
    int ret = 0;
    //comporvem que estigui el titol
    int j = 0;
    bool estaElLlibre = false;
    
    while ((j < nLlibres) && (!estaElLlibre))
    {
        if (titol == llibresGenerals[j].getTitol())
        {
            estaElLlibre = true;
        }
        else
        {
            j++;
        }
    }
    
    if (!estaElLlibre)
    {
        ret = -2;
    }
    else
    {
        codiExemplar = llibresGenerals[j].Agafarllibre();
        
        if (codiExemplar == -1)
        {
            ret = -1;
        }
        else
        {
            ret = 0;
        }
    }
    return ret;
}

int Biblioteca::retornaLlibre(const string &titol, int codiExemplar)
{
    int ret = 0;
    //comporvem que estigui el titol
    int j = 0;
    bool estaElLlibre = false;
    
    while ((j < nLlibres) && (!estaElLlibre))
    {
        if (titol == llibresGenerals[j].getTitol())
        {
            estaElLlibre = true;
        }
        else
        {
            j++;
        }
    }
    
    if (!estaElLlibre)
    {
        ret = -2;
    }
    else
    {
        ret = llibresGenerals[j].RetornarLlibre(codiExemplar);
        
    }
    
    return ret;
}


