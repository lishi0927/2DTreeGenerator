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

cTreeGenerator::cTreeGenerator() 
:_pCrown( NULL )
, _treeNodeLen( TREENODE_LENGTH )
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
    float treeNodeX = rand() % (SCREEN_W / 3) + (SCREEN_W / 3); // only the 2nd third of the screen
    float treeNodeY = 10.f;
    cTreeNode*  pFirstTN = new cTreeNode( -1, TREENODE_LENGTH, treeNodeX, treeNodeY ); // -1 to declare the first treeNode
    _treeNodeList.push_back( pFirstTN );

    _pCrown = new cCrown();
    assert( _pCrown != NULL );
    if ( _pCrown != NULL )
    {
        _pCrown->init();
    }
    
    while ( colonize() == true ) ;
}

bool cTreeGenerator::colonize()
{
    if ( _pCrown == NULL || _treeNodeList.empty() == true )
        return false;

    if ( _pCrown->getAttractionList().size() == 0 )
        return false;

    unsigned int i;
    unsigned int j;
    bool flag = false;
    std::vector< cAttractionPoint* > attractList = _pCrown->getAttractionList();
    for ( i = 0; i < attractList.size(); ++i )
    {
        if ( attractList[i]->isDisabled() == false )
        {
            flag = true;
            // todo: put vec2 in classes
            cPoint2D aPoint( attractList[i]->x, attractList[i]->y );

            int mindist = -1;
            unsigned int mindistIDX;
            for ( j = 0; j < _treeNodeList.size(); ++j )
            {
                float dist = distance( *_treeNodeList[j], *attractList[i] );
                if ( dist < mindist || mindist < 0 )
                {
                    mindist = dist;
                    mindistIDX = j;
                }
            }
            if ( mindist > 0 )
            {
                    _treeNodeList[mindistIDX]->addInfluence( i );
            }
        }
    }

    if ( flag == false )
    {
        return false;
    }
    
    unsigned int treeNodeSize = _treeNodeList.size();
    for ( i = 0; i < treeNodeSize; ++i )
    {
        if ( _treeNodeList[i]->getInfluenceList().size() > 0 )
        {
            std::vector< unsigned int > influenceList = _treeNodeList[i]->getInfluenceList();
            cPoint2D treeNode( _treeNodeList[i]->x, _treeNodeList[i]->y );
            cVector2D averageDir(0, 0);
            for ( j = 0; j < influenceList.size(); ++j )
            {
                cVector2D dir( attractList[influenceList[j]]->x, attractList[influenceList[j]]->y );
                dir = dir - treeNode;
                dir = dir.normalize();
                averageDir = averageDir + dir;
            }

            averageDir.normalize();
            averageDir = averageDir * ( _treeNodeList[i]->getRadius() );
            averageDir = averageDir + treeNode ;
            
            float newX = averageDir.x;
            float newY = averageDir.y;
            
            bool flag = true;
            for ( j = 0; j < treeNodeSize; ++j )
            {
                if ( _treeNodeList[j]->x == newX && _treeNodeList[j]->y == newY )
                {
                    flag = false;
                    break;
                }
            }
            if ( flag == true )
            {
                float treeNodeLen = _treeNodeList[i]->getRadius() - ( _treeNodeList[i]->getRadius() / TREENODE_LENGTH );
//                float treeNodeLen = _treeNodeLen  - ( _treeNodeLen / 100 );
               treeNodeLen = treeNodeLen < 0.f ? 0.f : treeNodeLen; //TODO: make it stop on minimal radius
                //_treeNodeLen = treeNodeLen;
                cTreeNode *newNode = new cTreeNode( i, treeNodeLen, averageDir.x, averageDir.y );
                _treeNodeList.push_back(newNode);
            }
            else
            {
                for ( j = 0; j < influenceList.size(); ++j )
                {
                    if ( _pCrown->getAttractionList()[ influenceList[j] ]->isDisabled() == false )
                    {
                            _pCrown->removeAttraction( influenceList[j] );
                    }
                }
            }
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
        if ( _pCrown->getAttractionList()[i]->isDisabled() == false )
        {
            cPoint2D attractpoint( _pCrown->getAttractionList()[i]->x, _pCrown->getAttractionList()[i]->y );
            for ( j = 0; j < _treeNodeList.size(); ++j )
            {
                cPoint2D treepoint( _treeNodeList[j]->x, _treeNodeList[j]->y );
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
    return true;

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
