#ifndef JOC_H
#define JOC_H

const int MAX_JUGADORS = 4;
const int N_CARTES_JUGADOR = 7;
const int MAX_MOVIMENTS = 40;
const int MAX_CARTES = 40;

const int VERMELL = 0;
const int VERD = 1;
const int BLAU = 2;
const int GROC = 3;

typedef enum
{
    TIRA_CARTA = 0,
    ROBA_CARTA,
    PASSA_TORN
} TipusMoviment;


typedef struct
{
    int valor;
    int color;
}Carta;


typedef struct
{
    Carta cartes[MAX_CARTES];
    int nCartes;
    bool haPogutTirar;
}Jugador;

typedef struct
{
    Jugador jugadors[MAX_JUGADORS];
    int jugadorActual;
    int nJugadors;
    Carta certesBaralla[MAX_CARTES];
    int nCartaActualBaralla;
    Carta cartaActual;
    
}Partida;

void jugaPartida(int cartesInicials[MAX_CARTES][2], int nJugadors, int moviments[MAX_MOVIMENTS][4], int& nMoviments);

#endif
