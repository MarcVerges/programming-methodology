//
//  Titulacio.cpp
//  Tema2 - Sessió 18
//
//  Created by Marc Verges on 19/5/23.
//
#include "Titulacio.h"
#include <fstream>
#include <iostream>
using namespace std;

void Titulacio::afegeixEstudiant(const string& niu, const string& nom, int anyInici)
{
    Estudiant e(niu,nom,anyInici);

    
    std :: list <Estudiant> :: iterator apuntador = m_estudiants.begin();
    std :: list <Estudiant> :: iterator afegirDerrera = m_estudiants.begin();
    
    while (apuntador != m_estudiants.end())
    {
        if ( apuntador ->getNom() > nom)
        {
            m_estudiants.insert(apuntador,e);
            m_nEstudiants ++;
            return;
        }
        apuntador ++;
    }
    m_estudiants.push_back(e);
    m_nEstudiants ++;
    
}

bool Titulacio::eliminaEstudiant(const string& niu)
{
    bool trobat = false;
    std::list<Estudiant>::iterator aux = m_estudiants.begin();
    while ((aux != m_estudiants.end()) && !trobat)
    {
        if (niu == (*aux).getNiu())
            trobat = true;
        else
        {
            aux++;
        }
    }
    if (trobat)
    {
        m_estudiants.erase(aux);
        m_nEstudiants--;
    }
    return trobat;
}

bool Titulacio::consultaEstudiant(const string& niu, Estudiant& e)
{
    bool trobat = false;
    std::list<Estudiant>::iterator aux = m_estudiants.begin();
    while ((aux != m_estudiants.end()) && (!trobat))
    {
        e = *aux;
        if (e.getNiu() == niu)
            trobat = true;
        else
            aux++;
    }
    return trobat;
}

void Titulacio::llegeixEstudiants(const string& nomFitxer)
{
    ifstream fitxer;
    fitxer.open(nomFitxer);
    
    if (fitxer.is_open())
    {
        string nom,niu;
        int any;
        
        fitxer >> niu;
        fitxer >> nom;
        fitxer >> any;
        
        while (!fitxer.eof())
        {
            afegeixEstudiant(niu,nom, any);
            m_nEstudiants ++;
            fitxer >> niu;
            fitxer >> nom;
            fitxer >> any;
        }
    }
    fitxer.close();

}

void Titulacio::mostraEstudiants()
{
    std :: list <Estudiant> :: reverse_iterator apuntador = m_estudiants.rbegin();
    
    while (apuntador != m_estudiants.rend())
    {
        cout << apuntador -> getNiu() << ", " << apuntador -> getNom() << ", " << apuntador -> getAnyInici() << endl;
        apuntador ++;
    }
}

void Titulacio::eliminaEstudiantsAny(int any)
{
    std :: list <Estudiant> :: iterator apuntador = m_estudiants.begin();
   
    
    while (apuntador != m_estudiants.end())
    {
        if ( apuntador -> getAnyInici() < any)
        {
            apuntador = m_estudiants.erase(apuntador);
            m_nEstudiants --;
        }
        else
        {
            apuntador ++;
            
        }
    }
}

