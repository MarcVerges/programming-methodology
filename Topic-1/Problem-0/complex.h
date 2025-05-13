#pragma once

class Complex
{
public:
    float getReal(); //TO VALIDATE TEST
    float getImg(); //TO VALIDATE TEST
    void setReal(float pReal); //TO VALIDATE TEST
    void setImg(float pImg); //TO VALIDATE TEST
    
    //IMPLEMENT CLASS CODE
    
    float m_real = 0;
    float m_img = 0;
    
    void mostra();
    Complex sumar(Complex &num2) ;
    Complex restar(Complex &num2);
    Complex multiplicacio(Complex &num2);
};

Complex avaluaOperacio(const char operacio, Complex& c1, Complex& c2);

