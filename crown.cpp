/* 
 * File:   crown.cpp
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 * 
 * Created on January 8, 2012, 9:56 PM
 */
#include <iostream>
#include <stdlib.h>

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

bool    cCrown::initEntity()
{
    unsigned int i;
    for ( i = 0; i < ATTRACTPOINT_NUMBER; ++i )
    {
        unsigned short x = rand() % SCREEN_W + 1;
        unsigned short y = rand() % (SCREEN_H - (SCREEN_H / 3)) + (SCREEN_H / 3);
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
    return true;
}