#include <iostream>
using namespace std;

void intercanvia(int* p_x, int* p_y)
{
    int tmp;

    tmp = *p_x;
    *p_x = *p_y;
    *p_y = tmp;
}

void ordena(int* a, int* b, int* c)
{
    if ( *a > *b)
    {
        intercanvia(a,b);
    }
    if (*a > *c)
    {
        intercanvia(a,c);
    }
    if(*b > *c)
    {
        intercanvia(b,c);
    }
}



int main()
{
    int x, y, z;

    cin >> x >> y >> z;
    
    
    ordena(&x,&y,&z);
    
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;
    cout << "z: " << z << endl;

    return 0;
}
