/*
 * Created on January 11, 2012, 9:43 AM
 * By Laurent Victorino < laurent.victorino@gmail.com >
 */

#ifndef MOVABLEENTITY_H
#define	MOVABLEENTITY_H

#include "mymath.h"
#include "entity.h"

class cMovableEntity : public cEntity, public cPoint2D
{

public:

    cMovableEntity( float x, float y );
    virtual ~cMovableEntity();

    void    warp( float x , float y);

    // inherited from cEntity
    virtual void    renderEntity() = 0;
    virtual bool    initEntity() = 0;

};

#endif	/* MOVABLEENTITY_H */

