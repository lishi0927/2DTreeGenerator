/* 
 * File:   treegenerator.cpp
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 * 
 * Created on January 8, 2012, 10:02 PM
 */

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
}

void cTreeGenerator::renderOneFrame()
{
    _pCrown->render();
}
