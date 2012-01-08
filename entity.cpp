/* 
 * File:   entity.cpp
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 * 
 * Created on January 8, 2012, 10:33 PM
 */

#include "entity.h"

cEntity::cEntity() :
_visible( true )
{
}

cEntity::cEntity(const cEntity& orig)
{
}

cEntity::~cEntity()
{
}

void    cEntity::render()
{
    if ( isVisible() == true )
    {
        renderEntity();
    }
}
