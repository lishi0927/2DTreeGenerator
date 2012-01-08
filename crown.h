/* 
 * File:   crown.h
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 *
 * Created on January 8, 2012, 9:56 PM
 */

#ifndef CROWN_H
#define	CROWN_H

#include "entity.h"

class cCrown : public cEntity
{

public:
    cCrown();
    cCrown(const cCrown& orig);
    virtual ~cCrown();

    // inherited from cEntity
    virtual void renderEntity();
    virtual void initEntity();

private:

};

#endif	/* CROWN_H */

