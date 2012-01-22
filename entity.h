/* 
 * File:   entity.h
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 *
 * Created on January 8, 2012, 10:33 PM
 */

#ifndef ENTITY_H
#define	ENTITY_H

#include "GL/gl.h"

class   cEntity
{

public:

    cEntity();
    virtual ~cEntity();

    void    setVisible( bool val ) { _visible = val; }
    bool    isVisible() { return _visible; }

    void    render();
    bool    init();

    virtual void    renderEntity() = 0;
    virtual bool    initEntity() = 0;

private:

    bool    _visible;

};

#endif	/* ENTITY_H */

