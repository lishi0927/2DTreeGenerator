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

// elipsis equation = ( (x - h) / a )^2 + ( (y - k) / b )^2
void    cCrown::createElipsisCrown( float a, float b, float h, float k )
{
    unsigned int i;
    for ( i = 0; i < ATTRACTPOINT_NUMBER; ++i )
    {
        float x = rand() % (int)SCREEN_W;
        float y = rand() % (int)SCREEN_H;
        
        bool isInElipsis = ((pow((x - h)/a, 2) + (pow((y - k)/b, 2))) <= 1.f);
        
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

    createElipsisCrown( a, b, h, k );
}

void    cCrown::createSphericCrown( float radius, float xSphere, float ySphere, float zSphere )
{
    cPoint3D sphere( 0.f, 0.f, 0.f );
    unsigned int i;
    for ( i = 0; i < ATTRACTPOINT_NUMBER; ++i )
    {
        float x = rand() % ((int)radius * 2) - radius;
        float y = rand() % ((int)radius * 2) - radius;
        float z = rand() % ((int)radius * 2) - radius;

        cPoint3D newPoint( x, y, z );

        bool isInSphere = distance( newPoint, sphere ) <= radius;

        if ( isInSphere == true )
        {
            cAttractionPoint*   pAttractPoint = new cAttractionPoint( x + xSphere, y + ySphere, z);
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

    createSphericCrown( 200.f, SCREEN_W / 2.f, SCREEN_H / 2.f, 0.f );    
//    createRandomElipsisCrown();
//    createElipsisCrown( 200.f,  100.f, SCREEN_W / 2.f, SCREEN_H / 2.f);
}

bool    cCrown::initEntity()
{
    return fillCrown();
}