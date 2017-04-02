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
										   double a,
										   double q1,
										   double b,
										   double q2,
										   double c,
										   double q3)
{
	double x = x0+a*std::sin(q1 * PI / 180.0)+b*std::sin((q1+q2) * PI / 180.0)+c*std::sin((q1+q2+q3) * PI / 180.0);
	double y = y0+a*std::cos(q1 * PI / 180.0)+b*std::cos((q1+q2) * PI / 180.0)+c*std::cos((q1+q2+q3) * PI / 180.0);

	return std::make_pair(x,y);

}

const double l1 = 2;
const double l2 = 4;
const double l3 = 2;
/**
 * Deze functie berekent de Jacobi matrix oftewel de afgeleide van de foreward kinematics
 * Deze functie werkt alleen met 3DOF robot vandaar de hard gecodeerde values
 */

Matrix<2,3,double> calculateJacobiMatrix(Matrix<1,2,double> coordinates,Matrix<1,3,double> angles)
{
	 Matrix<2,3,double> result;

  	 result.at(0).at(0)  = l1 * std::cos(angles[0][0] * PI / 180.0) + l2 * std::cos((angles[0][0] + angles[0][1]) * PI / 180.0) + l3 * std::cos((angles[0][0] + angles[0][1] + angles[0][2]) * PI / 180.0);
  	 result.at(0).at(1)  = l2 * std::cos((angles[0][0] + angles[0][1])* PI / 180.0) + l3 * std::cos((angles[0][0] + angles[0][1] + angles[0][2])* PI / 180.0);
  	 result.at(0).at(2)  = l3 * std::cos((angles[0][0] + angles[0][1] + angles[0][2])* PI / 180.0);

  	 result.at(1).at(0)  = l1 * -std::sin(angles[0][0] * PI / 180.0) + l2 * -std::sin((angles[0][0] + angles[0][1]) * PI / 180.0) + l3 * -std::sin((angles[0][0] + angles[0][1] + angles[0][2]) * PI / 180.0);
  	 result.at(1).at(1)  = l2 * -std::sin((angles[0][0] + angles[0][1])* PI / 180.0) + l3 * -std::sin((angles[0][0] + angles[0][1] + angles[0][2])* PI / 180.0);
  	 result.at(1).at(2)  = l3 * -std::sin((angles[0][0] + angles[0][1] + angles[0][2])* PI / 180.0);

  	 return result;
}
int main(int argc, char **argv)
{
	double x0 = 0.0;
	double y0 = 0.0;
	double beta = 1;
	double precision = 0.1;
	Matrix<1,3,double> currentPose ({45,45,45});

	auto result = forward_kinematic(x0,y0,l1,currentPose[0][0],l2,currentPose[0][1],l3,currentPose[0][2]);

    Matrix<1,2,double> e({result.first,result.second});
	Matrix<1,2,double> g({10,10});

	std::cout<<e<<std::endl;
	std::cout<<g<<std::endl;


	//while(!e.approxEqual(g,precision))
	//{
		//stap1 compute jacobi matrix

		Matrix<2,3,double> jacobiMatrix = calculateJacobiMatrix(e,currentPose); // resultaat van jacobijnse kom hier in. Jacobijn is afgeleide van forward_kinematic
		//std::cout<<jacobiMatrix<<std::endl;

		//stap2
		Matrix<2,2,double> squaredJacobiMatrix = jacobiMatrix * jacobiMatrix.transpose();
		//std::cout<<squaredJacobiMatrix<<std::endl;

		Matrix<2,2,double> jacobiInverse = squaredJacobiMatrix.inverse();
		//std::cout<<jacobiInverse<<std::endl;

		//stap3
		Matrix<1,2,double> deltaE = (g-e) * beta;
		//std::cout<<deltaE<<std::endl;

		//stap4
		Matrix<2,1,double> deltaPose = jacobiInverse * deltaE.transpose();
		//std::cout<<deltaPose<<std::endl;

		//stap5
		auto newPose = currentPose + deltaPose;

		//currentPose = newPose;

		//stap6 compute new e vector
		//auto result = forward_kinematic(x0,y0,l1,currentPose[0][0],l2,currentPose[0][1],l3,currentPose[0][2]);


	//}
		return 0;
}




