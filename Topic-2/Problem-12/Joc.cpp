//
//  Joc.cpp
//  Tema 2 - Exercici - Avaluable 8
//
//  Created by Marc Verges on 15/6/23.
//
#include "Joc.h"
#include <fstream>
using namespace std;

void Joc::inicialitza(const string& nomFitxer, int nJugadors)
{
    ifstream fitxer;
    fitxer.open(nomFitxer);
    if (fitxer.is_open())
    {
        int color, valor;
        fitxer >> color >> valor;
        while (!fitxer.eof())
        {
            Carta carta(color, valor);
            m_cartesBaralla.push_front(carta);
            fitxer >> color >> valor;
        }
        fitxer.close();
        for (int i = 0; i < nJugadors; i++)
        {
            Jugador jugador;
            for (int j = 0; j < N_CARTES_JUGADOR; j++)
            {
                Carta carta;
                agafaCarta(carta, false);
                jugador.afegeixCarta(carta);
            }
            m_jugadors.push_back(jugador);
            m_nJugadors++;
        }
        Carta primeraCarta;
        agafaCarta(primeraCarta, false);
        m_cartesJugades.push(primeraCarta);
        m_torn = 0;
    }
}

bool Joc::agafaCarta(Carta& carta, bool guardaMoviment)
{
    if ((m_cartesBaralla.size()!= 0) && (guardaMoviment))
    {
        std :: list<Carta> :: iterator inic = m_cartesBaralla.begin();
        carta.setColor(inic -> getColor());
        carta.setValor(inic -> getValor());
        m_cartesBaralla.pop_front();
        Moviment moviment (m_torn,ROBA_CARTA,carta);
        m_moviments.push_front(moviment);
        return true;
    }
    else
    {
        if (m_cartesBaralla.size()!= 0)
        {
            std :: list<Carta> :: iterator inic = m_cartesBaralla.begin();
            carta.setColor(inic -> getColor());
            carta.setValor(inic -> getValor());
            m_cartesBaralla.pop_front();
            return true;
        }
        else
        {
            return false;
        }
    }
}

void Joc::fesMoviment()
{
    Carta carta = m_cartesJugades.back();
    Carta cartaRobar;
    switch (carta.getValor())
    {
        case CANVI_TORN:
            m_sentitTorn = -m_sentitTorn;
            canviTorn();
            canviTorn();
            break;
        case SALTA_TORN:
            canviTorn();
            break;
        case ROBA_DOS:
            if (agafaCarta(cartaRobar, true))
            {
                m_jugadors[m_torn].afegeixCarta(cartaRobar);
                if (agafaCarta(cartaRobar, true))
                {
                    m_jugadors[m_torn].afegeixCarta(cartaRobar);
                }
            }
            break;
        }
        tiraCarta();
        canviTorn();
}

void Joc::tiraCarta()
{
    Carta ultima = m_cartesJugades.back();
    bool seguent;
    do
    {
        Carta cartaAJugar;
        seguent = m_jugadors[m_torn].tiraCarta(ultima, cartaAJugar);
        
        if (seguent)
        {
            m_cartesJugades.push(cartaAJugar);
            Moviment moviment (m_torn,TIRA_CARTA,cartaAJugar);
            m_moviments.push_front(moviment);
        }
        else
        {
            std :: list <Carta> :: iterator intera = m_cartesBaralla.begin();
            Carta cartaRobada;
            cartaRobada.setValor(intera->getValor());
            cartaRobada.setColor(intera -> getColor());
            m_cartesBaralla.pop_front();
            Moviment moviment (m_torn,ROBA_CARTA,cartaRobada);
            m_moviments.push_front(moviment);
            m_jugadors[m_torn].afegeixCarta(cartaRobada);
            
        }
    }while (!seguent);
}

bool Joc::final()
{
     if (m_jugadors[0].potTirar() == false && m_jugadors[1].potTirar() == false && m_jugadors[2].potTirar() == false && m_jugadors[4].potTirar() == false)
     {
         return true;
     }
     else
     {
         if (m_jugadors[0].getNCartes() == 0 ||m_jugadors[1].getNCartes() == 0 || m_jugadors[2].getNCartes() == 0 || m_jugadors[3].getNCartes() == 0 )
         {
             return true;
         }
         else
         {
             return false;
         }
     }
}

void Joc::guarda(const string& nomFitxer)
{
    ofstream fitxer;
    fitxer.open(nomFitxer);
    
    if (fitxer.is_open())
    {
        std :: list <Moviment> :: reverse_iterator iter;
        
        for (iter = m_moviments.rbegin(); iter != m_moviments.rend(); ++iter)
        {
            fitxer << iter -> getJugador() << " " << iter -> getAccio() << " " << iter -> getCarta().getColor() << " " << iter -> getCarta().getValor() << endl;
        }
    }
    fitxer.close();
}

void Joc::canviTorn()
{
    m_torn += m_sentitTorn;
    if (m_torn < 0)
        m_torn = m_nJugadors - 1;
    if (m_torn >= m_nJugadors)
        m_torn = 0;
}

