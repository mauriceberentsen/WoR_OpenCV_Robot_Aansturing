/*
 * Kinematica.cpp
 *
 *  Created on: Apr 3, 2017
 *      Author: Agit
 */

#include "Kinematic.hpp"

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

Kinematic::~Kinematic() {
	// TODO Auto-generated destructor stub
}



