//
//  Llista.cpp
//  Tema 2 - Avalauble - Exercici 3
//
//  Created by Marc Verges on 13/5/23.
//
#include "Llista.h"

Llista::~Llista()
{
    while (m_primer != nullptr)
        elimina(nullptr);
}

Llista::Llista(const Llista& l)
{
    m_primer = nullptr;
    Node* aux = l.m_primer;
    Node* aux_nova = m_primer;
    while (aux != nullptr)
    {
        aux_nova = insereix(aux->getValor(), aux_nova);
        aux = aux->getNext();
    }

}

Llista& Llista::operator=(const Llista& l)
{
    
    if (this != &l)
    {
        if ( m_primer != nullptr)
        {
            delete[] m_primer;
        }
        
        if (l.m_primer != nullptr)
        {
            m_primer = l.m_primer;
        }
        else
        {
            m_primer = nullptr;
        }
    }
    return *this;
}

Node *Llista::insereix(const Punt& valor, Node *posicio)
{
    if (posicio != nullptr)
    {
        if (posicio -> getNext() != nullptr)
        {
            Node* posicioAGuardar = posicio -> getNext();
            Node *m_nou = new Node;
            m_nou -> setValor(valor);
            m_nou -> setNext(posicioAGuardar);
            posicio -> setNext(m_nou);
            return m_nou;
        }
        else
        {
            Node *m_nou = new Node;
            m_nou -> setValor(valor);
            posicio -> setNext(m_nou);
            return m_nou;
        }
       
    }
    else
    {
        Node *m_nou = new Node;
        m_nou -> setValor(valor);
        Node *seguent = m_primer;
        m_nou -> setNext(m_primer);
        m_primer = m_nou;
        return m_nou;
    }

}

Node *Llista::elimina(Node *posicio)
{
    if (posicio != nullptr)
    {
        Node *PosicioAElminar = posicio -> getNext();
        Node *PosicioAMoure = PosicioAElminar -> getNext();
        posicio -> setNext(PosicioAMoure);
        delete PosicioAElminar;
        PosicioAElminar = nullptr;
        return PosicioAMoure;
    }
    else
    {
        Node *PosicioNova = m_primer -> getNext();
        m_primer = PosicioNova;
        return m_primer;
    }

}

int Llista::getNElements() const
{
    int nElements = 0;
    Node *aux = m_primer;
    while (aux != NULL)
    {
        nElements++;
        aux = aux->getNext();
    }
    
    return nElements;
}
