//
//  main.cpp
//  Tema 2 - Sessió 17
//
//  Created by Marc Verges on 17/5/23.
//

#include "Titulacio.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    Titulacio titulacio;
    titulacio.llegeixEstudiants("Estudiants.txt");
    titulacio.mostraEstudiants();
    titulacio.eliminaEstudiantsAny(2017);
    titulacio.mostraEstudiants();

     return 0;
}
