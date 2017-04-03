/*
 * main.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: root
 */

#include <iostream>
#include "Graph.hpp"
#include "AStar.hpp"
#include "Kinematic.hpp"
#include "Point.hpp"

int main(int argc, char **argv)
{

	try
	{
		//Graph g;

		//PathAlgorithm::Vertex start(0.0,0.0,0.0);
		//PathAlgorithm::Vertex goal(50.0,-51.0,62.0);

		//g.findShortestPath(start,goal);

	   // Point position;
	   // position = calculate_postition(myPos);
	   // std::cout << myPos;
	    //std::cout << position.x << "\t" << position.y << "\t" << position.z << "\t" << std::endl;

			Kinematic robotArm({{-30,90},{0,135},{-90,90}},{50,50,50});
		  	double x0 = 0.0;
			double y0 = 0.0;
			double beta = 0.1;
			double precision = 0.1;
			Matrix<3,1,double> currentPose (
											{
												{{90}},			//hoek van base
												{{135}},			//hoek van shoulder
												{{-90}},			//hoek van elbow
											}
											);
			Matrix<2,1,double> g({100.0,100.0});

			Matrix<3,1,double> foundAngles = robotArm.inverse_kinematica(x0,y0,beta,precision,currentPose,g);

			auto current = robotArm.forward_kinematic(0,0,currentPose[0][0],currentPose[1][0],currentPose[2][0] );
			auto found = robotArm.forward_kinematic(0,0,foundAngles[0][0],foundAngles[1][0],foundAngles[2][0]);

			Matrix<2,1,double> cur({50, -70});
			Matrix<2,1,double> gtest({g[0][0],g[1][0]});

			cur= (cur+gtest) * 0.5; //middenpunt berekening;

			std::cout<<foundAngles<<std::endl;
			std::cout<<found.first << "|" << found.second <<std::endl;
			std::cout<<current.first << "|" << current.second <<std::endl;
			std::cout<<cur[0][0] << "|" << cur[1][0] <<std::endl;

	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}



