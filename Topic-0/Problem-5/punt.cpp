#include "punt.h"
#include <iostream>
#include <math.h>

using namespace std;

void llegeixPunt(Punt& p)
{
   cin >>  p.x;
   cin >>  p.y;
}

void mostraPunt(Punt & p)
{
    cout << p.x;
    cout << p.y;
}

float distanciaPunts(Punt &p1, Punt &p2)
{
    float dis1, dis2, disTot;
    
    dis1 = p1.x - p2.x;
    dis2 = p1.y - p2.y;
    
    disTot = sqrt(pow(dis1,2) + pow(dis2,2));
    
    return disTot;
    
}
