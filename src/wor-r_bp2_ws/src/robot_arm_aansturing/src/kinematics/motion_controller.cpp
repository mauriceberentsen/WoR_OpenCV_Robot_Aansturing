/*
 * main.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: Agit
 */

#include <iostream>
#include "Kinematic.hpp"
#include <ros/ros.h>
#include <robot_arm_aansturing/position.h>
#include <robot_arm_aansturing/command.h>

static void execute_motion(int argc, char** argv ,double baseStartAngle,double targetX ,double targetY,double goalBaseAngle,double goalX, double goalY)
{
	std::cout<<"in functie"<<std::endl;
	//int argc;
	//char** argv;
	ros::init(argc,argv,"kinematic_node");
	std::cout<<"voor de try"<<std::endl;
		try
		{
			std::cout<<"ben in de try"<<std::endl;
			//3000 90 -27 83 89 0 0
			ros::ServiceClient client;
			ros::NodeHandle n;
			client = n.serviceClient<robot_arm_aansturing::position>(
					"add_position_task");
			// ga naar start positie
			robot_arm_aansturing::position pos;
			pos.request.time = 3000;
			pos.request.angles.push_back(90); //base
			pos.request.angles.push_back(-27);
			pos.request.angles.push_back(83);
			pos.request.angles.push_back(89);
			pos.request.angles.push_back(1);
			pos.request.angles.push_back(0);

			if (client.call(pos))
			{
				ROS_INFO("accepted position: %d", (long int )pos.response.accepted);
			}
			else
			{
				ROS_ERROR("Failed to call service");
				return  ;
			}
			//sleep(4);
			//14.5 cm eerste arm shoulder servo to elbow sevo
			//18.7 cm tweede arm elbow servo to wrist servo
			//12   cm derde arm  wrist servo to uit einde van gripper
				Kinematic robotArm({{-30,90},{0,135},{-90,90}},{14.5,18.7,12.0});
				double x0 = 0.0;
				double y0 = 0.0; //rekening houden met de hoogte van de base misschien?? 6.7 cm
				double beta = 0.1;
				double precision = 0.1;

				//Reminder Stand van de hoeken heeft wel effect op of doel haalbaar is
				Matrix<3,1,double> currentPose (
												{
													{{-27}},			//hoek van shoulder
													{{83}},			//hoek van elbow
													{{89}}			//hoek van wrist
												}
												);
				Matrix<2,1,double> g1({targetX,targetY});
				Matrix<2,1,double> g2({goalX,goalY});

				robotArm.executeMotionPlanning(x0,y0,beta,precision,baseStartAngle,currentPose,g1,g2,goalBaseAngle);

				ros::ServiceClient client2;
				ros::NodeHandle n2;
				client2 = n2.serviceClient<robot_arm_aansturing::position>(
						"add_position_task");
				// ga naar start positie
				robot_arm_aansturing::position pos2;
				pos2.request.time = 3000;
				pos2.request.angles.push_back(90); //base
				pos2.request.angles.push_back(-27);
				pos2.request.angles.push_back(83);
				pos2.request.angles.push_back(89);
				pos2.request.angles.push_back(1);
				pos2.request.angles.push_back(0);


				if (client2.call(pos2))
				{
					ROS_INFO("accepted position: %d", (long int )pos2.response.accepted);
				}
				else
				{
					ROS_ERROR("Failed to call service");
					return  ;
				}

		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout<<"klaar met functie"<<std::endl;
}



