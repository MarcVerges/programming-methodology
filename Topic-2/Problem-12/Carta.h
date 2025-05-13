//
//  Carta.h
//  Tema 2 - Exercici - Avaluable 8
//
//  Created by Marc Verges on 15/6/23.
//
#pragma once
#include <list>
#include <stack>
#include <queue>
#include <vector>


const int VERMELL = 0;
const int VERD = 1;
const int BLAU = 2;
const int GROC = 3;

const int CANVI_TORN = 10;
const int ROBA_DOS = 11;
const int SALTA_TORN = 12;

class Carta
{
public:
    Carta() : m_valor(-1), m_color(-1) { }
    Carta(int color, int valor): m_valor(valor), m_color(color) { }
    ~Carta() {};

    int getValor() const { return m_valor; }
    int getColor() const { return m_color; };
    void setValor(int valor) { m_valor = valor; }
    void setColor(int color) { m_color = color; }
private:
    int m_valor;
    int m_color;
};


