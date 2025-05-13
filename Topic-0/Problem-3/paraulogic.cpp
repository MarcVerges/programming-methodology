#include <string.h>
#include "paraulogic.h"

//comporvacio de que la paraula conte la lletra princpial

bool laLletraCentral (char paraula[MAX_PARAULA], char lletres[N_LLETRES])
{
    char lletra =  lletres[0];
    int i = 0;
    bool esta = false;
    
    while ((paraula [i] != '\0') && (!esta))
    {
        if (paraula[i] == lletra )
        {
            esta = true;
        }
        else
        {
            i++;
        }
    }
    
    return esta;
}

//comproacio de que les lletres pertanyen a les posibles

bool lasLletresCorresponen (char paraula[MAX_PARAULA], char lletres[N_LLETRES])
{
    
    
    int  i = 0;
    bool paraulaCorrecte = true;
    
    while ((paraula[i] != '\0') && (paraulaCorrecte))
    {
        int j = 0;
        bool pertany = false;
        
        while ((j < N_LLETRES) && (!pertany))
        {
            if (paraula[i] == lletres[j])
            {
                pertany = true;
            }
            else
            {
                j++;
            }
        }
        
        if (!pertany)
        {
            paraulaCorrecte = false;
        }
        else
        {
            i++;
        }
    }
    
    return paraulaCorrecte;
}

//funcio que mira si la paraula es troba al diccioanari (no esta funcionant)
bool laParaulaDicci ( char paraula[MAX_PARAULA],char diccionari[N_PARAULES][MAX_PARAULA])
{
    //fem una cerca dins del diccionari per pasar-li les entrades 1 per 1
    
    int i = 0;
    bool esta = false;
    
    while ( (!esta) && (i < N_PARAULES ))
    {
        //fem una cerca dins le entrada i la paraula per comporvar las lletres 1 a 1
        
        int j = 0;
        bool coinxideix = true;
        
        while ((paraula[j] != '\0') && (coinxideix))
        {
            
            if (paraula[j] != diccionari [i][j])
            {
                coinxideix = false;
            }
            else
            {
                j++;
            }
        }
        i++;
        
        if (coinxideix)
        {
            esta = true;
        }

    }
    return esta;
}

//comparacio de que la paraula es tuti

bool esTutti (char paraula[MAX_PARAULA], char lletres[N_LLETRES])
{
    char lletra1 = lletres[0];
    char lletra2 = lletres[1];
    char lletra3 = lletres[2];
    char lletra4 = lletres[3];
    char lletra5 = lletres[4];
    char lletra6 = lletres[5];
    char lletra7 = lletres[6];
    
    bool blletra1 = false;
    bool blletra2 = false;
    bool blletra3 = false;
    bool blletra4 = false;
    bool blletra5 = false;
    bool blletra6 = false;
    bool blletra7 = false;
    
    
    for (int i = 0; paraula[i] != '\0'; i++)
    {
        if (paraula[i] == lletra1)
        {
            blletra1 = true;
        }
        if (paraula[i] == lletra2)
        {
            blletra2 = true;
        }
        if (paraula[i] == lletra3)
        {
            blletra3 = true;
        }
        if (paraula[i] == lletra4)
        {
            blletra4 = true;
        }
        if (paraula[i] == lletra5)
        {
            blletra5 = true;
        }
        if (paraula[i] == lletra6)
        {
            blletra6 = true;
        }
        if (paraula[i] == lletra7)
        {
            blletra7 = true;
        }
        
    }
    
    if ((blletra1) && (blletra2) && (blletra3) && (blletra4) && (blletra5) && (blletra6) && (blletra7))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

//calcul de punts

int puntsAconseguits (char paraula[MAX_PARAULA])
{
    int j = 0;
    
    for (int i = 0; paraula [i] != '\0'; i++)
    {
        j++;
    }
  
    
    if (j < 3)
    {
        return 0;
    }
    else
    {
        if (j == 3)
        {
            return 1;
        }
        else
        {
            if (j == 4)
            {
                return 2;
            }
            else
            {
                    return j;
                
            }
        }
    }
}




bool introdueixParaula(char paraula[MAX_PARAULA], char lletres[N_LLETRES],
    char diccionari[N_PARAULES][MAX_PARAULA], bool& tutti, int& puntuacio)
{
    tutti = false;
    bool compleix;
    
    if (laLletraCentral(paraula,lletres))
    {
        if (lasLletresCorresponen(paraula, lletres))
        {
            if(laParaulaDicci(paraula, diccionari))
            {
                tutti = esTutti(paraula, lletres);
                compleix = true;
                
                if (tutti == true)
                {
                    puntuacio = (puntsAconseguits(paraula)*2) ;
                }
                else
                {
                    puntuacio = puntsAconseguits(paraula);
                }
                
            }
            else
            {
                puntuacio = 0;
                compleix = false;
            }
        }
        else
        {
            puntuacio = 0;
            compleix = false;
        }
    }
    else
    {
        puntuacio = 0;
        compleix = false;
    }
    return compleix;
}
