/*
 * Graph.cpp
 *
 *  Created on: Mar 24, 2017
 *      Author: root
 */

#include "Graph.hpp"
#include <algorithm>
Graph::Graph() {
	// TODO Auto-generated constructor stub

}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

void Graph::addVertex(const PathAlgorithm::Vertex& aVertex)
{
	v.push_back(aVertex);
}

void Graph::addEdge(const PathAlgorithm::Edge& aEdge)
{
	e.push_back(aEdge);
}

void Graph::printEdges()
{
	std::for_each(e.begin(),e.end(),[](const PathAlgorithm::Edge& edge)
			{
				std::cout<<edge<<std::endl;
			});
}

void Graph::printVertex()
{
	std::cout<<"not implemented yet"<<std::endl;
}

void Graph::findShortestPath(const PathAlgorithm::Vertex& startVertex, const PathAlgorithm::Vertex& goalVertex)
{;

	const PathAlgorithm::Path& result = a.search(startVertex,goalVertex);

	for(const PathAlgorithm::Vertex& r : result)
	{
		std::cout<<r<<std::endl;
	}

}
