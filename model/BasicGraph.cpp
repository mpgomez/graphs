/*
 * BasicGraph.cpp
 *
 *  Created on: 27 Apr 2014
 *      Author: dreamer
 */

#include <stdio.h>      // printf, scanf,  NULL
#include <stdlib.h>     // rand, srand
#include <stdint.h>     // uint8_t
#include <time.h>       // time

#include "BasicGraph.hpp"
#include "graphException.hpp"

BasicGraph::BasicGraph()
{

}

BasicGraph::~BasicGraph()
{
}

const std::vector<std::list<std::pair<int, int> > >& BasicGraph::getEdgesRepresentation() const
{
    return edgesRepresentation;
}

bool BasicGraph::isIsEdgesRepresentation() const
{
    return isEdgesRepresentation;
}

bool BasicGraph::isIsMatrixRepresentation() const
{
    return isMatrixRepresentation;
}

void BasicGraph::setIsMatrixRepresentation(bool isMatrixRepresentation)
{
    this->isMatrixRepresentation = isMatrixRepresentation;
}

void BasicGraph::setIsEdgesRepresentation(bool IsEdgesRepresentation)
{
    this->isEdgesRepresentation = IsEdgesRepresentation;
}

const std::vector<std::vector<int> >& BasicGraph::getMatrixRepresentation() const
{
    return matrixRepresentation;
}

void BasicGraph::genrateRandomGraph(int numOfNodes,
                                    uint8_t density,
                                    bool withWeights,
                                    unsigned int maxWeight )
{
    int randomNumber = 0;
    int isEdge = 0;

    //Validate the input
    if( density > 100 || density == 0 )
    {
        //TODO error handling
        throw graphException( -1 );
    }
    if( withWeights && maxWeight == 0 )
    {
        //TODO error handling
        throw graphException( -1 );
    }

    /* initialize random seed: */
    srand (time(NULL));

    //Populate a zeroed matrix
    std::vector<int> zeroedVector( numOfNodes,0 );
    for ( int i = 0; i< numOfNodes; i++)
    {
        matrixRepresentation.push_back( zeroedVector );
    }

    /* we will generate a random number, and use it as
       to know if there will be an edge or not, based on the
       density
     */
    for( int i = 0; i < numOfNodes/2; i++ )
    {
        for( int j = numOfNodes/2; j < numOfNodes; i++ )
        {
            // avoiding loops
            if( i != j )
            {
                isEdge = rand() % 100;
                //If it is and edge, we add true (1) or the weight
                if( isEdge <= density )
                {
                    if( withWeights )
                    {
                        randomNumber = rand() % maxWeight;
                        //The matrix is simetric, as it is a non directed graph
                        matrixRepresentation[i][j] = randomNumber;
                        matrixRepresentation[j][i] = randomNumber;
                    }
                    else
                    {
                        matrixRepresentation[i][j] = 1;
                        matrixRepresentation[j][i] = 1;
                    }
                }
                //if it is not and edge, we should add a 0, but as the matrix
                //is initialised with zeros, we do nothing

            }
        }
    }

}

void BasicGraph::populateMatrixFromList()
{

}
void BasicGraph::populateListFromMatrix()
{

}

