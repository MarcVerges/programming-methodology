//
//  Navegador.cpp
//  Tema 2 - Sessió 19 - 2
//
//  Created by Marc Verges on 24/5/23.
//
#include "Navegador.h"

void Navegador::anarEnrere()
{
    if (!m_paginesVisitades.empty())
    {
        string ret = m_paginesVisitades.top();
        m_paginesVisitades.pop();
        m_paginesEndevant.push(m_paginaActual);
        m_paginaActual = ret;
    }
   
}

void Navegador::anarEndavant()
{
    if (!m_paginesEndevant.empty())
    {
        m_paginesVisitades.push(m_paginaActual);
        string ret = m_paginesEndevant.top();
        m_paginesEndevant.pop();
        m_paginaActual = ret;
    }
}

void Navegador::visitarNovaPagina(const string &url)
{
    m_paginesVisitades.push(m_paginaActual);
    
    while (!m_paginesEndevant.empty())
    {
        m_paginesEndevant.pop();
    }
   
    m_paginaActual = url;
}
