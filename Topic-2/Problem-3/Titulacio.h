//
//  Titulacio.h
//  Tema 2 - Sessió 14
//
//  Created by Marc Verges on 26/4/23.
//
#pragma once
#include "Estudiant.h"
const int MAX_ESTUDIANTS = 300;

class Titulacio
{
public:
    Titulacio()
    {
        m_nom = " ";
        m_nMaxAssignatures = 0;
        m_nEstudiants = 0;
        m_nMaxEstudiants = 0;
        m_estudiants = new Estudiant [m_nMaxEstudiants];
    }
    Titulacio(const string& nom, int maxAssignatures, int maxEstudiants)
    {
        m_nom = nom;
        m_nMaxAssignatures = maxAssignatures;
        m_nMaxEstudiants = maxEstudiants;
        m_nEstudiants = 0;
        m_estudiants = new Estudiant [m_nMaxEstudiants];
    }
    Titulacio(const Titulacio& t);
    Titulacio& operator=(const Titulacio& t);
    ~Titulacio()
    {
        delete [] m_estudiants;
        m_estudiants = nullptr;
    }
    void afegeixEstudiant(const string& niu, const string& nom);
    bool eliminaEstudiant(const string& niu);
    Estudiant* consultaEstudiant(const string& niu);
    Estudiant getEstudiant(int posicio) { return m_estudiants[posicio]; }
    string getNom() const { return m_nom; }
    int getMaxAssignatures() const { return m_nMaxAssignatures; }
    int getMaxEstudiants() const { return m_nMaxEstudiants; }
    int getNEstudiants() const { return m_nEstudiants; }
private:
    string m_nom;
    int m_nMaxAssignatures;
    Estudiant *m_estudiants;
    int m_nMaxEstudiants;
    int m_nEstudiants;
};
