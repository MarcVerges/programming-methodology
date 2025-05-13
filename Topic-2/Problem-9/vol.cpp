//
//  vol.cpp
//  Tema 2 - Avaluable - Exercici 1
//
//  Created by Marc Verges on 1/5/23.
//
#include "vol.h"

void Vol::afegeixSeients(string* codiSeients, int nSeients)
{
    for (int i = 0; i < nSeients; i++)
    {
        m_seients[m_nSeients] = codiSeients[i];
        m_nSeients++;
    }
}

bool Vol::afegeixPassatger(const string& codiSeient, const string& dni, const string& nom)
{
    
    int i = 0;
    bool esta = false;
    
    while ((i < m_nSeients)&&(!esta))
    {
        if ((m_seients[i].getCodi() == codiSeient) && (m_seients[i].getPassatger() == nullptr))
        {
            esta = m_seients[i].assignaPassatger(dni,nom);
        }
        else
        {
            i++;
        }
    }
    return esta;
}

bool Vol::cancelaReserva(const string& codiSeient)
{
    int i = 0;
    bool esta = false;
    
    while ((i < m_nSeients)&&(!esta))
    {
        if ((m_seients[i].getCodi() == codiSeient) && (m_seients[i].getPassatger() != nullptr))
        {
            esta = m_seients[i].eliminaPassatger();
        }
        else
        {
            i++;
        }
    }
    return esta;
}

Passatger* Vol::recuperaPassatger(const string& codiSeient)
{
    
    int j = 0;
    bool esta = false;
    
    while ((j < m_nSeients) && (!esta))
    {
        if ((m_seients[j].getCodi() == codiSeient) && (m_seients[j].getPassatger() != nullptr))
        {
            esta = true;
        }
        else
        {
            j++;
        }
    }
    if (esta)
    {
        return m_seients[j].getPassatger();
    }
    else
    {
        return nullptr;
    }
}

bool Vol::modificaReserva(const string& codiSeientOriginal, const string& codiSeientNou)
{
    Passatger* apuntador = recuperaPassatger(codiSeientOriginal);
    
    int i = 0;
    bool esta = false;
    
    while ((i < m_nSeients) && (!esta))
    {
        if ((m_seients[i].getCodi() == codiSeientNou) && (m_seients[i].getPassatger() == nullptr))
        {
            esta = true;
        }
        else
        {
            i++;
        }
    }
    
    if ((apuntador != nullptr) && (esta == true))
    {
        string dni = apuntador -> getDni();
        string nom = apuntador -> getNom();
        cancelaReserva(codiSeientOriginal);
        afegeixPassatger(codiSeientNou,dni,nom);
        return true;
    }
    else
    {
        return false;
    }
}
