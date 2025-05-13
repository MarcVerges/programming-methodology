//
//  lletra.h
//  Tema 1 - Avaluable 10 - 3.0
//
//  Created by Marc Verges on 4/4/23.
//
#ifndef LLETRA_H
#define LLETRA_H


#include "definicions.h"
#include <fstream>

using namespace std;

class Lletra {
public:
    Lletra(): m_lletra(' '), m_estat(NO_DEFINIDA) {}
    void setLletra(char lletra) {m_lletra = lletra;}
    void setEstat(EstatLletra estat) {m_estat = estat;}
    EstatLletra getEstat() const {return m_estat;}
    char getLletra() const {return m_lletra;}
private:
    char m_lletra;
    EstatLletra m_estat;
    
};

ofstream& operator<<(ofstream& output, const Lletra& lletra);

#endif
