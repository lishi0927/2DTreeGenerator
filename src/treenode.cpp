/* 
 * File:   treenode.cpp
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 * 
 * Created on January 11, 2012, 9:00 AM
 */
#include <iostream>
#include <GL/gl.h>
#include <stdlib.h>

#include "macros.h"
#include "treegenerator.h"
#include "treenode.h"

cTreeNode::cTreeNode( int pID, float radius, float x, float y, float z ) 
: cMovableEntity( x, y, z )
, _parentID( pID )
, _radius( radius )
{
}

cTreeNode::~cTreeNode()
{
}

void    cTreeNode::renderEntity()
{
    if ( _parentID == -1 )
        return;
    cTreeNode* pParent = cTreeGenerator::getInstance()->getTreeNode( _parentID );
    glBegin(GL_LINES);
        glColor3ub( TREESEGMENT_GLCOLOR );
        glVertex2d( SCREEN2GL_X( x ), SCREEN2GL_Y( y ) );
        glVertex2d( SCREEN2GL_X( pParent->x ), SCREEN2GL_Y( pParent->y ) );
    glEnd();
}

bool    cTreeNode::initEntity()
{
}
