/*
 * main.cpp
 *
 *  Created on: Mar 17, 2017
 *      Author: root
 */

#include "Matrix.hpp"
#include <algorithm>
#include <array>
#include <cmath>
#include <utility>
#include <cmath>

//#define BOOST_TEST_MODULE MatrixTestModule
//#define BOOST_TEST_DYN_LINK
//#define BOOST_TEST_NO_MAIN
//#include <boost/test/unit_test.hpp>
//int main(int argc, char **argv)
//{
//
//	return boost::unit_test::unit_test_main( &init_unit_test, argc, argv );
//}


const double PI = std::acos(-1);

std::pair<double,double> forward_kinematic(double x0,
										   double y0,
										   double l1,
										   double q1,
										   double l2,
										   double q2,
										   double l3,
										   double q3)
{
	double x = x0+l1*std::sin(q1 * PI / 180.0)+l2*std::sin((q1+q2) * PI / 180.0)+l3*std::sin((q1+q2+q3) * PI / 180.0);
	double y = y0+l1*std::cos(q1 * PI / 180.0)+l2*std::cos((q1+q2) * PI / 180.0)+l3*std::cos((q1+q2+q3) * PI / 180.0);

	return std::make_pair(x,y);

}

/**
 * Deze functie berekent de Jacobi matrix oftewel de afgeleide van de foreward kinematics
 * Deze functie werkt alleen met 3DOF robot vandaar de hard gecodeerde matrixen
 */

Matrix<2,3,double> calculateJacobiMatrix(Matrix<2,1,double> coordinates,Matrix<3,1,double> angles,double l1, double l2, double l3)
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

/*
 * Deze functie berekent de benodige hoeken voor de opgegeven coordinaten.
 * Hiervoor is de huidige hoeken nodig.
 */
Matrix<3,1,double> inverse_kinematica(double x0, double y0,double beta, double precision,Matrix<3,1,double> armReach,Matrix<3,1,double> aCurrentPoseAngles,
						Matrix<2,1,double> g)
{
	const double l1 = armReach.at(0).at(0);
	const double l2 = armReach.at(1).at(0);
	const double l3 = armReach.at(2).at(0);

	Matrix<3,1,double> currentPose (aCurrentPoseAngles);

	auto result = forward_kinematic(x0,y0,l1,currentPose.at(0).at(0),l2,currentPose.at(1).at(0),l3,currentPose.at(2).at(0));

    Matrix<2,1,double> e({result.first,result.second});

	if(std::pow(g.at(0).at(0),2) + std::pow(g.at(1).at(0),2) > std::pow((l1+l2+l3),2) ) throw std::runtime_error("destination can never be reached because arm is not long enough");

	int i = 0;
	while(!e.approxEqual(g,precision)
			|| (currentPose[0][0] > 90 || currentPose[0][0] <-30)
			|| (currentPose[1][0] > 135 || currentPose[1][0] < 0)
			|| (currentPose[2][0] > 90 || currentPose[2][0] <-90))
	{

		//stap1 compute jacobi matrix
		Matrix<2,3,double> jacobiMatrix = calculateJacobiMatrix(e,currentPose,l1,l2,l3); // resultaat van jacobijnse kom hier in. Jacobijn is afgeleide van forward_kinematic
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
		auto coordinates= forward_kinematic(x0,y0,l1,currentPose.at(0).at(0),l2,currentPose.at(1).at(0),l3,currentPose.at(2).at(0));

		e = {coordinates.first,coordinates.second};
		++i;

	}
	std::cout << i << std::endl;
	return currentPose;
}
int main(int argc, char **argv)
{
	double x0 = 0.0;
	double y0 = 0.0;
	double beta = 0.1;
	double precision = 0.1;
	Matrix<3,1,double> currentPose ({90,135,-90});
	Matrix<2,1,double> g({100.0,100.0});
	Matrix<3,1,double> armReach({50,50,50});

	Matrix<3,1,double> foundAngles = inverse_kinematica(x0,y0,beta,precision,armReach,currentPose,g);

	auto current = forward_kinematic(0,0,armReach[0][0],90,armReach[1][0],135,armReach[2][0],-90 );
	auto found = forward_kinematic(0,0,armReach[0][0],foundAngles[0][0],armReach[1][0],foundAngles[1][0],armReach[2][0],foundAngles[2][0]);

	Matrix<2,1,double> cur({50, -70});
	Matrix<2,1,double> gtest({g[0][0],g[1][0]});

	auto deltaTest =  gtest - cur;
	deltaTest /= 2;
	cur += deltaTest;

	std::cout<<foundAngles<<std::endl;
	std::cout<<found.first << "|" << found.second <<std::endl;
	std::cout<<current.first << "|" << current.second <<std::endl;
	std::cout<<cur[0][0] << "|" << cur[1][0] <<std::endl;

	return 0;
}

