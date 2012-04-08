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
    
    cAttractionPoint( float x = 0.f, float y = 0.f, float z = 0.f );
    virtual ~cAttractionPoint();

    void        setDisabled( bool v ) { _disabled = v; }
    bool        isDisabled() { return _disabled; }
    
    // inherited from cEntity
    virtual void renderEntity();
    virtual bool initEntity();

private:
    
    bool                        _disabled;
    
};

#endif	/* ATTRACTIONPOINT_H */

