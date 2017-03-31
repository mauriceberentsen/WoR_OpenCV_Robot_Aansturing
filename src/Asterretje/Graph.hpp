/*
 * Graph.hpp
 *
 *  Created on: Mar 24, 2017
 *      Author: root
 */

#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include "AStar.hpp"
#include <vector>

class Graph
{
public:
	Graph();
	virtual ~Graph();

	void addVertex(const PathAlgorithm::Vertex& aVertex);

	void addEdge(const PathAlgorithm::Edge& aEdge);

	void printEdges();

	void printVertex();

	void findShortestPath(const PathAlgorithm::Vertex& startVertex,const PathAlgorithm::Vertex& goalVertex);


private:
	std::vector<PathAlgorithm::Vertex> v;
	std::vector<PathAlgorithm::Edge> e;
	PathAlgorithm::AStar a;
};

#endif /* GRAPH_HPP_ */
