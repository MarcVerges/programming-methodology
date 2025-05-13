//
//  Joc.h
//  Tema 2 - Exercici - Avaluable 8
//
//  Created by Marc Verges on 15/6/23.
//
#pragma once
#include "Carta.h"
#include "Jugador.h"
#include "Moviment.h"
#include <string>

using namespace std;
const int N_CARTES_JUGADOR = 7;

class Joc
{
public:
    Joc(): m_torn(-1), m_sentitTorn(1), m_nJugadors(0) {};
    ~Joc() {};

    void inicialitza(const string& nomFitxer, int nJugadors);
    void fesMoviment();
    bool final();
    void guarda(const string& nomFitxer);
private:
    vector <Jugador> m_jugadors;
    queue <Carta> m_cartesJugades;
    list <Carta> m_cartesBaralla;
    list <Moviment> m_moviments;
    int m_nJugadors;
    int m_torn;
    int m_sentitTorn;
    
    void canviTorn();
    bool agafaCarta(Carta& carta, bool guardaMoviment);
    void tiraCarta();
};


