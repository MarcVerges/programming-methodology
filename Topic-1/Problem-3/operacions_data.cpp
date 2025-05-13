#include "operacions_data.h"


bool comprovaTermini()
{
    //data incial
    //data data actual
    // ndies
    // dataactual < o == de data inical + ndies
    // retorn true en cas de < o ==
    
    //variables
    Data dataInicial, dataActual;
    int nDies;
    
    //incialitzem las funcions
    cin >> dataInicial;
    cin >> dataActual;
    cin >> nDies;
    
    //sumem a la data inicial
    Data dataSumada = dataInicial + nDies;
    
    //comporvem si són igual
    if (dataActual == dataSumada)
    {
        return true;
    }
    else
    {
        if (dataSumada < dataActual )
        {
            return false;
        }
        else
        {
            return true;
        }
    }
}
