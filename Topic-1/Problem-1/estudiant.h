#ifndef ESTUDIANT_H
#define ESTUDIANT_H
#include <string>
using namespace std;

const int MAX_LLETRES = 50;
const int MAX_NOTES = 5;

class Estudiant
{
    public:
    
    float notes[MAX_NOTES];
    float mitjana;
    
    //nom
    string getNom();
    void setNom (string c);
    
    //NIU
    string getNiu();
    void setNiu(string c);
    
    //afegir nota
    
    bool afegeixNota (float nota);
    
    //calcul de nota mitjana
    float calculaNotaMitjana ();
   
        
    
    private:
    string nom;
    string niu;
    
    

};


#endif

