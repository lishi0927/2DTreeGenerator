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

cAttractionPoint::cAttractionPoint( float x, float y, float z )
: cMovableEntity(x, y, z)
{
    std::cout << "attractionpoint: " << x << " " << y << " " << z << std::endl;
}

cAttractionPoint::~cAttractionPoint()
{
}

void    cAttractionPoint::renderEntity()
{
    if ( isDisabled() == true )
        return;
    
    glBegin(GL_LINES);
        glColor3ub( ATTRACTPOINT_GLCOLOR );
        glVertex3d( SCREEN2GL_X(x - (ATTRACTPOINT_SIZE / 2.0) ), SCREEN2GL_Y(y), SCREEN2GL_Z(z) );
        glVertex3d( SCREEN2GL_X(x + (ATTRACTPOINT_SIZE / 2.0) ), SCREEN2GL_Y(y), SCREEN2GL_Z(z) );

        glVertex3d( SCREEN2GL_X(x), SCREEN2GL_Y(y  - (ATTRACTPOINT_SIZE / 2.0) ), SCREEN2GL_Z(z) );
        glVertex3d( SCREEN2GL_X(x), SCREEN2GL_Y(y  + (ATTRACTPOINT_SIZE / 2.0) ), SCREEN2GL_Z(z) );
    glEnd();
}

bool    cAttractionPoint::initEntity()
{
    return true;
}