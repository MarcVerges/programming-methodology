//
//  jugada.h
//  Tema 1 - Avaluable 10 - 3.0
//
//  Created by Marc Verges on 4/4/23.
//
#ifndef JUGADA_H
#define JUGADA_H

#include "lletra.h"


class Jugada
{
public:
    Jugada();
    void setParaula (const string& paraulaSecreta);
    void incialitza (const string& paraulaPrposada);
    void flagsDeLaPAraula (Lletra abecedari[NUM_LLETRES_ABC]);
    int PosAlABC (const Lletra& aux);
    bool PartidaAcabada ();
    Lletra getLletra (int pos) const {return m_paraula[pos];}
                                              
private:
    Lletra m_paraula[NUM_LLETRES];
    Lletra m_paraulaSecreta [NUM_LLETRES];
};


ofstream& operator<<(ofstream& output, const Jugada& jugada);



#endif
