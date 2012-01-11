/* 
 * File:   attractionpoint.cpp
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 * 
 * Created on January 8, 2012, 9:56 PM
 */
#include <iostream>
#include <GL/gl.h>

#include "macros.h"
#include "attractionpoint.h"

cAttractionPoint::cAttractionPoint( unsigned short x, unsigned short y ): cMovableEntity(x, y)
{
}

cAttractionPoint::~cAttractionPoint()
{
}

void    cAttractionPoint::renderEntity()
{
    glBegin(GL_LINES);
        glColor3ub( ATTRACTPOINT_GLCOLOR );
        glVertex2d( SCREEN2GL_X(_x - (ATTRACTPOINT_SIZE / 2.0) ), SCREEN2GL_Y(_y) );
        glVertex2d( SCREEN2GL_X(_x + (ATTRACTPOINT_SIZE / 2.0) ), SCREEN2GL_Y(_y) );

        glVertex2d( SCREEN2GL_X(_x), SCREEN2GL_Y(_y  - (ATTRACTPOINT_SIZE / 2.0) ) );
        glVertex2d( SCREEN2GL_X(_x), SCREEN2GL_Y(_y  + (ATTRACTPOINT_SIZE / 2.0) ) );
    glEnd();
}

bool    cAttractionPoint::initEntity()
{
    return true;
}