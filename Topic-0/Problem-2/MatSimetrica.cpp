
#include "MatSimetrica.h"

bool esSimetrica(int matriu[N][N])
{
    bool simetrica = true;
    int i = 1;
    int j = 1;
    
    while ((i < N ) && (simetrica))
    {
        j = 1;
        while ((j < N ) && (simetrica))
        {
            if (matriu[i][j] != matriu[j][i])
            {
                simetrica = false;
            }
            else
            {
                j++;
            }
        }
        i++;
    }
    return simetrica;
}
