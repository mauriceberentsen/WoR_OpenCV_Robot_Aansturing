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

PathAlgorithm::Vertex& Graph::findVertexbyName(std::string vertexName)
{
	auto result = std::find_if(v.begin(),v.end(),[&vertexName](const PathAlgorithm::Vertex& rhs)
			{
				return rhs.name == vertexName;
			});
	if(result==std::end(v)) throw std::runtime_error("Vertex not found with given name: " + vertexName);

	return *result;
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

void Graph::findShortestPath(std::string startVertex, std::string goalVertex)
{;
	PathAlgorithm::Vertex start = findVertexbyName(startVertex);
	PathAlgorithm::Vertex goal =  findVertexbyName(goalVertex);
	auto result = a.search(start,goal,e);

	for(auto& r : result)
	{
		std::cout<<r<<std::endl;
	}

}
