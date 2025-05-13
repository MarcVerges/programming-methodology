#ifndef ASSIGNATURA_H
#define ASSIGNATURA_H
#include "estudiant.h"

const int MAX_ESTUDIANTS = 50;

class Assignatura
{
public:
    Assignatura();
    Assignatura(string nom);
    Assignatura(string nom, int nEstudiants, string alumnes [][2]);
    bool afegeixNota (string niu, float nota);
    float calculaNotaMitjana (string niu);
    
private:
    string nomAssig;
    Estudiant llistaEstudiants[MAX_ESTUDIANTS];
    int nEstudiants;
};

#endif
