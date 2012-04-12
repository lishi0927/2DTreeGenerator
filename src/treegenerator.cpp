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
    // set up the first tree node
    float treeNodeX = rand() % (SCREEN_W / 3) + (SCREEN_W / 3); // only the 2nd third of the screen width is used
    float treeNodeY = 10.f; // fixed Y position
    cTreeNode*  pFirstTN = new cTreeNode( -1, TREENODE_LENGTH, treeNodeX, treeNodeY ); // -1 to declare the first treeNode
    _treeNodeList.push_back( pFirstTN );

    // create and init the crown
    _pCrown = new cCrown();
    assert( _pCrown != NULL );
    if ( _pCrown != NULL )
    {
        _pCrown->init();
    }
    
    // compute the whole tree before rendering loop
    while ( colonize() == true ) ;
}

bool cTreeGenerator::defineAttractions()
{
    unsigned int i;
    unsigned int j;
    bool flag = false;

    std::vector< cAttractionPoint* > attractList = _pCrown->getAttractionList();
    for ( i = 0; i < attractList.size(); ++i )
    {
        if ( attractList[i]->isDisabled() == false )
        {
            flag = true;

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

    // if no attraction point is available let's kill the optimize loop
    return flag;    
}

bool cTreeGenerator::computeNextPoint()
{
    unsigned int i;
    unsigned int j;
    
    std::vector< cAttractionPoint* > attractList = _pCrown->getAttractionList();
    unsigned int treeNodeSize = _treeNodeList.size();
    for ( i = 0; i < treeNodeSize; ++i )
    {
        if ( _treeNodeList[i]->getInfluenceList().size() > 0 )
        {
            std::vector< unsigned int > influenceList = _treeNodeList[i]->getInfluenceList();
            cPoint3D treeNode(  _treeNodeList[i]->x, 
                                _treeNodeList[i]->y, 
                                _treeNodeList[i]->z );
            cVector3D averageDir(0.f, 0.f, 0.f);
            for ( j = 0; j < influenceList.size(); ++j )
            {
                cVector3D dir(  attractList[influenceList[j]]->x, 
                                attractList[influenceList[j]]->y,
                                attractList[influenceList[j]]->z ); // todo: stock influenceList[j] somewhere
                dir = dir - treeNode;
                dir = dir.normalize();
                averageDir = averageDir + dir;
            }

            averageDir.normalize();
            averageDir = averageDir * ( _treeNodeList[i]->getRadius() );
            averageDir = averageDir + treeNode ;
            
            bool flag = true;
            // we have to be sure that we're not creating the same point again and again
            for ( j = 0; j < treeNodeSize; ++j )
            {
                if ( *_treeNodeList[j] == averageDir ) 
                {
                    flag = false;
                    break;
                }
            }
            
            if ( flag == true ) // if we have to create a new tree node
            {
               float treeNodeLen =  TREENODE_LENGTH; // TODO: length has to change to simulate smaller branches
               cTreeNode *newNode = new cTreeNode( i, treeNodeLen, averageDir.x, averageDir.y, averageDir.z );
               _treeNodeList.push_back(newNode);
            }
            else // if we're trying to create a tree node on an existing tree node
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
    return true;
}

bool cTreeGenerator::clearInfluence()
{
    
    unsigned int i;
    unsigned int j;
    
    // clears influence list  and useless attraction points for each treenode in order to prepare next colonize iteration
    for ( i = 0; i < _treeNodeList.size(); ++i )
    {
        _treeNodeList[i]->clearInfluence();
    }
    
    // disables every attraction point with treenode in its KILLDISTANCE
    unsigned int  attractListSize =  _pCrown->getAttractionList().size();
    for ( i = 0; i < attractListSize; ++i)
    {
        if ( _pCrown->getAttractionList()[i]->isDisabled() == false )
        {
            cPoint3D attractpoint( _pCrown->getAttractionList()[i]->x, _pCrown->getAttractionList()[i]->y, _pCrown->getAttractionList()[i]->z );
            for ( j = 0; j < _treeNodeList.size(); ++j )
            {
                cPoint3D treepoint( _treeNodeList[j]->x, _treeNodeList[j]->y, _treeNodeList[j]->z );
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

/*
 * How it works:
 * - checks the closest tree node for each attraction point
 * - computes an average vector based on every attraction point attached to each tree node
 * - disables every attraction point with a tree node in its KILLDISTANCE
 */
bool cTreeGenerator::colonize()
{
    if ( _pCrown == NULL || _treeNodeList.empty() == true )
        return false;

    if ( _pCrown->getAttractionList().size() == 0 )
        return false;
    
    return defineAttractions() && computeNextPoint() && clearInfluence();
    
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
