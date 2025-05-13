#include "llibre.h"


Llibre :: Llibre ()
{
    autor = " ";
    titol = " ";
    nExemplars = 0;
    
    for (int i = 0; i < MAX_EXEMPLARS; i++)
    {
        exemplarsGenerals[i] = true;
    }
}

Llibre :: Llibre (string titol1, string autor1, int nExemplars1)
{
    titol = titol1;
    autor = autor1;
    nExemplars = nExemplars1;
    
    for (int i = 0; i < nExemplars; i++)
    {
        exemplarsGenerals[i] = true;  //si esta en true el llibre esta
    }
}



bool Llibre :: EsPotPrestar() const
{
    //Comprovem si tenim exemplars per prestar
    
    bool podemPrestar = false;
    int j = 0;
    
    while ((j < nExemplars) && (!podemPrestar))
    {
        if (exemplarsGenerals[j] == true)
        {
            podemPrestar = true;
        }
        else
        {
            j++;
        }
    }
    return podemPrestar;
}

int Llibre :: Agafarllibre()
{
    //funcio que treu del sistema el llibre i retorna el numero de exemplar si es pot presetar i sino retronar -1
    
    bool esta = false;
    int ret = -1;
    
    if (EsPotPrestar() == true)
    {
        //busquem el primer exemplar a prestar
        
        int i = 0;
        
        while ((i < nExemplars) && (!esta))
        {
            if (exemplarsGenerals[i] == true)
            {
                exemplarsGenerals[i] = false;
                esta = true;
                ret = i;
            }
            else
            {
                i++;
            }
        }
    }
    
    return ret;
}

bool Llibre :: EstavaPrestat(int numExemplar) const
{
    //comporvem si el llibre estava prestat, si ho estava retornem true
   
    bool estavaPrestat = false;
    
    if (exemplarsGenerals[numExemplar] == false)
    {
        estavaPrestat = true;
    }
    
    return estavaPrestat;
}

int Llibre :: RetornarLlibre(int numExemplar)
{
    //funcio que torna si s'ha pogut retornar i posa de nou el llibre al sistema 
    
    int ret;
    
    if (EstavaPrestat(numExemplar) == true)
    {
        exemplarsGenerals[numExemplar] = true;
        ret = 0;
    }
    else
    {
        ret = -1;
    }
    
    return ret;
}



