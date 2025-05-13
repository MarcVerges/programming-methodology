//
//  jugada.cpp
//  Tema 1 - Avaluable 10 - 3.0
//
//  Created by Marc Verges on 4/4/23.
//

#include "jugada.h"

Jugada :: Jugada()
{
    for (int i = 0; i < NUM_LLETRES; i++)
    {
        m_paraula[i].setEstat(NO_DEFINIDA);
        m_paraula[i].setLletra(' ');
    }
}
//es crida nomes des de la inicalitzacio de wordle.
void Jugada:: setParaula (const string& paraulaSecreta)
{
    for (int i = 0; i < NUM_LLETRES; i++)
    {
        m_paraulaSecreta[i].setLletra(paraulaSecreta[i]);
    }
}

//inicalitza la paraula amb la paraula prposada
void Jugada :: incialitza (const string& paraulaPrposada)
{
    for (int i= 0; i < NUM_LLETRES; i++)
    {
        m_paraula[i].setLletra(paraulaPrposada[i]);
        m_paraula[i].setEstat(NO_DEFINIDA);
    }
}

//es retorna la pos de la lletra a el abecedari

int Jugada :: PosAlABC (const Lletra& aux)
{
    return aux.getLletra() - 'A';
}

//s'actualitzan els flags independents de cada una de las lletres a la paraula proposada i es modifica el ABC

void Jugada:: flagsDeLaPAraula (Lletra abecedari[NUM_LLETRES_ABC])
{
    for (int i = 0; i < NUM_LLETRES; i++)
    {
        int pos = PosAlABC(m_paraula[i]);
        
        m_paraula[i].setEstat(NO_EXISTEIX);
        abecedari[pos].setEstat(NO_EXISTEIX);
        
        if (m_paraula[i].getLletra() == m_paraulaSecreta[i].getLletra())
        {
            m_paraula[i].setEstat(POSICIO_CORRECTA);
            abecedari[pos].setEstat(POSICIO_CORRECTA);
            
        }
        else
        {
            int j = 0;
            bool esta = false;
            

            while ((j < NUM_LLETRES) && (!esta))
            {
                if (m_paraula[i].getLletra() == m_paraulaSecreta[j].getLletra())
                {
                    esta = true;
                    m_paraula[i].setEstat(POSICIO_INCORRECTA);
                    abecedari[pos].setEstat(POSICIO_INCORRECTA);
                }
                else
                {
                    j ++;
                }
            }
        }
    }
    
}

bool Jugada :: PartidaAcabada ()
{
    int r = 0;
    bool guanyat = true;
    
    while ((guanyat) && (r <NUM_LLETRES))
    {
        if (m_paraula[r].getEstat() != POSICIO_CORRECTA)
        {
            guanyat = false;
        }
        else
        {
            r ++;
        }
    }
    return guanyat;
}

ofstream& operator<<(ofstream& output, const Jugada& jugada)
{
    for (int i = 0; i < NUM_LLETRES; i++)
    {
        output << jugada.getLletra(i);
    }
    output << endl;
    
    return output;
}


