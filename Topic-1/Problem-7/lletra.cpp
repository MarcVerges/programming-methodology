//
//  lletra.cpp
//  Tema 1 - Avaluable 10 - 3.0
//
//  Created by Marc Verges on 4/4/23.
//
#include "lletra.h"

ofstream& operator<<(ofstream& output, const Lletra& lletra)
{
    char estat;
    
    if (lletra.getEstat() == NO_DEFINIDA)
    {
        estat = '_';
    }
    if (lletra.getEstat() == NO_EXISTEIX)
    {
        estat = 'N';
    }
    if (lletra.getEstat() == POSICIO_CORRECTA)
    {
        estat = 'C';
    }
    if (lletra.getEstat() == POSICIO_INCORRECTA)
    {
        estat = 'I';
    }


    
    output <<"("<< lletra.getLletra() << "," << estat << ")";
    
    return output;
}
