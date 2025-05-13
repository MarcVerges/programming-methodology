#pragma once
#include <string>
using namespace std;
const int MAX_EXEMPLARS = 10;

class Llibre
{
public:

    //constructors
    Llibre ();
    Llibre (string titol, string autor, int nExemplars);
    
    //general getters
    string getTitol () const  {return titol;}
    string getAutor () const  {return autor;}
    int getnExemplars() const {return nExemplars;}
    
    //general setters
    void setTitol(string titol1) {titol = titol1;}
    void setAutor (string autor1) {autor = autor1;}
    void setnExemplars (int nExemplars1) {nExemplars = nExemplars1;}
    
    
    //agafar llibres (torna el numero de exemplar que deix o un -1  si no s'ha pogut deixar ja que estan tots prestats)
    bool EsPotPrestar () const;
    int Agafarllibre();
    
    //retron de llibres (torna true si s'ha pogut tornar el llibre), (també torna el llibre al sistema)
    bool EstavaPrestat(int i)const ;
    int RetornarLlibre (int i );

private:
    string titol;
    string autor;
    int nExemplars;
    bool exemplarsGenerals[MAX_EXEMPLARS];
    

};
