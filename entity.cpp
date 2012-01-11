/* 
 * File:   entity.cpp
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 * 
 * Created on January 8, 2012, 10:33 PM
 */

#include "entity.h"

cEntity::cEntity()
:_visible( true )
{
}

cEntity::~cEntity()
{
}

bool    cEntity::init()
{
    return initEntity();
}

void    cEntity::render()
{
    if ( isVisible() == true )
    {
        renderEntity();
    }
}
