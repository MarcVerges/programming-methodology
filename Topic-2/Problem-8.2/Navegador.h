//
//  Navegador.h
//  Tema 2 - Sessió 19 - 2
//
//  Created by Marc Verges on 24/5/23.
//
#pragma once

#include <stack>
#include <string>
using namespace std;

class Navegador
{
private:
    stack<string> m_paginesVisitades;
    stack<string> m_paginesEndevant;
    string m_paginaActual;
public:
    Navegador() { m_paginaActual = "Pagina Inicial"; }
    void anarEnrere();
    void anarEndavant();
    void visitarNovaPagina(const string &url);
    const string& getPaginaActual() const { return m_paginaActual; }
};
