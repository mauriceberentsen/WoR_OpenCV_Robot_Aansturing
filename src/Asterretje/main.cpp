/*
 * main.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: root
 */

#include <iostream>
#include "Graph.hpp"
#include "AStar.hpp"
int main(int argc, char **argv)
{

	try
	{
		Graph g;

		PathAlgorithm::Vertex start(0.0,0.0,0.0);
		PathAlgorithm::Vertex goal(50.0,-51.0,62.0);

		g.findShortestPath(start,goal);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	return 0;
}


