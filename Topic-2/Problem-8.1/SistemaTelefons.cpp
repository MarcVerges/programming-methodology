//
//  SistemaTelefons.cpp
//  Tema 2 - Sessió 19 - 1
//
//  Created by Marc Verges on 24/5/23.
//
#include "SistemaTelefons.h"

SistemaTelefons::SistemaTelefons()
{
    if (m_cuaTelefons.size() != 0)
    {
        eliminarTot();
    }
}

void SistemaTelefons::introduirTelefon(const string& telf)
{
    m_cuaTelefons.push(telf);
}

string SistemaTelefons::servirTelefon()
{
    string ret;
    ret = m_cuaTelefons.front();
    m_cuaTelefons.pop();

    return ret;
}

void SistemaTelefons::eliminarTot()
{
    while (m_cuaTelefons.size() != 0)
    {
        m_cuaTelefons.pop();
    }
}
