//
//  seient.cpp
//  Tema 2 - Avaluable - Exercici 1
//
//  Created by Marc Verges on 1/5/23.
//
#include "seient.h"

Seient::Seient()
{
    m_codi = " ";
    m_passatger = nullptr;
}
Seient :: Seient(const string& codi)
{
    m_codi = codi;
    m_passatger = nullptr;
}

Seient :: ~Seient()
{
    delete m_passatger;
    m_passatger = nullptr;
}

bool Seient::assignaPassatger(const string& dni, const string& nom)
{
    if (m_passatger == nullptr)
    {
        m_passatger = new Passatger;
        m_passatger -> setDni(dni);
        m_passatger -> setNom(nom);
        return true;
    }
    else
    {
        return false;
    }
}

bool Seient::eliminaPassatger()
{
    if (m_passatger != nullptr)
    {
        delete m_passatger;
        m_passatger = nullptr;
        return true;
    }
    else
    {
        return false;
    }
}
