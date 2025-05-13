#ifndef LLISTA_H
#define LLISTA_H

#include "estudiant.h"
#include <iostream>
#include <fstream>
using namespace std;

int const MAX_LLISTA = 100;

class Llista
{
public:
    //constructors (no tocar)
    Llista() : m_nElements(0) {}
    Llista(const Estudiant v[], int mida);
    
    //obtenim el numero de elements a la arry llista
    int getNumElements() const { return m_nElements; }
    
    //ens indica si pertany
    bool pertany(const Estudiant& element) const;
    
    //ens trona la posicio amb el niu com  origen
    int cerca(const string& niu) const;
    
    //ens retorna el estudiant amb la posicio concreta
    Estudiant getElement(int posicio) const;
    
    //funció interna del insereix (millor no utilitzar) / nomes utilitzar per sobreescriure elements no per afegir .
    void setElement(int posicio, const Estudiant& estudiant);
    
    //insereix el element en funcio de la posició fent les comporvacions previes i mou la array (el operador + nomes insereix al final)
    bool insereix(const Estudiant& element, int posicio);
    
    //elimina un element fent les comprovacions previes i mou la array (millor utilitzar la sobrecarrega - )
    bool elimina(int posicio);
   
    //suma el element a la primera posicio disponible de la array general
    bool operator+(const Estudiant &element);
    
    //borra el element de la array general
    bool operator-(const Estudiant &element);

 
    

private:
    int m_nElements;
    Estudiant totEstudiants[MAX_LLISTA];

};


ostream& operator<<(ostream& output, const Llista& llista);
ofstream& operator<<(ofstream& output, const Llista& llista);
ifstream& operator>>(ifstream& input, Llista& llista);

#endif
