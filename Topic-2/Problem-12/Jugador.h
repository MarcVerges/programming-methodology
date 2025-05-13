//
//  Jugador.h
//  Tema 2 - Exercici - Avaluable 8
//
//  Created by Marc Verges on 15/6/23.
//
#pragma once

#include "Carta.h"
using namespace std;

class Jugador
{
public:
    Jugador(): m_haPogutTirar(true) {}
    ~Jugador() {}

    void afegeixCarta(const Carta& carta);
    bool tiraCarta(const Carta& cartaTirada, Carta& cartaATirar);
    int getNCartes() const { return m_cartes.size(); }
    bool potTirar() const { return m_haPogutTirar; }
private:
    list <Carta> m_cartes;
    bool m_haPogutTirar;
};
