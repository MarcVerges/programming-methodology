//
//  seient.cpp
//  Tema 2 - Sessió 12
//
//  Created by Marc Verges on 14/4/23.
//
#include "seient.h"
Seient :: Seient()
{
    m_passatger = nullptr;
    m_codi = " ";
    
}
Seient :: ~Seient()
{
    delete m_passatger;
    m_passatger = nullptr;
}
bool Seient::assignaPassatger(const string& dni, const string& nom)
{
    //comporobem que el seint no esigui assignat
    
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
        m_codi = "";
        delete m_passatger;
        m_passatger = nullptr;
        return true;
    }
    else
    {
        return false;
    }
}
