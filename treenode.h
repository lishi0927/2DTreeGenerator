/* 
 * File:   treenode.h
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 *
 * Created on January 11, 2012, 9:00 AM
 */

#ifndef TREENODE_H
#define	TREENODE_H

#include <vector>

#include "movableentity.h"
#include "attractionpoint.h"

class cTreeNode : public cMovableEntity
{
public:

    cTreeNode( unsigned short x = 0, unsigned short y = 0 );
    virtual ~cTreeNode();

    const std::vector< unsigned int >&    getInfluenceList() { return _influenceList; }
    void    addInfluence( unsigned int influence ) { _influenceList.push_back( influence ); }
    void    clearInfluence() { _influenceList.clear(); }


    // inherited from cEntity
    virtual void    renderEntity();
    virtual bool    initEntity();

private:

    std::vector< unsigned int >    _influenceList;

};

#endif	/* TREENODE_H */
