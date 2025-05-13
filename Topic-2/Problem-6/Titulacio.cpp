//
//  Titulacio.cpp
//  Tema 2 - Sessió 17
//
//  Created by Marc Verges on 17/5/23.
//

#include "Titulacio.h"
#include <fstream>
#include <iostream>
using namespace std;

void Titulacio::afegeixEstudiant(const string& niu, const string& nom, int anyInici)
{
    Estudiant estudiantAux(niu, nom, anyInici);
    m_estudiants.push_front(estudiantAux);
    m_nEstudiants++;
}

bool Titulacio::eliminaEstudiant(const string& niu)
{
    bool trobat = false;
    std::forward_list<Estudiant>::iterator aux = m_estudiants.begin();
    std::forward_list<Estudiant>::iterator anterior = m_estudiants.before_begin();
    while ((aux != m_estudiants.end()) && !trobat)
    {
        if (niu == (*aux).getNiu())
            trobat = true;
        else
        {
            anterior = aux;
            aux++;
        }
    }
    if (trobat)
    {
        m_estudiants.erase_after(anterior);
        m_nEstudiants--;
    }
    return trobat;
}

bool Titulacio::consultaEstudiant(const string& niu, Estudiant& e)
{
    bool trobat = false;
    std::forward_list<Estudiant>::iterator aux = m_estudiants.begin();
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
        
        string niu,nom;
        int any;
        
        fitxer >> niu;
        fitxer >> nom;
        fitxer >> any;
        
        afegeixEstudiant(niu, nom,any);
        std :: forward_list<Estudiant> :: iterator actual = m_estudiants.begin();
        
        fitxer >> niu;
        fitxer>>nom;
        fitxer >> any;
        
        while (!fitxer.eof())
        {
            Estudiant aux;
            aux.setNom(nom);
            aux.setNiu(niu);
            aux.setAnyInici(any);
            m_estudiants.insert_after(actual, aux);
            actual ++;
            m_nEstudiants ++;
            fitxer >> niu;
            fitxer>>nom;
            fitxer >> any;
        }
    }
    fitxer.close();
}

void Titulacio::mostraEstudiants()
{
    std :: forward_list<Estudiant> :: iterator actual = m_estudiants.begin();
   
    while (actual != m_estudiants.end())
    {
        cout << actual -> getNiu() << " , " << actual -> getNom() << " , " << actual-> getAnyInici() << endl;
        actual ++;
    }
}

void Titulacio::eliminaEstudiantsAny(int any)
{
    std :: forward_list<Estudiant> :: iterator anterior = m_estudiants.before_begin();
    std :: forward_list<Estudiant> :: iterator eliminar = m_estudiants.begin();
  

    
    while (eliminar != m_estudiants.end())
    {
        if ( eliminar -> getAnyInici() < any)
        {
            eliminar = m_estudiants.erase_after(anterior);
        }
        else
        {
            anterior ++;
            eliminar++;
        }
    }
}
