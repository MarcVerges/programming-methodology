//
//  Estudiant.h
//  Tema 2 - Sessió 14
//
//  Created by Marc Verges on 26/4/23.
//
#pragma once
#include <string>
using namespace std;

class Estudiant
{
public:
    Estudiant(): m_NIU(""), m_nom(""), m_nAssignatures(0), m_maxAssignatures(0), m_assignatures(nullptr) {};
    Estudiant(const string& niu, const string& nom, int nAssignatures);
    Estudiant(const Estudiant& e);
    Estudiant& operator=(const Estudiant& e);
    ~Estudiant();

    string getNiu() const { return m_NIU; }
    string getNom() const { return m_nom; }
    void setNiu(const string& niu) { m_NIU = niu; }
    void setNom(const string& nom) { m_nom = nom; }

    void afegeixAssignatura(const string& assignatura);
    int getNAssignatures() const { return m_nAssignatures; }
    string getAssignatura(int posicio) const;

    void inicialitza(const string& niu, const string& nom, int nAssignatures);
    void allibera();
private:
    string m_nom;
    string m_NIU;
    string *m_assignatures;
    int m_maxAssignatures;
    int m_nAssignatures;
};
