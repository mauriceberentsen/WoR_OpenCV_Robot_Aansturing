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

int main(int argc, char **argv)
{
	ros::init(argc, argv, "kinematic_node");

	if (argc == 7)
	{
		try
		{
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
				return 1 ;
			}
			sleep(4);
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
				Matrix<2,1,double> g1({atof(argv[2]),atof(argv[3])});
				Matrix<2,1,double> g2({atof(argv[5]),atof(argv[6])});

				robotArm.executeMotionPlanning(x0,y0,beta,precision,atof(argv[1]),currentPose,g1,g2,atof(argv[4]));


//							auto schuine_zijde = std::sqrt(std::pow(20,2) + std::pow(20,2));
//							std::cout<<schuine_zijde<<std::endl;
//							auto getal = 20/schuine_zijde;
//							std::cout<<getal<<std::endl;
//							std::cout<<std::acos(getal) * 180 / PI<<std::endl;


		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	else
	{
		ROS_INFO("usage: Base_start_angle target_x target_y goal_base_angle goal_x goal_y \n\r");
		return 1;
	}
	return 0;
}



