//
//  Estudiant.cpp
//  Tema 2 - Sessió 13
//
//  Created by Marc Verges on 20/4/23.
//
#include "Estudiant.h"

Estudiant::Estudiant(const string& niu, const string& nom, int nAssignatures)
{
    
    m_NIU  = niu;
    m_nom = nom;
    m_nAssignatures = 0;
    m_maxAssignatures = nAssignatures;
    m_assignatures = new string[m_maxAssignatures];

}
Estudiant::~Estudiant()
{
    if (m_assignatures != nullptr)
    {
        delete[] m_assignatures;
    }
    
}

void Estudiant::inicialitza(const string& niu, const string& nom, int nAssignatures)
{
    m_nom = nom;
    m_NIU = niu;
    m_maxAssignatures= nAssignatures;
    m_assignatures = new string[m_maxAssignatures];
    m_nAssignatures = 0;
    
}

void Estudiant::allibera()
{
    if (m_assignatures != nullptr)
    {
        delete[] m_assignatures;
        m_assignatures = nullptr;
        m_nAssignatures = 0;
        m_maxAssignatures = 0;
    }
}

void Estudiant::afegeixAssignatura(const string& assignatura)
{
    if(m_assignatures != nullptr)
    {
        m_assignatures[m_nAssignatures++] = assignatura;
    }
    
}

string Estudiant::getAssignatura(int posicio) const
{
    if (m_assignatures != nullptr)
        return m_assignatures[posicio];
    else return "";
}
