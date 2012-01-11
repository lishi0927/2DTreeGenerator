/*
 * Created on January 11, 2012, 9:43 AM
 * By Laurent Victorino < laurent.victorino@gmail.com >
 */

#ifndef MOVABLEENTITY_H
#define	MOVABLEENTITY_H

#include "entity.h"

class cMovableEntity : public cEntity
{

public:

    cMovableEntity( unsigned short x, unsigned short y );
    virtual ~cMovableEntity();

    void    warp( unsigned short x , unsigned short y);
    unsigned short  getX() { return _x; }
    unsigned short  getY()  { return _y; }

    // inherited from cEntity
    virtual void    renderEntity() = 0;
    virtual bool    initEntity() = 0;

protected:

    unsigned short _x;
    unsigned short _y;

};

#endif	/* MOVABLEENTITY_H */

