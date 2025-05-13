//
//  Jugador.cpp
//  Tema 2 - Exercici - Avaluable 8
//
//  Created by Marc Verges on 15/6/23.
//
#include "Jugador.h"

void Jugador::afegeixCarta(const Carta& carta)
{
    m_cartes.push_front(carta);

}

bool Jugador::tiraCarta(const Carta& cartaTirada, Carta& cartaATirar)
{
    std :: list <Carta> :: iterator inici = m_cartes.begin();
    bool m_teCarta = false;
    
    while ((inici != m_cartes.end()) && !m_teCarta)
    {
        if (inici ->getColor() == cartaTirada.getColor() || inici ->getValor() == cartaTirada.getValor())
        {
            m_teCarta = true;
        }
        else
        {
            inici++;
        }
    }
    
    if (!m_teCarta)
    {
        return false;
    }
    else
    {
        std :: list <Carta> :: iterator inici = m_cartes.begin();
        Carta m_millorCarta;
        m_millorCarta.setColor(14);
        m_millorCarta.setValor(14);
        bool cartaEspecial = false;
        
        for (inici = m_cartes.begin(); inici != m_cartes.end(); inici ++)
        {
            if (inici -> getValor() == 11 && inici->getColor() == cartaTirada.getColor())
            {
                m_millorCarta.setValor(inici->getValor());
                m_millorCarta.setColor(inici->getColor());
                cartaEspecial = true;
            }
            else
            {
                if (inici -> getValor() == 10 && inici->getColor() == cartaTirada.getColor() && m_millorCarta.getValor() != 11)
                {
                    m_millorCarta.setValor(inici->getValor());
                    m_millorCarta.setColor(inici->getColor());
                    cartaEspecial = true;
                }
                else
                {
                    if (inici -> getValor() == 12 && inici->getColor() == cartaTirada.getColor() && m_millorCarta.getValor() != 11 && m_millorCarta.getValor() != 10)
                    {
                        m_millorCarta.setValor(inici->getValor());
                        m_millorCarta.setColor(inici->getColor());
                        cartaEspecial = true;
                    }
                }
            }
        }
        
        if (cartaEspecial)
        {
            cartaATirar = m_millorCarta;
            std :: list<Carta> :: iterator inic = m_cartes.begin();
            bool esta = false;
           
            while ((inic != m_cartes.end() && !esta))
            {
                if (inic ->getColor() == m_millorCarta.getColor() && inic -> getValor() == m_millorCarta.getValor())
                {
                    esta = true;
                    m_cartes.erase(inic);
                }
                inic ++;
            }
            return true;
        }
        else
        {
            bool tenimColorIgual = false;
            
            for (inici = m_cartes.begin(); inici != m_cartes.end(); inici++)
            {
                if (inici ->getColor() == cartaTirada.getColor())
                {
                    tenimColorIgual = true;
                    
                    if (m_millorCarta.getColor() == cartaTirada.getColor() && inici->getValor() < m_millorCarta.getValor())
                    {
                        m_millorCarta.setColor(inici->getColor());
                        m_millorCarta.setValor(inici->getValor());
                    }
                    else
                    {
                        if (m_millorCarta.getColor() != cartaTirada.getColor())
                        {
                            m_millorCarta.setColor(inici->getColor());
                            m_millorCarta.setValor(inici->getValor());
                        }
                    }
                }
                if (inici->getColor() != cartaTirada.getColor() && !tenimColorIgual && inici->getValor() == cartaTirada.getValor())
                {
                    if (inici -> getColor() < m_millorCarta.getColor())
                    {
                        m_millorCarta.setColor(inici->getColor());
                        m_millorCarta.setValor(inici->getValor());
                    }
                    if (m_millorCarta.getColor() == inici ->getColor() && inici->getValor() < m_millorCarta.getValor())
                    {
                        m_millorCarta.setColor(inici->getColor());
                        m_millorCarta.setValor(inici->getValor());
                    }
                }
            }
        }
        
        if (m_millorCarta.getColor() != 14)
        {
            cartaATirar = m_millorCarta;
            std :: list<Carta> :: iterator inic = m_cartes.begin();
            bool esta = false;
           
            while ((inic != m_cartes.end() && !esta))
            {
                if (inic ->getColor() == m_millorCarta.getColor() && inic -> getValor() == m_millorCarta.getValor())
                {
                    esta = true;
                    m_cartes.erase(inic);
                }
                inic ++;
            }
            return true;
        }
        else
        {
            return false;
        }
    }
}
