/* 
 * File:   crown.cpp
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 * 
 * Created on January 8, 2012, 9:56 PM
 */
#include <iostream>
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
}

void    cCrown::renderEntity()
{
    unsigned int i;
    for ( i = 0; i < _attractPointList.size(); ++i )
    {
        _attractPointList[i]->render();
    }
}

bool    cCrown::initEntity()
{
    unsigned int i;
    for ( i = 0; i < ATTRACTPOINT_NUMBER; ++i )
    {
        // TODO: randomise attractpoints in a specific crownshape
        cAttractionPoint* pAttractPoint = new cAttractionPoint();
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