/* 
 * File:   crown.h
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 *
 * Created on January 8, 2012, 9:56 PM
 */

#ifndef CROWN_H
#define	CROWN_H

#include <vector>

#include "defines.h"
#include "entity.h"
#include "attractionpoint.h"

class cCrown : public cEntity
{

public:
    
    cCrown();
    cCrown(const cCrown& orig);
    virtual ~cCrown();

    std::vector< cAttractionPoint* > getAttractionList() { return _attractPointList; }
    inline void removeAttraction( unsigned int idx ) { _attractPointList[idx]->setDisabled(true); }

    // inherited from cEntity
    virtual void renderEntity();
    virtual bool initEntity();

private:
    bool        fillCrown();
    void        createRandomElipsisCrown();
    void        createElipsisCrown( float a, float b, float h, float k);

private:

    std::vector< cAttractionPoint* > _attractPointList;

};

#endif	/* CROWN_H */

