//
//  SistemaTelefons.h
//  Tema 2 - Sessió 19 - 1
//
//  Created by Marc Verges on 24/5/23.
//
#include <queue>
#include <string>
using namespace std;

class SistemaTelefons
{
public:
    SistemaTelefons();
    void introduirTelefon(const string& telf);
    string servirTelefon();
    void eliminarTot();
    int getNumTelefons() { return m_cuaTelefons.size(); }

private:
    
    std :: queue<string> m_cuaTelefons;
  

};
