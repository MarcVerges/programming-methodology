//
//  Titulacio.h
//  Tema 2 - Sessió 17
//
//  Created by Marc Verges on 17/5/23.
//

#pragma once
#include <forward_list>
#include "Estudiant.h"

class Titulacio
{
public:
    Titulacio(): m_nom(""), m_nEstudiants(0) {}
    void afegeixEstudiant(const string& niu, const string& nom, int anyInici);
    bool eliminaEstudiant(const string& niu);
    bool consultaEstudiant(const string& niu, Estudiant& e);
    void llegeixEstudiants(const string& nomFitxer);
    void mostraEstudiants();
    void eliminaEstudiantsAny(int any);
private:
    string m_nom;
    std::forward_list<Estudiant> m_estudiants;
    int m_nEstudiants;
};
