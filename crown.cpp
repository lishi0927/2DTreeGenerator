/* 
 * File:   crown.cpp
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 * 
 * Created on January 8, 2012, 9:56 PM
 */
#include <iostream>
#include <stdlib.h>
#include <math.h>

#include "crown.h"

cCrown::cCrown()
{
    _attractPointList.clear();
}

cCrown::cCrown(const cCrown& orig)
{
}

cCrown::~cCrown()
{
    unsigned int i;
    for ( i = 0; i < _attractPointList.size(); ++i )
    {
        delete _attractPointList[i];
    }
    _attractPointList.clear();
}

void    cCrown::renderEntity()
{
    unsigned int i;
    for ( i = 0; i < _attractPointList.size(); ++i )
    {
        if (  _attractPointList[i] != NULL )
        {
            _attractPointList[i]->render();
        }
    }
}

void    cCrown::createRandomElipsisCrown()
{
    float minw = 50.f;
    float minh = 25.f;
    float maxw = 300.f;
    float maxh = 150.f;
    
    float a = rand() % (int)(maxw - minw) + minw; // elipsis width
    float b = rand() % (int)(maxh - minh) + minh; // elipsis height
    
    float h = rand() % (int)(SCREEN_W) + 1.f; // elipsis center x position
    float k = rand() % (int)(SCREEN_H / 3)*2 + SCREEN_H / 3; // elipsis center y position
    
    // elipsis equation = ( (x - h) / a )^2 + ( (y - k) / b )^2
    
    unsigned int i;
    for ( i = 0; i < 50; ++i )
    {
        float x = rand() % (int)a + ( h - a / 2 );
        float y = rand() % (int)k + ( k - b / 2 );

        bool isInElipsis = ((pow((x - h)/a, 2) + (pow((y - k)/b, 2))) <= 1);
        
        if ( isInElipsis == true )
        {
            cAttractionPoint*   pAttractPoint = new cAttractionPoint( x, y );
            if ( pAttractPoint->init() == true )
            {
                _attractPointList.push_back( pAttractPoint );
            }
        }
        else
        {
            i = i - 1; // if not contained in elipsis then re-compute another point.
        }
    }
}

bool    cCrown::fillCrown()
{
    unsigned short i;
    
    for ( i = 0; i < 10; ++i )
    {
        createRandomElipsisCrown();
    }
}

bool    cCrown::initEntity()
{
    return fillCrown();
}