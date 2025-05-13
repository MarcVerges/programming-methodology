//
//  wordle.cpp
//  Tema 1 - Avaluable 10 - 3.0
//
//  Created by Marc Verges on 4/4/23.
//
#include "wordle.h"
#include <fstream>


using namespace std;

Wordle :: Wordle()
{
    for (int i = 0; i < NUM_LLETRES_ABC; i++)
    {
        m_abecedari[i].setLletra('A' + i);
        m_abecedari[i].setEstat(NO_DEFINIDA);
    }
    m_nIntentes = 0;
    
}

void Wordle :: inicialitza(const string& paraula)
{
    for (int i = 0; i < MAX_INTENTS; i++)
    {
        m_jugades[i].setParaula(paraula);
    }
    for (int i = 0; i < NUM_LLETRES_ABC; i++)
    {
        m_abecedari[i].setLletra('A' + i);
        m_abecedari[i].setEstat(NO_DEFINIDA);
    }
    m_nIntentes = 0;
    
}

EstatPartida Wordle :: juga(const string& paraula)
{
    
    bool estat = true;
    
    m_jugades[m_nIntentes].incialitza(paraula);
    m_jugades[m_nIntentes].flagsDeLaPAraula(m_abecedari);
    estat = m_jugades[m_nIntentes].PartidaAcabada();
    m_nIntentes++;
    
    if ((estat == false) && (m_nIntentes < MAX_INTENTS))
    {
        return ACTIVA;
    }
    else
    {
        if (estat == true)
        {
            return FINAL_GUANYAT;
        }
        else
        {
            return FINAL_PERDUT;
        }

    }
}

void Wordle:: escriuPartida(const string& nomFitxer)
{
    ofstream fitxer;
    fitxer.open(nomFitxer);
    if (fitxer.is_open())
    {
        for ( int j = 0; j < m_nIntentes; j++)
        {
            fitxer << m_jugades[j];
        }
        
        fitxer << endl;
        
        for (int i = 0; i < NUM_LLETRES_ABC; i++)
        {
            fitxer << m_abecedari[i];
        }
      
        
        
    }
    fitxer.close();
}

