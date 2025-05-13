#pragma once
#include "llibre.h"
#include <string>
using namespace std;


const int MAX_LLIBRES = 100;

class Biblioteca
{
public:
    Biblioteca();
    void afegeixLlibre(const Llibre& llibre);
    int prestaLlibre(const string& titol, int& codiExemplar);
    int retornaLlibre(const string& titol, int codiExemplar);
    
    
private:
    Llibre llibresGenerals[MAX_LLIBRES];
    int nLlibres = 0;

};
