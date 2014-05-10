/*
 * BasicGraph.hpp
 *
 *  Created on: 27 Apr 2014
 *      Author: dreamer
 */

#ifndef BASICGRAPH_HPP_
#define BASICGRAPH_HPP_

#include <vector>
#include <list>
#include <iostream>
#include <exception>

/**
 * Class BasicGraph, generic representation of a non-directed graph
 */
class BasicGraph
{

protected:
    //If the graph has weight, the int will represent that weight.
    //If there is no weight in the edges, the int will take 0 and 1 values (as boolean would do)
    std::vector<std::vector<int> > matrixRepresentation;

    //If the graph has weight, the second int in the pair will represent that weight.
    //Otherwise, the second int won't be used
    std::vector<std::list<std::pair<int, int> > > edgesRepresentation;

    bool isMatrixRepresentation = false;
    bool isEdgesRepresentation = false;
    bool hasWeights = false;

    //Private methods
    void setIsMatrixRepresentation(bool isMatrixRepresentation);
    void setIsEdgesRepresentation(bool IsEdgesRepresentation);

public:
    BasicGraph();
    virtual ~BasicGraph();
    //TODO final in CPP?
    void populateMatrixFromList();
    //void populateListFromMatrix() throw(int);
    void populateListFromMatrix();

    virtual void genrateRandomGraph(int numOfNodes,
                                    uint8_t density,
                                    bool withWeights = false,
                                    unsigned int maxWeight = 1);

    virtual BasicGraph getShortestPath();

    //Getters and setters
    const std::vector<std::list<std::pair<int, int> > >& getEdgesRepresentation() const;
    bool isIsEdgesRepresentation() const;
    bool isIsMatrixRepresentation() const;
    const std::vector<std::vector<int> >& getMatrixRepresentation() const;

};

#endif /* BASICGRAPH_HPP_ */
