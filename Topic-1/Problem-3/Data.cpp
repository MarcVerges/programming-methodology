#include "Data.h"
#include <iostream>
using namespace std;

bool Data :: operator==( Data &a) const
{
    if ((m_any == a.m_any) && (m_mes == a.m_mes) && (m_dia == a.m_dia))
    {
        return true;
    }
    else
    {
        return false;
    }
   
}

Data Data :: operator+(int a)
{
    Data ret(m_dia,m_mes,m_any);
   
    while (a > 0)
    {
        int diaParcial = ret.m_dia + a;
        if (diaParcial > nDiesMes[ret.m_mes -1])
        {
            a -= (nDiesMes[ret.m_mes-1] - ret.m_dia + 1);
            ret.m_dia = 1;
            ret.m_mes ++;
            
            if (ret.m_mes > N_MESOS)
            {
                ret.m_any++;
                ret.m_mes = 1;
            }
        }
        else
        {
            ret.m_dia = diaParcial;
            a = 0;
        }
    }
    return ret;
}


bool Data :: operator<(const Data &a)
{
    
    //retornem true si el primer en fer la comparació (el natiu de la funció ) és el més petit
    
    bool res = false;
    
    if (m_any > a.m_any)
    {
        res = false;
    }
    if (m_any < a.m_any)
    {
        res = true;
    }
    if (m_any == a.m_any)
    {
        if (m_mes > a.m_mes)
        {
            res = false;
        }
        if (m_mes < a.m_mes)
        {
            res = true;
        }
        if (m_mes == a.m_mes)
        {
            if (m_dia > a.m_dia)
            {
                res = false;
            }
            if (m_dia < a.m_dia)
            {
                res = true;
            }
        }
    }
    return res;
}



ostream& operator<< (ostream& output, Data &a)
{
    
    output << a.getDia() << "/" << a.getMes() << "/" << a.getAny();
    
    return output;
    
}
istream& operator>> (istream& input, Data &a)
{
    float dia = 0, mes = 0, any = 0;
    
    cout << "introduiex el dia: ";
    input >> dia;
    a.setDia(dia);
    cout << "introdeuix el mes: ";
    input >> mes;
    a.setMes(mes);
    cout << "introdueix any: ";
    input >> any;
    a.setAny(any);
    
    return input;
}


