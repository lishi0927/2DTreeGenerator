/* 
 * File:   treenode.h
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 *
 * Created on January 11, 2012, 9:00 AM
 */

#ifndef TREENODE_H
#define	TREENODE_H

#include "movableentity.h"

class cTreeNode : public cMovableEntity
{
public:

    cTreeNode( unsigned short x = 0, unsigned short y = 0 );
    virtual ~cTreeNode();

    // inherited from cEntity
    virtual void    renderEntity();
    virtual bool    initEntity();

private:

};

#endif	/* TREENODE_H */

