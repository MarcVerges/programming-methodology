#include "llista.h"



Llista ::  Llista(const Estudiant v[], int mida)
{
    m_nElements = mida;
    
    for (int i = 0; i < m_nElements; i++)
    {
        totEstudiants[i] = v[i];
    }
}


bool Llista :: pertany(const Estudiant& element) const
{
    //comporva si el element estudaint passat com a parametre esta dins de la array de tipus estudaint
    //caldrà sobrecarregar el operador == de la class estudiant
    
    int i = 0;
    bool trobat = false;
    
    while ((!trobat) && (i < m_nElements))
    {
        if (totEstudiants[i] == element)
        {
            trobat = true;
        }
        else
        {
            i++;
        }
    }
    return trobat;
}

int Llista :: cerca(const string& niu) const
{
    //busquem la posició de la persona amb el niu a la array de estudaint
    
    int i = 0;
    bool trobat = false;
    
    while ((i< m_nElements) && (!trobat))
    {
        if (totEstudiants[i].getNiu() == niu)
        {
            trobat = true;
        }
        else
        {
            i++;
        }
    }
    
    if (trobat)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

Estudiant Llista::getElement(int posicio) const    //no esta passant les notes
{
    //pasem nom i niu si la posicó es troba dins del domini posible li pasem el nom i niu vuit
    
    Estudiant ret;
    
    if((posicio > MAX_LLISTA-1 ) || (posicio < 0 ))
    {
        ret.setNom("");
        ret.setNiu("");
        
    }
    else
    {
        ret = totEstudiants[posicio];
    }
    return ret;
}

void Llista :: setElement(int posicio, const Estudiant& estudiant)
{
    //hem de escriure la class pasada com a parametre a la posico concreta
    
    if((posicio <= MAX_LLISTA-1 ) || (posicio >= 0 ))
    {
        totEstudiants[posicio] = estudiant;
    }
}

bool  Llista :: insereix(const Estudiant& element, int posicio)
{
    //inserim el element estudaint a la calsse de estudiants a la posicio que ens indican el resta de componenets es desplacen a la dreta, els valors valids son de 0 fins a m_nElements si es aquest cas es posa el estudaint i no es canvia res, si els valors no son valids o ja tenim la array plena reotrnem false
    
    if ((m_nElements == MAX_LLISTA) || (posicio < 0) || (posicio > m_nElements))
    {
        return false;
    }
    else
    {
        //diferenciem de cas de una posció nomral o el numero de elements (a la ultima no cal canviar res ja que es buida)
        
        if (posicio == m_nElements)
        {
            totEstudiants[posicio] = element;
            m_nElements++;
        }
        else
        {
            for (int i = m_nElements - 1 ; i >= posicio ; i --)
            {
                totEstudiants[i + 1] = totEstudiants[i];
                
            }
            setElement(posicio,element);
            m_nElements++;
        }
        return true;
    }
}

bool Llista:: elimina(int posicio)
{
    //eliminem el element de la posicició i avancem la array endevant
    
    if ((posicio > m_nElements-1 ) || (posicio < 0 ) || (m_nElements == 0))
    {
        return false;
    }
    else
    {
        
        if (posicio == m_nElements- 1)
        {
            Estudiant aux;
            
            totEstudiants[posicio] =aux;
            m_nElements--;
        }
        else
        {
            for (int i = posicio; i < m_nElements ; i++)
            {
                totEstudiants[i] = totEstudiants[ i + 1];
            
            }
            m_nElements--;
            
        }
        return true;
    }
}

bool Llista :: operator+(const Estudiant &element)
{
    //afegim una data al final
    
    bool espotfer = insereix(element, m_nElements);
    
    return espotfer;
}

bool Llista :: operator-(const Estudiant &element)
{
    int pos ;
    
    pos = cerca(element.getNiu());
    
    if (pos == -1)
    {
        return false;
    }
    else
    {
        elimina(pos);
        return true;
    }
}

ostream& operator<<(ostream& output, const Llista& llista)
{
    //volem imprimir cada un dels estudiant en  lineas separades de forma que diguem nom niu notamitjana
    
    for (int i = 0; i < llista.getNumElements(); i++)
    {
        output << llista.getElement(i) ;
    }
    return output;
}

ofstream& operator<<(ofstream& output, const Llista& llista)
{
    
    for (int i = 0; i < llista.getNumElements(); i++ )
    {
        output << llista.getElement(i);
    }
    
    return output;
}

ifstream& operator>>(ifstream& input, Llista& llista)
{
    Estudiant aux;
   
    input >> aux;
    
      for (int i = 0; !input.eof(); i++)
      {
          llista.insereix(aux,i);
          input >> aux;
      }

      
    return input;
}

