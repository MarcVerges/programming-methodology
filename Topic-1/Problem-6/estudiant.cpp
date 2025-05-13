#include "estudiant.h"
#include <iostream>
#include <fstream>

using namespace std;

void Estudiant::inicialitza(const string& nom, const string& niu)
{
    m_nom = nom;
    m_niu = niu;
    m_nNotes = 0;
}

bool Estudiant::afegeixNota(float nota)
{
    bool correcte = false;
    
    if (m_nNotes < MAX_NOTES)
    {
        m_notes[m_nNotes++] = nota;
        correcte = true;
    }
    return correcte;
}

float Estudiant::calculaNotaMitjana() const
{
    float mitjana = -1.0;
    float suma = 0.0;
    for (int i = 0; i < m_nNotes; i++)
        suma += m_notes[i];
    if (m_nNotes > 0)
        mitjana = suma / m_nNotes;
    return mitjana;
}

bool Estudiant::operator==(const Estudiant &element) const
{
    bool ret = false;
    
    if ((element.getNiu() == m_niu) && (element.getNom() == m_nom))
    {
        ret = true;
    }
    return ret;
}

ostream& operator<<(ostream& output, const Estudiant& estudiant2)
{
    float mitjana = estudiant2.calculaNotaMitjana();
    output << estudiant2.getNom() << " " << estudiant2.getNiu() << " " << mitjana << endl;
    
    return output;
}

ofstream& operator<<(ofstream& output, const Estudiant& estudiant2)
{
    float mitjana = estudiant2.calculaNotaMitjana();
    output << estudiant2.getNom() << " " << estudiant2.getNiu() << " " << mitjana << endl;
    
    return output;
}
ifstream& operator>>(ifstream& input, Estudiant& estudiant)
{
    string nom,niu;
    float nota = 0;
    int n_notes = 0;
    
    input >> nom >> niu >> n_notes;
    Estudiant aux (nom,niu);
    
    estudiant = aux;
  
    
    for (int i = 0; i < n_notes ; i++)
    {
        input >> nota ;
        estudiant.afegeixNota(nota);
    }
    
    return input;
}
