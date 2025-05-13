//
//  wordle.h
//  Tema 1 - Avaluable 10 - 3.0
//
//  Created by Marc Verges on 4/4/23.
//
#ifndef WORDLE_H
#define WORDLE_H

#include "jugada.h"

class Wordle
{
public:
    Wordle();
    //rep paraula secreta
    void inicialitza(const string& paraula);
    
    //rep paraula prposada
    EstatPartida juga(const string& paraula);
    void escriuPartida(const string& nomFitxer);
private:
    int m_nIntentes;
    Lletra m_abecedari[NUM_LLETRES_ABC];
    Jugada m_jugades[MAX_INTENTS];
    

};



#endif
