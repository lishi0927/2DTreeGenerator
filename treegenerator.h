/* 
 * File:   treegenerator.h
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 *
 * Created on January 8, 2012, 10:02 PM
 */

#ifndef TREEGENERATOR_H
#define	TREEGENERATOR_H

#include <vector>

#include "defines.h"

#include "singleton.h"
#include "crown.h"
#include "treenode.h"

class cTreeGenerator : public cSingleton< cTreeGenerator >
{

    friend class cSingleton< cTreeGenerator >;

public:

    void    init();
    void    renderOneFrame();
    bool    colonize();
    cTreeNode*  getTreeNode(int id) { return _treeNodeList[id]; }
    
private:

    // private for singleton
    cTreeGenerator();
    ~cTreeGenerator();

    bool        defineAttractions();
    bool        computeNextPoint();
    bool        clearInfluence();
    
private:

    cCrown*                                     _pCrown;
    std::vector< cTreeNode* >          _treeNodeList;
};

#endif	/* TREEGENERATOR_H */
