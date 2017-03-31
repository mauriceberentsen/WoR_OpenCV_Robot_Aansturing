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

		g.addVertex(PathAlgorithm::Vertex("(0,0)",0,0));
		g.addVertex(PathAlgorithm::Vertex("(1,3)",1,3));
		g.addVertex(PathAlgorithm::Vertex("(1,9)",1,9));
		g.addVertex(PathAlgorithm::Vertex("(2,8)",2,8));

		g.addVertex(PathAlgorithm::Vertex("(4,8)",4,8));
		g.addVertex(PathAlgorithm::Vertex("(4,10)",4,10));
		g.addVertex(PathAlgorithm::Vertex("(6,9)",6,9));
		g.addVertex(PathAlgorithm::Vertex("(10,10)",10,10));

		g.addVertex(PathAlgorithm::Vertex("(3,0)",3,0));

		g.addVertex(PathAlgorithm::Vertex("(3,2)",3,2));
		g.addVertex(PathAlgorithm::Vertex("(4,5)",4,5));
		g.addVertex(PathAlgorithm::Vertex("(6,3)",6,3));
		g.addVertex(PathAlgorithm::Vertex("(6,1)",6,1));

		g.addVertex(PathAlgorithm::Vertex("(5,7)",5,7));
		g.addVertex(PathAlgorithm::Vertex("(7,5)",7,5));
		g.addVertex(PathAlgorithm::Vertex("(8,9)",8,9));


		g.addVertex(PathAlgorithm::Vertex("(8,1)",8,1));
		g.addVertex(PathAlgorithm::Vertex("(9,4)",9,4));
		g.addVertex(PathAlgorithm::Vertex("(10,7)",10,7));
		g.addVertex(PathAlgorithm::Vertex("(9,6)",9,6));


		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(0,0)"),g.findVertexbyName("(1,3)")));

		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(1,3)"),g.findVertexbyName("(1,9)")));
		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(1,9)"),g.findVertexbyName("(2,8)")));
		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(1,3)"),g.findVertexbyName("(2,8)")));
		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(2,8)"),g.findVertexbyName("(4,8)")));

		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(4,8)"),g.findVertexbyName("(4,10)")));
		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(4,8)"),g.findVertexbyName("(6,9)")));
		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(6,9)"),g.findVertexbyName("(10,10)")));


		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(0,0)"),g.findVertexbyName("(3,2)")));
		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(0,0)"),g.findVertexbyName("(3,0)")));

		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(3,2)"),g.findVertexbyName("(4,5)")));
		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(3,2)"),g.findVertexbyName("(6,3)")));
		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(3,2)"),g.findVertexbyName("(6,1)")));
		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(3,0)"),g.findVertexbyName("(6,1)")));



		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(4,5)"),g.findVertexbyName("(5,7)")));
		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(4,5)"),g.findVertexbyName("(4,8)")));
		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(5,7)"),g.findVertexbyName("(8,9)")));

		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(4,5)"),g.findVertexbyName("(7,5)")));
		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(6,3)"),g.findVertexbyName("(7,5)")));

		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(6,1)"),g.findVertexbyName("(8,1)")));
		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(6,3)"),g.findVertexbyName("(8,1)")));

		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(8,1)"),g.findVertexbyName("(9,4)")));

		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(6,3)"),g.findVertexbyName("(9,4)")));

		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(9,4)"),g.findVertexbyName("(9,6)")));

		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(9,4)"),g.findVertexbyName("(10,7)")));

		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(7,5)"),g.findVertexbyName("(10,7)")));

		g.addEdge(PathAlgorithm::Edge(g.findVertexbyName("(10,7)"),g.findVertexbyName("(10,10)")));


		std::cout<<"hello_world1"<<std::endl;
		g.findShortestPath("(0,0)","(10,10)");



	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}


	return 0;
}


