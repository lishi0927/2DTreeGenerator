/*
 * File:  movableentity.cpp
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 *
 * Created on January 11, 2012, 09:38 AM
 */

#include "movableentity.h"

cMovableEntity::cMovableEntity(float x, float y, float z)
: cEntity()
, cPoint3D( x, y, z )
{
}

cMovableEntity::cMovableEntity( cPoint3D &point )
: cEntity()
, cPoint3D( point )
{

}

cMovableEntity::~cMovableEntity()
{
}

void	cMovableEntity::warp( cPoint3D &point )
{
	set( point.x, point.y, point.z );
}

void    cMovableEntity::warp( float r, float s, float t )
{
    set( r, s, t );
}
