/*
 * File:  movableentity.cpp
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 *
 * Created on January 11, 2012, 09:38 AM
 */

#include "movableentity.h"

cMovableEntity::cMovableEntity(float x, float y)
: cEntity()
, cPoint2D( x, y )
{
}

cMovableEntity::~cMovableEntity()
{
}

void    cMovableEntity::warp( float r, float s )
{
    set( r, s );
}
