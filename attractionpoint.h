/* 
 * File:   attractionpoint.h
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 *
 * Created on January 8, 2012, 9:56 PM
 */

#ifndef ATTRACTIONPOINT_H
#define	ATTRACTIONPOINT_H

#include "movableentity.h"

class cAttractionPoint : public cMovableEntity
{

public:
    
    cAttractionPoint( unsigned short x = 0, unsigned short y = 0 );
    virtual ~cAttractionPoint();

    // inherited from cEntity
    virtual void renderEntity();
    virtual bool initEntity();

private:
    
};

#endif	/* ATTRACTIONPOINT_H */

