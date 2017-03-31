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

	PathAlgorithm::Vertex& findVertexbyName(std::string vertexName);

	void printEdges();

	void printVertex();

	void findShortestPath(std::string startVertex, std::string goalVertex);

	//std::vector<PathAlgorithm::Edge> getEdgeRelationByVertexName(std::string startVertex, std::string goalVertex);

private:
	std::vector<PathAlgorithm::Vertex> v;
	std::vector<PathAlgorithm::Edge> e;
	PathAlgorithm::AStar a;
};

#endif /* GRAPH_HPP_ */
