/* 
 * File:   treegenerator.cpp
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 * 
 * Created on January 8, 2012, 10:02 PM
 */

#include <assert.h>
#include <stdlib.h>
#include "treegenerator.h"

cTreeGenerator::cTreeGenerator() :
_pCrown( NULL )
{
}

cTreeGenerator::~cTreeGenerator()
{
    if ( _pCrown != NULL )
    {
        delete _pCrown;
        _pCrown = NULL;
    }
}

void cTreeGenerator::init()
{
    _pCrown = new cCrown();
    assert( _pCrown != NULL );
    if ( _pCrown != NULL )
    {
        _pCrown->init();
    }

    unsigned short treeNodeX = rand() % (SCREEN_W / 3) +(SCREEN_W / 3); // only the 2nd third of the screen
    unsigned short treeNodeY = 10;
    cTreeNode*  pFirstTN = new cTreeNode( treeNodeX, treeNodeY );
    _treeNodeList.push_back( pFirstTN );
}

void cTreeGenerator::renderOneFrame()
{
    _pCrown->render();
    unsigned int i;
    for ( i = 0; i < _treeNodeList.size(); ++i )
    {
        _treeNodeList[i]->render();
    }
}
