/* 
 * File:   treegenerator.cpp
 * Author: Laurent Victorino < laurent.victorino@gmail.com >
 * 
 * Created on January 8, 2012, 10:02 PM
 */

#include <assert.h>
#include <stdlib.h>
#include <iostream>
#include "treegenerator.h"
#include "mymath.h"

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
    unsigned short treeNodeX = rand() % (SCREEN_W / 3) +(SCREEN_W / 3); // only the 2nd third of the screen
    unsigned short treeNodeY = 10;
    cTreeNode*  pFirstTN = new cTreeNode( treeNodeX, treeNodeY );
    _treeNodeList.push_back( pFirstTN );

    _pCrown = new cCrown();
    assert( _pCrown != NULL );
    if ( _pCrown != NULL )
    {
        _pCrown->init();
    }
    
}

void cTreeGenerator::colonize()
{
    if ( _pCrown == NULL || _treeNodeList.empty() == true )
        return;

    if ( _pCrown->getAttractionList().size() == 0 )
        return;

    unsigned int i;
    unsigned int j;
    std::vector< cAttractionPoint* > attractList = _pCrown->getAttractionList();
    for ( i = 0; i < attractList.size(); ++i )
    {
        // todo: put vec2 in classes
        cPoint2D aPoint( attractList[i]->getX(), attractList[i]->getY() );

        int mindist = -1;
        unsigned int mindistIDX;
        for ( j = 0; j < _treeNodeList.size(); ++j )
        {
            cPoint2D tPoint( _treeNodeList[j]->getX(), _treeNodeList[j]->getY() );

            unsigned int dist = distance( aPoint, tPoint );
            if ( dist < mindist || mindist < 0 )
            {
                mindist = dist;
                mindistIDX = j;
            }
        }
        _treeNodeList[mindistIDX]->addInfluence( i );
    }

    unsigned int treeNodeSize = _treeNodeList.size();
    for ( i = 0; i < treeNodeSize; ++i )
    {
        unsigned int s = _treeNodeList[i]->getInfluenceList().size();
        if ( _treeNodeList[i]->getInfluenceList().size() > 0 )
        {
            std::vector< unsigned int > influenceList = _treeNodeList[i]->getInfluenceList();
            cPoint2D treeNode( _treeNodeList[i]->getX(), _treeNodeList[i]->getY() );
            cVector2D averageDir(0, 0);
            for ( j = 0; j < influenceList.size(); ++j )
            {
                cVector2D dir( attractList[influenceList[j]]->getX(), attractList[influenceList[j]]->getY() );
                dir = dir - treeNode;
                dir = dir.normalize();
                averageDir = averageDir + dir;
            }

            averageDir.normalize();
            averageDir = averageDir * TREENODE_LENGTH;
            averageDir = averageDir + treeNode ;

            cTreeNode *newNode = new cTreeNode( averageDir.x, averageDir.y );
            _treeNodeList.push_back(newNode);
        }
    }

    // clearing influence list  and useless attraction points for next colonize iteration
    for ( i = 0; i < _treeNodeList.size(); ++i )
    {
        _treeNodeList[i]->clearInfluence();
    }
    unsigned int  attractListSize =  _pCrown->getAttractionList().size();
    for ( i = 0; i < attractListSize; ++i)
    {
        cPoint2D attractpoint( _pCrown->getAttractionList()[i]->getX(), _pCrown->getAttractionList()[i]->getY() );
        for ( j = 0; j < _treeNodeList.size(); ++j )
        {
            cPoint2D treepoint( _treeNodeList[j]->getX(), _treeNodeList[j]->getY() );
            unsigned int dist = distance( attractpoint, treepoint );
            if ( dist <= ATTRACTPOINT_KILLDISTANCE )
            {
                _pCrown->removeAttraction( i );
                i = 0;
                attractListSize -= 1;
                break;
            }
        }
    }

}

void cTreeGenerator::renderOneFrame()
{
    colonize();
    _pCrown->render();
    unsigned int i;
    for ( i = 0; i < _treeNodeList.size(); ++i )
    {
        _treeNodeList[i]->render();
    }
}
