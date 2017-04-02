/*
 * main.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: root
 */

#include <iostream>
#include "Graph.hpp"
#include "AStar.hpp"
#include "kinematic.hpp"
#include "Point.hpp"

Configuration myPos(Point(0,0,0),45,45,0,0,2,2,2);
int main(int argc, char **argv)
{

	try
	{
		Graph g;

		PathAlgorithm::Vertex start(0.0,0.0,0.0);
		PathAlgorithm::Vertex goal(50.0,-51.0,62.0);

		//g.findShortestPath(start,goal);

	    Point position;
	    position = calculate_postition(myPos);
	    std::cout << myPos;
	    std::cout << position.x << "\t" << position.y << "\t" << position.z << "\t" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	return 0;
}


