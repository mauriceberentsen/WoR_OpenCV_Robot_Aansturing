/*
 * main.cpp
 *
 *  Created on: Mar 23, 2017
 *      Author: Agit
 */

#include <iostream>
#include "Kinematic.hpp"
#include <ros/ros.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "kinematic_node");

	if (argc == 7)
	{
		try
		{

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
													{{atof(argv[2])}},			//hoek van shoulder
													{{atof(argv[3])}},			//hoek van elbow
													{{atof(argv[4])}}			//hoek van wrist
												}
												);
				Matrix<2,1,double> g({atof(argv[5]),atof(argv[6])});

				robotArm.executeMotionPlanning(x0,y0,beta,precision,currentPose,g);


				//			auto schuine_zijde = std::sqrt(std::pow(20,2) + std::pow(20,2));
				//			std::cout<<schuine_zijde<<std::endl;
				//			auto getal = 20/schuine_zijde;
				//			std::cout<<getal<<std::endl;
				//			std::cout<<std::acos(getal) * 180 / PI<<std::endl;


		}
		catch (std::exception& e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	else
	{
		ROS_INFO("usage: Base_angle shoulder_angle elbow_angle wrist_angle target_x target_y \n\r");
		return 1;
	}
	return 0;
}



