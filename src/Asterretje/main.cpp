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
//#include <opencv-3.2.0/opencv2/aruco.hpp> <--- nodig voor opencv

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

		//14.5 cm eerste arm shoulder servo to elbow sevo
		//18.7 cm tweede arm elbow servo to wrist servo
		//12   cm derde arm  wrist servo to uit einde van gripper
			Kinematic robotArm({{-30,90},{0,135},{-90,90}},{14.5,18.7,12.0});
		  	double x0 = 0.0;
			double y0 = 0.0;
			double beta = 0.1;
			double precision = 0.1;
			Matrix<3,1,double> currentPose (
											{
												{{45}},		//hoek van shoulder
												{{45}},			//hoek van elbow
												{{45}},			//hoek van wrist
											}
											);
			Matrix<2,1,double> g({20.0,20.0});

			robotArm.executeMotionPlanning(x0,y0,beta,precision,currentPose,g);


	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}



