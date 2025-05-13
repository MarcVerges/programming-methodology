#include "assignatura.h"


void Assignatura:: setnEstudiant(int n)
{
    nEstudiants = n;
}
Assignatura::Assignatura(string nom, int nEstudiants, string estudiants[MAX_ESTUDIANTS][2])
{
    m_nom = nom;
    Estudiant aux;
    for (int i = 0; i < nEstudiants; i++)
    {
        aux.setNom(estudiants[i][1]);
        aux.setNiu(estudiants[i][0]);
        
        m_estudiants.insereix(aux,i);
    }
    
    setnEstudiant(nEstudiants);
}

int Assignatura::cercaEstudiant(string niu)
{
    return m_estudiants.cerca(niu);
}

bool Assignatura::afegeixNota(string niu, float nota)
{
    
    
    bool correcte = false;
    int pos;
    
    pos = cercaEstudiant(niu);
    
    
    if (pos == -1)
    {
        correcte = false;
      
    }
    else
    {
        Estudiant aux;
        
        aux = m_estudiants.getElement(pos);
        correcte = aux.afegeixNota(nota);
        m_estudiants.setElement(pos,aux);
    }
    return correcte;
}

float Assignatura::calculaNotaMitjana(string niu)
{
    float mitjana;
    int pos = cercaEstudiant(niu);
    if (pos != -1)
    {
        Estudiant aux;
        aux = m_estudiants.getElement(pos);
        mitjana = aux.calculaNotaMitjana();
    }
        
    else
    {
        mitjana = -1.0;
    }
    
    return mitjana;
}
