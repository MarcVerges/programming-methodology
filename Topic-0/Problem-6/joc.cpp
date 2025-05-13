#include "joc.h"
#include <fstream>
using namespace std;

//funcions:

//funció 1:

void inicialitza(Partida& joc, int cartesInicials[MAX_CARTES][2], int nJugadors)
{
    for (int i = 0; i< MAX_CARTES; i++)
    {
        joc.certesBaralla[i].color = cartesInicials[i][0];
        joc.certesBaralla[i].valor = cartesInicials[i][1];
    }
    
    //repartim cartes:
    
    for (int i = 0; i < nJugadors; i++)
    {
        for (int j = 0; j < 7 ; j++)
        {
            joc.jugadors[i].cartes[j].color = cartesInicials[j + 7 * i][0];
            joc.jugadors[i].cartes[j].valor = cartesInicials[j + 7 * i][1];
        }
        
        joc.jugadors[i].nCartes = 7;
    }
    
    //inicialització de variables
    
    joc.jugadorActual = 0;
    joc.nJugadors = nJugadors;
    joc.nCartaActualBaralla = (7 * nJugadors + 1 );
    joc.cartaActual.color = cartesInicials[7 * nJugadors][0];
    joc.cartaActual.valor = cartesInicials[7* nJugadors][1];
    joc.jugadors[0].haPogutTirar = true;
    joc.jugadors[1].haPogutTirar = true;
    joc.jugadors[2].haPogutTirar = true;
    joc.jugadors[3].haPogutTirar = true;
    
}



//funció 2:
bool final(Partida& joc)
{
    //comporvem si algun jugador s'ha quedat sense cartes:
    
    int i = 0;
    bool senseCartes = false;
    
    while ((i < joc.nJugadors) && (!senseCartes))
    {
        if (joc.jugadors[i].nCartes == 0)
        {
            senseCartes = true;
        }
        else
        {
            i++;
        }
    }
    
    //comporvem si cap jugador ha pigut tirar carta a el ultim torn
    
    int cont = 0;
    
    for (int j = 0; j < joc.nJugadors; j++)
    {
        if (joc.jugadors[j].haPogutTirar == false)
        {
            cont ++;
        }
    }
    
    if ((cont == joc.nJugadors) || (senseCartes == true ))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//funció 3:

void eliminarCarta (Jugador& jugador, Carta cartaATirar)
{
    //funcio que elimina una carta concreta de la array de cartes.
    //trobem las posicio de la nova carta
    
    int j = 0;
    bool trobada = false;
    
    while ((j < jugador.nCartes) && (!trobada))
    {
        if ((jugador.cartes[j].color == cartaATirar.color) && (jugador.cartes[j].valor == cartaATirar.valor))
        {
            trobada = true;
        }
        else
        {
            j++;
        }
    }
    
    for (int i = j; i < jugador.nCartes - 1; i++)
    {
        jugador.cartes[i] = jugador.cartes[i + 1];
    }
}



//funció 4:
bool seleccionaCartaJugador(Jugador& jugador, Carta& cartaActual,Carta& cartaATirar)
{
    //compovem si te el color
    
    int i = 0;
    bool teColor = false;
    
    while ((i <= jugador.nCartes) && (!teColor))
    {
        if (cartaActual.color == jugador.cartes[i].color)
        {
            teColor = true;
            cartaATirar = jugador.cartes[i];
            jugador.haPogutTirar = true;
        }
        else
        {
            i++;
        }
    }
    //si te color comprovem que sigui el numero més gran
    
    if (teColor)
    {
        for (int i = 0; i < jugador.nCartes;i++)
        {
            if ((cartaATirar.valor < jugador.cartes[i].valor) && (jugador.cartes[i].color  == cartaATirar.color))
            {
                cartaATirar = jugador.cartes[i];
            }
        }
    }
    else
    {
        //comprovem si te el numero
        
        int w = 0;
        bool teNum = false;
        
        while ((w < jugador.nCartes) && (!teNum))
        {
            if (jugador.cartes[w].valor == cartaActual.valor)
            {
                cartaATirar = jugador.cartes[w];
                jugador.haPogutTirar = true;
                teNum = true;
            }
            else
            {
                w++;
            }
        }
        //comprovem que sigui el numero mes alt
        
        if (teNum == true)
        {
            for (int i = 0; i < jugador.nCartes; i++)
            {
                if ((cartaATirar.valor == jugador.cartes[i].valor ) && ((cartaATirar.color < jugador.cartes[i].color ) || (jugador.cartes[i].color == 0)))
                {
                    cartaATirar = jugador.cartes[i];
                }
            }
        }
        else
        {
            jugador.haPogutTirar = false;
        }
    }
    
    if (jugador.haPogutTirar)
    {
        eliminarCarta(jugador, cartaATirar);
        jugador.nCartes --;
        return true;
    }
    else
    {
        return false;
    }
}



//funcio 5:

bool agafaCarta(Partida& joc)
{
    bool haPogut;
    
    if (joc.nCartaActualBaralla != MAX_CARTES)
    {
        haPogut = true;
        joc.jugadors[joc.jugadorActual].nCartes ++;
        joc.jugadors[joc.jugadorActual].cartes[joc.jugadors[joc.jugadorActual].nCartes] = joc.certesBaralla[joc.nCartaActualBaralla];
        joc.nCartaActualBaralla ++;
    }
    else
    {
        haPogut = false;
    }
    
    return haPogut;
}

//funció 6
//afegeix el moviment a la array de moviments

void afegeixMoviment (int moviments[MAX_MOVIMENTS][4], int &nMoviments, int nJugador , int queFa ,Carta cartaAPosar )
{
    
    moviments[nMoviments][0] = nJugador;
    moviments[nMoviments][1] = queFa;
    moviments[nMoviments][2] = cartaAPosar.color;
    moviments[nMoviments][3] = cartaAPosar.valor;
    nMoviments ++;
    
}

//funció 7:

void tiraCarta(Partida& joc, int moviments[MAX_MOVIMENTS][4], int& nMoviments)
{
    bool potRobar = true;
    bool potTirar = false;
    Carta cartaATirar;
    do
    {
        potTirar = seleccionaCartaJugador(joc.jugadors[joc.jugadorActual],
        joc.cartaActual, cartaATirar);
        if (!potTirar)
        {
            
        afegeixMoviment(moviments, nMoviments, joc.jugadorActual, ROBA_CARTA,
        joc.certesBaralla[joc.nCartaActualBaralla]);
        potRobar = agafaCarta(joc);
    
        }
    } while ((!potTirar) && (potRobar));
    
    if (potTirar)
    {
        joc.cartaActual = cartaATirar;
        afegeixMoviment(moviments, nMoviments, joc.jugadorActual, TIRA_CARTA,
        cartaATirar);
    }
    else
    {
        afegeixMoviment(moviments, nMoviments, joc.jugadorActual, TIRA_CARTA,
        {-1, -1});
    }
}


void jugaPartida(int cartesInicials[MAX_CARTES][2], int nJugadors,int moviments[MAX_MOVIMENTS][4], int& nMoviments)
{
    Partida joc;
    nMoviments = 0;
    inicialitza(joc, cartesInicials, nJugadors);
    
    while (!final(joc))
    {
        tiraCarta(joc, moviments, nMoviments);
        joc.jugadorActual = (joc.jugadorActual + 1) % nJugadors;
    }
}
