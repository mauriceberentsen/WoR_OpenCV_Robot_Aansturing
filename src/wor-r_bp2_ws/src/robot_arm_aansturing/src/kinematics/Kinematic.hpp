/*
 * Kinematica.cpp
 *
 *  Created on: Apr 3, 2017
 *      Author: Agit
 */
#ifndef FORWARD_KINEMATIC_HPP_
#define FORWARD_KINEMATIC_HPP_

#include <cmath>
#include <utility>
#include "Matrix.hpp"

const double PI = std::acos(-1);

class Kinematic
{
public:
	/*
	 * Deze kinematica klasse werkt alleen met 3DOF
	 * De constructer wilt een matrix met hoek restricties van elk arm lengte. Van elke arm moet de eerst de min value en dan max value gedefineert worden.
	 * Zie de onderstaande constructor voor hoe de default waarde zijn ingestelt voor 3DOF
	 * Ook moet er een matrix gegeven worden met de 3 arm lengtes
	 */
	Kinematic(Matrix<3,2,double> aRobotArmAngleRestrictions = {{-30,90},{0,135},{-90,90}} ,Matrix<3,1,double> aRobotArmReach = {4,4,4});

	std::pair<double,double> forward_kinematic(double x0,
											   double y0,
											   double q1,
											   double q2,
											   double q3);

	/*
	 * Deze functie berekent de benodige hoeken voor de opgegeven coordinaten.
	 * Hiervoor is de huidige hoeken nodig.
	 */
	Matrix<3,1,double> inverse_kinematica(double x0, double y0,double beta, double precision,Matrix<3,1,double> aCurrentPoseAngles,Matrix<2,1,double> g);


	void executeMotionPlanning(double x0, double y0,double beta, double precision,double startAngleBase,Matrix<3,1,double> aCurrentPoseAngles,Matrix<2,1,double> g1,Matrix<2,1,double> g2,double endAngleBase);

	virtual ~Kinematic();

private:
	Matrix<3,2,double> robotArmAngleRestrictions;
	double l1,l2,l3;
	/**
	 * Deze functie berekent de Jacobi matrix oftewel de afgeleide van de foreward kinematics
	 * Deze functie werkt alleen met 3DOF robot vandaar de hard gecodeerde matrixen
	 */
	Matrix<2,3,double> calculateJacobiMatrix(Matrix<2,1,double> coordinates,Matrix<3,1,double> angles);

};

#endif /* FORWARD_KINEMATIC_HPP_ */
