#include "complex.h"
#include <iostream>
using namespace std;


void Complex::setReal(float pReal) //TO VALIDATE TEST
{
    m_real=pReal;
}

void Complex::setImg(float pImg) //TO VALIDATE TEST
{
    m_img=pImg;
}

float Complex::getReal() //TO VALIDATE TEST
{
    return m_real;
}

float Complex::getImg() //TO VALIDATE TEST
{
    return m_img;
}

void Complex :: mostra()
{
    cout << m_real << "+" << m_img <<"i";
}

Complex Complex:: sumar(Complex &c2)
{
    Complex res;
    res.m_real = m_real + c2.m_real;
    res.m_img = m_img + c2.m_img;
    return res;
}
Complex Complex:: restar(Complex &c2)
{
    Complex res;
    res.m_real = m_real - c2.m_real;
    res.m_img = m_img - c2.m_img;
    return res;
}
Complex Complex:: multiplicacio(Complex &c2)
{
    Complex res;
    res.m_real = (m_real * c2.m_real) -  (m_img * c2.m_img);
    res.m_img = (m_real * c2.m_img) + (m_img *c2.m_real);
    return res;
}


Complex avaluaOperacio(const char operacio, Complex& c1, Complex& c2)
{
    //IMPLEMENT CODE
    
    Complex res;
    
    switch (operacio)
    {
        case '1':
        {
            res = c1.sumar(c2);
            break;
        }
        case '2':
            {
                res= c1.restar(c2);
                break;
            }
        case '3':
            {
                res= c1.multiplicacio(c2);
                break;
            }
        default:
        {
            break;
        }
            
    }

    return res;

};
