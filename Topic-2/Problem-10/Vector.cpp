//
//  Vector.cpp
//  Tema 2 - Avaluable 2
//
//  Created by Marc Verges on 10/5/23.
//
#include"Vector.h"

Vector::Vector()
{
    m_array = nullptr;
    m_nElements = 0;
    m_maxElements = 0;
}

Vector::Vector(const Vector& v)
{
    m_array = nullptr;
    m_maxElements = v.m_maxElements;
    m_nElements = v.m_nElements;
    if (v.m_array != nullptr)
    {
        m_array = new Punt[m_maxElements];
        for (int i = 0; i < v.m_nElements; i++)
        {
            m_array[i] = v.m_array[i];
        }
    }
}

Vector& Vector::operator = ( const Vector& v)
{
    if (this != &v)
    {
        m_nElements = v.m_nElements;
        m_maxElements = v.m_maxElements;
        m_valorDefecte = v.m_valorDefecte;
        
        if (m_array != nullptr)
        {
            delete[] m_array;
        }
        if (v.m_array != nullptr)
        {
            m_array = new Punt [m_maxElements];
            
            for (int i = 0; i < m_nElements; i++)
            {
                m_array[i] = v.m_array[i];
            }
        }
        else
        {
            m_array = nullptr;
        }
    }
    return *this;
}


Vector::~Vector()
{
    if (m_array != nullptr)
    {
        delete[] m_array;
        m_array = nullptr;
    }
    m_maxElements = 0;
    m_nElements = 0;
}


bool Vector::insereix(const Punt& pt, int posicio)
{
    if ((posicio < 0) || posicio > m_nElements)
    {
        return false;
    }
    else
    {
        if (m_maxElements == 0)
        {
            m_array = new Punt[TAMANY_MINIM];
            m_nElements = 0;
            m_maxElements = TAMANY_MINIM;
        }
        
        if (m_nElements ==  m_maxElements)
        {
            Vector ret;
            ret.m_array = new Punt[m_nElements * 2];
            
            for (int i = 0 ; i < m_nElements; i ++)
            {
                ret.m_array[i] = m_array[i];
            }
            ret.m_nElements = m_nElements;
            ret.m_maxElements = m_nElements * 2;
            ret.m_valorDefecte = m_valorDefecte;
            *this = ret;
        }
        
        for (int i = m_nElements - 1; i >= posicio; i--)
        {
            m_array[i + 1] = m_array[i];
        }
        m_array[posicio] = pt;
        m_nElements ++;
        return true;
    }
}


bool Vector::elimina(int posicio)
{
    if (posicio < 0 || posicio > m_nElements - 1)
    {
        return false;
    }
  
    else
    {
        for (int i = posicio; i < m_nElements; i++)
        {
            m_array[i] = m_array[i + 1];
        }
        m_nElements --;
        
        if ((m_nElements < (m_maxElements / 4)) && (m_maxElements/2 >= 5))
        {
            Vector ret;
            ret.m_array = new Punt[m_maxElements / 2];
            
            for (int i = 0 ; i < m_nElements; i ++)
            {
                ret.m_array[i] = m_array[i];
            }
            ret.m_nElements = m_nElements;
            ret.m_maxElements = m_maxElements / 2;
            *this = ret;
        }
    }
    return true;
}


int Vector::getNElements()
{
    return m_nElements;
}

int Vector::getMaxElements()
{
    return m_maxElements;
}

Punt& Vector::operator[] (int nIndex)
{
    if (nIndex >= 0 && nIndex < m_nElements)
        return m_array[nIndex];
    else
    {
        cout << "Error d'acces a l'array" << endl;
        return m_valorDefecte;
    }
}





