/*
 * File:  movableentity.cpp
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 *
 * Created on January 11, 2012, 09:38 AM
 */

#include "movableentity.h"

cMovableEntity::cMovableEntity(unsigned short x, unsigned short y)
{
    warp( x, y );
}
cMovableEntity::~cMovableEntity()
{
}

void    cMovableEntity::warp( unsigned short x, unsigned short y )
{
    _x = x;
    _y = y;
}
