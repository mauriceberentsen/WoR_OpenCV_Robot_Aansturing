/*
 * main.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: root
 */
#include <iostream>
#include "CommandLineParser.hpp"
#include "Graph.hpp"
#include "AStar.hpp"
int main(int argc, char **argv)
{

	try
	{
		//CommandLineParser parser;
		//std::cout<<"hello_world"<<std::endl;
		//(argc > 1) ? (parser.parseFile(argv[1])) : (throw std::runtime_error("this application needs a file name as argument"));
		Graph g;

		g.addVertex(PathAlgorithm::Vertex("(1,0)",0.0,00.0,0));

		g.addVertex(PathAlgorithm::Vertex("(50,10)",50.0,-51.0,62));





		std::cout<<"hello_world2"<<std::endl;
		g.findShortestPath("(1,0)","(50,10)");





	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	return 0;
}


