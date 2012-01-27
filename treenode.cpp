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
#include "treenode.h"

cTreeNode::cTreeNode( int pID, float x, float y ) 
: cMovableEntity( x, y )
, _parentID( pID )
{
}

cTreeNode::~cTreeNode()
{
}

void    cTreeNode::renderEntity()
{
    glBegin(GL_LINES);
        glColor3ub( TREENODE_GLCOLOR );
        glVertex2d( SCREEN2GL_X(x - (TREENODE_SIZE / 2.0) ), SCREEN2GL_Y(y +(TREENODE_SIZE / 2.0) ) );
        glVertex2d( SCREEN2GL_X(x + (TREENODE_SIZE / 2.0) ), SCREEN2GL_Y(y -(TREENODE_SIZE / 2.0)) );
        glVertex2d( SCREEN2GL_X(x + (TREENODE_SIZE / 2.0) ), SCREEN2GL_Y(y +(TREENODE_SIZE / 2.0) ) );
        glVertex2d( SCREEN2GL_X(x - (TREENODE_SIZE / 2.0) ), SCREEN2GL_Y(y -(TREENODE_SIZE / 2.0)) );
    glEnd();
}

bool    cTreeNode::initEntity()
{
}


