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

bool    cCrown::fillCrown()
{
    unsigned int i;
    for ( i = 0; i < ATTRACTPOINT_NUMBER; ++i )
    {
        float x = rand() % (SCREEN_W) + 1;
        float y = rand() % (SCREEN_H * 2 / 3) + SCREEN_H / 3;


        float h = SCREEN_W / 2;
        float k = ((SCREEN_H * 2 / 3) / 2) + SCREEN_H / 3;
        float a = SCREEN_W;
        a = a/2;
        double b = (SCREEN_H / 3) * 2;
        b = b/2;

        bool isInElipsis = ((pow((x - h) / a, 2) + (pow((y - k)/b, 2)) ) <= 1);

        if ( isInElipsis == true )
        {

            cAttractionPoint*   pAttractPoint = new cAttractionPoint( x, y );
            if ( pAttractPoint->init() == true )
            {
                _attractPointList.push_back( pAttractPoint );
            }
            else
            {
                return false;
            }
        }
        else
        {
            i = i - 1; // if not contained in elipsis then re-compute another point.
        }
    }
    return true;
}

bool    cCrown::initEntity()
{
    return fillCrown();
}