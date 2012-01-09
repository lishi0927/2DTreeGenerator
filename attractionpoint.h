/* 
 * File:   attractionpoint.h
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 *
 * Created on January 8, 2012, 9:56 PM
 */

#ifndef ATTRACTIONPOINT_H
#define	ATTRACTIONPOINT_H

#include "entity.h"

class cAttractionPoint : public cEntity
{

public:
    
    cAttractionPoint();
    cAttractionPoint(const cAttractionPoint& orig);
    virtual ~cAttractionPoint();

    unsigned short  getX() { return _x; }
    unsigned short  getY()  { return _y; }

    // inherited from cEntity
    virtual void renderEntity();
    virtual bool initEntity();

private:

    unsigned short  _x;
    unsigned short  _y;

};

#endif	/* ATTRACTIONPOINT_H */

