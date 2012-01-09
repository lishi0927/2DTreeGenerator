/* 
 * File:   attractionpoint.cpp
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 * 
 * Created on January 8, 2012, 9:56 PM
 */
#include <iostream>
#include <stdlib.h>
#include <GL/gl.h>

#include "macros.h"
#include "attractionpoint.h"

cAttractionPoint::cAttractionPoint()
: _x(0)
, _y(0)
{
}

cAttractionPoint::cAttractionPoint(const cAttractionPoint& orig)
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
    _x = rand() % SCREEN_W + 1;
    _y = rand() % (SCREEN_H - (SCREEN_H / 3)) + (SCREEN_H / 3);
    return true;
}