//
//  seient.h
//  Tema 2 - Avaluable - Exercici 1
//
//  Created by Marc Verges on 1/5/23.
//
#ifndef SEIENT_H
#define SEIENT_H

#include "passatger.h"
#include <string>
using namespace std;

class Seient
{
public:
    Seient();
    Seient(const string& codi);
    ~Seient();

    void setCodi(const string& codi) { m_codi = codi; }
    void setPassatger(Passatger* p) { m_passatger = p; }

    bool assignaPassatger(const string& dni, const string& nom);
    bool eliminaPassatger();
    
    const string& getCodi () const { return m_codi; }
    Passatger* getPassatger() { return m_passatger; }
private:
    string m_codi;
    Passatger* m_passatger;
};

#endif
