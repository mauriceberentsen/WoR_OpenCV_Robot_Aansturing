/*
 * Kinematic.cpp
 *
 *  Created on: Apr 3, 2017
 *      Author: Agit
 */

#include "Kinematic.hpp"
#include "ros/ros.h"
#include <robot_arm_aansturing/position.h>
#include <robot_arm_aansturing/command.h>

Kinematic::Kinematic(Matrix<3,2,double> aRobotArmAngleRestrictions, Matrix<3,1,double> aRobotArmReach) :
						robotArmAngleRestrictions(aRobotArmAngleRestrictions),
						l1(aRobotArmReach.at(0).at(0)),
						l2(aRobotArmReach.at(1).at(0)),
						l3(aRobotArmReach.at(2).at(0))
{
	// TODO Auto-generated constructor stub

}

std::pair<double, double> Kinematic::forward_kinematic(double x0, double y0,double q1, double q2, double q3)
{
	double x = x0+l1*std::sin(q1 * PI / 180.0)+l2*std::sin((q1+q2) * PI / 180.0)+l3*std::sin((q1+q2+q3) * PI / 180.0);
	double y = y0+l1*std::cos(q1 * PI / 180.0)+l2*std::cos((q1+q2) * PI / 180.0)+l3*std::cos((q1+q2+q3) * PI / 180.0);

	return std::make_pair(x,y);
}

Matrix<2, 3, double> Kinematic::calculateJacobiMatrix(
		Matrix<2, 1, double> coordinates, Matrix<3, 1, double> angles)
{
	 Matrix<2,3,double> result;

	 result.at(0).at(0)  = l1 * std::cos(angles.at(0).at(0) * PI / 180.0) + l2 * std::cos((angles.at(0).at(0) + angles.at(1).at(0)) * PI / 180.0) + l3 * std::cos((angles.at(0).at(0) + angles.at(1).at(0) + angles.at(2).at(0)) * PI / 180.0);
	 result.at(0).at(1)  = l2 * std::cos((angles.at(0).at(0) + angles.at(1).at(0))* PI / 180.0) + l3 * std::cos((angles.at(0).at(0) + angles.at(1).at(0) + angles.at(2).at(0))* PI / 180.0);
	 result.at(0).at(2)  = l3 * std::cos((angles.at(0).at(0) + angles.at(1).at(0) + angles.at(2).at(0))* PI / 180.0);

	 result.at(1).at(0)  = l1 * -std::sin(angles.at(0).at(0) * PI / 180.0) + l2 * -std::sin((angles.at(0).at(0) + angles.at(1).at(0)) * PI / 180.0) + l3 * -std::sin((angles.at(0).at(0) + angles.at(1).at(0) + angles.at(2).at(0)) * PI / 180.0);
	 result.at(1).at(1)  = l2 * -std::sin((angles.at(0).at(0) + angles.at(1).at(0))* PI / 180.0) + l3 * -std::sin((angles.at(0).at(0) + angles.at(1).at(0) + angles.at(2).at(0))* PI / 180.0);
	 result.at(1).at(2)  = l3 * -std::sin((angles.at(0).at(0) + angles.at(1).at(0) + angles.at(2).at(0))* PI / 180.0);

	 return result;
}

Matrix<3, 1, double> Kinematic::inverse_kinematica(double x0, double y0,
		double beta, double precision,Matrix<3, 1, double> aCurrentPoseAngles, Matrix<2, 1, double> g)
{
	Matrix<3,1,double> currentPose (aCurrentPoseAngles);

	auto result = forward_kinematic(x0,y0,currentPose.at(0).at(0),currentPose.at(1).at(0),currentPose.at(2).at(0));

	Matrix<2,1,double> e({result.first,result.second});

	if(std::pow(g.at(0).at(0),2) + std::pow(g.at(1).at(0),2) > std::pow((l1+l2+l3),2) ) throw std::runtime_error("destination can never be reached because arm is not long enough");

	int i = 0;
	while(!e.approxEqual(g,precision)
			|| (currentPose[0][0] < robotArmAngleRestrictions[0][0] || currentPose[0][0] >  robotArmAngleRestrictions[0][1])
			|| (currentPose[1][0] < robotArmAngleRestrictions[1][0] || currentPose[1][0] >  robotArmAngleRestrictions[1][1])
			|| (currentPose[2][0] < robotArmAngleRestrictions[2][0] || currentPose[2][0] >  robotArmAngleRestrictions[2][1]))
	{

		//stap1 compute jacobi matrix
		Matrix<2,3,double> jacobiMatrix = calculateJacobiMatrix(e,currentPose); // resultaat van jacobijnse kom hier in. Jacobijn is afgeleide van forward_kinematic
		//std::cout<<jacobiMatrix<<std::endl;

		//stap2 using Moore–Penrose pseudoinverse  (A+=A*(AA*)-1)
		Matrix<3,2,double> jacobiInverse =  jacobiMatrix.transpose() * (jacobiMatrix * jacobiMatrix.transpose()).inverse();
		//std::cout<<jacobiInverse<<std::endl;

		//stap3
		Matrix<2,1,double> deltaE = (g-e) * beta;
		//std::cout<<deltaE<<std::endl;

		//stap4
		Matrix<3,1,double> deltaPose = jacobiInverse * deltaE;
		//std::cout<<deltaPose<<std::endl;

		//stap5
		currentPose = currentPose + deltaPose;

		//stap6 compute new e vector
		auto coordinates= forward_kinematic(x0,y0,currentPose.at(0).at(0),currentPose.at(1).at(0),currentPose.at(2).at(0));

		e = {coordinates.first,coordinates.second};
		++i;

	}
	std::cout << i << std::endl;
	return currentPose;
}

