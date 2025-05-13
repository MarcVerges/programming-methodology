#include "poligon.h"
#include <iostream>

using namespace std;



void llegeixPoligon(Poligon& p)
{
    cout << "introduiex el numero de cares del poligon: ";
    cin >> p.nCostats;
    
    for (int i = 0; i < p.nCostats ; i++)
    {
        cout << "introdeuix les dades del vertex: " << i+1 << endl;
        llegeixPunt(p.vertexs[i]);
    }
}

void mostraPoligon(Poligon& p)
{
    cout << "vertexs del poligon: ";
    for (int i = 0; i < p.nCostats; i++)
    {
        mostraPunt(p.vertexs[i]);
        cout << " ";
    }
    cout << endl;
}

float calculaPerimetre(Poligon &p)
{
    float perimetre = 0.0;
   
    for (int i = 0;i < p.nCostats-1; i++)
    {

        perimetre = perimetre + distanciaPunts( p.vertexs[i], p.vertexs[i+1]);
        
    }
    perimetre = perimetre + distanciaPunts(p.vertexs[p.nCostats - 1], p.vertexs[0]);
    
    return perimetre;
}

void rectangleMinim(Poligon& p, Punt& superiorEsquerra, Punt& inferiorDreta)
{
    float minY = p.vertexs[0].y;
    float maxY = p.vertexs[0].y;
    float minX = p.vertexs[0].x;
    float maxX = p.vertexs[0].x;
    
    for (int i = 0;i < p.nCostats; i++)
    {
        if (p.vertexs[i].y < minY )
        {
            minY = p.vertexs[i].y;
        }
        if (p.vertexs[i].y > maxY )
        {
            maxY = p.vertexs[i].y;
        }
        if (p.vertexs[i].x < minX )
        {
            minX = p.vertexs[i].x;
        }
        if (p.vertexs[i].x > maxX )
        {
            maxX = p.vertexs[i].x;
        }
    }
    
    superiorEsquerra.x = minX;
    superiorEsquerra.y = minY;
    inferiorDreta.x = maxX;
    inferiorDreta.y = maxY;
    
    
}
