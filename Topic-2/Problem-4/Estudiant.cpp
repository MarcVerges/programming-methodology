//
//  Estudiant.cpp
//  Tema 2 - Sessió 15
//
//  Created by Marc Verges on 28/4/23.
//
#include "Estudiant.h"
#include <iostream>

Estudiant::Estudiant(const string& niu, const string& nom, int nAssignatures)
{
    m_NIU = niu;
    m_nom = nom;
}

Estudiant::~Estudiant()
{
}

void Estudiant::inicialitza(const string& niu, const string& nom)
{
    m_NIU = niu;
    m_nom = nom;
    m_assignatures.clear();
}

void Estudiant::allibera()
{
    m_assignatures.clear();
}

void Estudiant::afegeixAssignatura(const string& assignatura)
{
    m_assignatures.push_back(assignatura);
}


// PER COMPLETAR
void Estudiant::insereixAssignatura(const string& assignatura)
{
    // Declarar iterador  v
    
    vector<string> :: iterator actual,final;
    
    // Inicialitzar iterador al primer element del vector
    actual = m_assignatures.begin();
    final = m_assignatures.end();

    bool trobat = false;

    while (!trobat && actual != final)
    {
        if ( *actual > assignatura)
            trobat = true;
        else
            actual ++;
    }
    m_assignatures.insert(actual, assignatura);
}


// PER COMPLETAR
void Estudiant::eliminaAssignatura(const string& assignatura)
{
    vector<string> :: iterator actual;
    actual = m_assignatures.begin();
   
    bool trobat = false;

    while (!trobat && actual != m_assignatures.end())
    {
        if ( *actual == assignatura)
            trobat = true;
        else
            actual++;
    }
    m_assignatures.erase(actual);
}



void Estudiant::mostraAssignatures()
{
    vector<string> :: iterator actual;
    actual = m_assignatures.begin();
    
    for (actual = m_assignatures.begin(); actual != m_assignatures.end(); actual ++)
    {
        cout << *actual << endl;
    }
}

string Estudiant::getAssignatura(int posicio) const
{
    if ((posicio >= 0) && (posicio < m_assignatures.size()))
        return m_assignatures[posicio];
    else return "";
}