void Kinematic::executeMotionPlanning(double x0, double y0, double beta,
		double precision, Matrix<3, 1, double> aCurrentPoseAngles,
		Matrix<2, 1, double> g)
{
	ros::ServiceClient client;
	ros::NodeHandle n;
	client = n.serviceClient<robot_arm_aansturing::position>(
			"add_position_task");

	robot_arm_aansturing::position pos;

	auto current = forward_kinematic(x0,y0,aCurrentPoseAngles[0][0],aCurrentPoseAngles[1][0],aCurrentPoseAngles[2][0]);

	Matrix<3,1,double> foundAngles = inverse_kinematica(x0,y0,beta,precision,aCurrentPoseAngles,g);


	auto found = forward_kinematic(x0,y0,foundAngles[0][0],foundAngles[1][0],foundAngles[2][0]);

	//			Matrix<2,1,double> cur({50, -70});
	//			Matrix<2,1,double> gtest({g[0][0],g[1][0]});
	//
	//			cur= (cur+gtest) * 0.5; //middenpunt berekening;

	//3000 0 45 45 45 0 0
	//robot foundAngles laten uitvoeren
	pos.request.time = 3000;
	pos.request.angles.push_back(0); //base
	pos.request.angles.push_back(foundAngles.at(0).at(0)); //shoulder
	pos.request.angles.push_back(foundAngles.at(1).at(0)); //elbow
	pos.request.angles.push_back(foundAngles.at(2).at(0)); //wrist
	pos.request.angles.push_back(0);
	pos.request.angles.push_back(0);
	if (client.call(pos))
	{
		ROS_INFO("accepted position: %d", (long int )pos.response.accepted);
	}
	else
	{
		ROS_ERROR("Failed to call service");
		return ;
	}
	sleep(4);
	std::cout<<foundAngles<<std::endl;
	std::cout<<current.first << "|" << current.second <<std::endl;
	std::cout<<found.first << "|" << found.second <<std::endl;


	//			std::cout<<cur[0][0] << "|" << cur[1][0] <<std::endl;
	aCurrentPoseAngles = foundAngles;

	current = forward_kinematic(x0,y0,aCurrentPoseAngles[0][0],aCurrentPoseAngles[1][0],aCurrentPoseAngles[2][0]);


	std::cout<<"ik ben bij blokje "<<current.first << "|" << current.second <<std::endl;

	g = {30.0,30.0};
	aCurrentPoseAngles.at(1).at(0) = 90;
	//uitvoeren currentPose;

	pos.request.time = 3000;
	pos.request.angles.push_back(0); //base
	pos.request.angles.push_back(aCurrentPoseAngles.at(0).at(0));
	pos.request.angles.push_back(aCurrentPoseAngles.at(1).at(0));
	pos.request.angles.push_back(aCurrentPoseAngles.at(2).at(0));
	pos.request.angles.push_back(0);
	pos.request.angles.push_back(0);
	sleep(4);
	if (client.call(pos))
	{
		ROS_INFO("accepted position: %d", (long int )pos.response.accepted);
	}
	else
	{
		ROS_ERROR("Failed to call service");
		return ;
	}

	current = forward_kinematic(x0,y0,aCurrentPoseAngles[0][0],aCurrentPoseAngles[1][0],aCurrentPoseAngles[2][0]);
	foundAngles = inverse_kinematica(x0,y0,beta,precision,aCurrentPoseAngles,g);
	found = forward_kinematic(x0,y0,foundAngles[0][0],foundAngles[1][0],foundAngles[2][0]);

	pos.request.time = 3000;
	pos.request.angles.push_back(0); //base
	pos.request.angles.push_back(foundAngles.at(0).at(0));
	pos.request.angles.push_back(foundAngles.at(1).at(0));
	pos.request.angles.push_back(foundAngles.at(2).at(0));
	pos.request.angles.push_back(0);
	pos.request.angles.push_back(0);
	if (client.call(pos))
	{
		ROS_INFO("accepted position: %d", (long int )pos.response.accepted);
	}
	else
	{
		ROS_ERROR("Failed to call service");
		return ;
	}
	sleep(4);
	std::cout<<"eerst naar boven dan naar doel"<<std::endl;
	std::cout<<foundAngles<<std::endl;
	std::cout<<current.first << "|" << current.second <<std::endl;
	std::cout<<found.first << "|" << found.second <<std::endl;
}
Kinematic::~Kinematic() {
	// TODO Auto-generated destructor stub
}



