//
//  Data.h
//  Tema 1 - Sessió 10
//
//  Created by Marc Verges on 21/3/23.
//
#ifndef DATA_H
#define DATA_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Data
{
public:
    Data() { m_dia = 0; m_mes = 0; m_any = 0; }
    Data(int dia, int mes, int any) : m_dia(dia), m_mes(mes), m_any(any) { }
    void setDia(int dia) { m_dia = dia; }
    void setMes(int mes) { m_mes = mes; }
    void setAny(int any) { m_any = any; }
    int getDia() const { return m_dia; }
    int getMes() const { return m_mes; }
    int getAny() const { return m_any; }
    Data operator+(int nDies) const;
    bool operator==(const Data& data) const;
    bool operator<(const Data& data) const;
    Data& operator=(const Data& data);
private:
    int m_dia, m_mes, m_any;
    static const int N_MESOS = 12;
    const int nDiesMes[N_MESOS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
};

istream& operator>>(istream& input, Data& d);
ostream& operator<<(ostream& input, const Data& d);
ifstream& operator>>(ifstream& input, Data& d);
ofstream& operator<< (ofstream& output, const Data& d);




#endif
