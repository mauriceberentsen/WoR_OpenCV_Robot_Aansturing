/*
 * forward_kinematic.hpp
 *
 *  Created on: 6 mrt. 2017
 *      Author: maurice
 */

#ifndef FORWARD_KINEMATIC_HPP_
#define FORWARD_KINEMATIC_HPP_

#include <cmath>
#include <utility>
#include "Point.hpp"
#include "Matrix.hpp"

#define PI 3.14159265358979323846264

using std::sin;
using std::cos;

struct Configuration
{
  Configuration(){};
  Configuration(Point aPoint ,double aPhi0, double aPhi1, double aPhi2, double aPhi3, double aLength1,double aLength2,double aLength3)
  :currentPos(aPoint), phi0(aPhi0), phi1(aPhi1), phi2(aPhi2), phi3(aPhi3), length1(aLength1), length2(aLength2), length3(aLength3){};
  Point currentPos;
  double phi0 = 0;
  double phi1 = 0;
  double phi2 = 0;
  double phi3 = 0;

  double length1, length2, length3;

};

Matrix<4,3,double> jacobi_4dof(double phi0,double phi1,double phi2,double phi3,double phi4,double l1,double l2,double l3)
{
	/**afgeleiden**/
	double dx0 = -l1 * cos(phi1) * sin(phi0) -l2 * cos(phi1 + phi2) * sin(phi0) -l3* cos(phi1 + phi2 + phi3) * sin(phi0);
	double dx1 = -l1 * sin(phi1) * cos(phi0) -l2 * sin(phi1 + phi2) * cos(phi0) -l3* sin(phi1 + phi2 + phi3) * cos(phi0);
	double dx2 = -l2 * sin(phi1 + phi2) * cos(phi0) -l3 * sin(phi1 + phi2 + phi3) * cos(phi0);
	double dx3 = -l3 * sin(phi1 + phi2 + phi3) * cos(phi0);
	double dy0 = -l1 * cos(phi1) * cos(phi0) -l2 * cos(phi1 + phi2) * cos(phi0) -l3* cos(phi1 + phi2 + phi3) * cos(phi0);
	double dy1 = -l1 * sin(phi1) * sin(phi0) -l2 * sin(phi1 + phi2) * sin(phi0) -l3* sin(phi1 + phi2 + phi3) * sin(phi0);
	double dy2 = -l2 * sin(phi1 + phi2) * sin(phi0) -l3* sin(phi1 + phi2 + phi3) * sin(phi0);
	double dy3 = -l3* sin(phi1 + phi2 + phi3) * sin(phi0);
	double dz0 = 0;
	double dz1 = l1 * cos(phi1) + l2 * cos(phi1 + phi2) + l3 * cos(phi1 + phi2 + phi3);
	double dz2 = l2 * cos(phi1 + phi2) + l3 * cos(phi1 + phi2 + phi3);
	double dz3 = l3 * cos(phi1 + phi2 + phi3);
	//jacobi
	Matrix<4,3,double> mat = Matrix<4,3,double> ({{dx0,dx1,dx2,dx3},
												  {dy0,dy1,dy2,dy3},
												  {dz0,dz1,dz2,dz3}});
	return mat;
}


std::pair<double,double> calculate_postion(const std::pair<double,double>& startpos, double lengte1,double phi1,double lengte2, double phi2, double lengte3, double phi3)
{
  std::pair<double,double> position;

  position.first = startpos.first + (lengte1 * sin(phi1 * PI/180)) + (lengte2 * sin((phi1 + phi2)* PI/180)) + (lengte3 * sin((phi1 + phi2 + phi3)* PI/180));
  position.second = startpos.second + (lengte1 * cos(phi1 * PI/180)) + (lengte2 * cos((phi1 + phi2)* PI/180)) + (lengte3 * cos((phi1 + phi2 + phi3)* PI/180));


  return position;
}


Point calculate_postition(const Configuration& myConfig)
{
  Point currentPosition;
  currentPosition.x = myConfig.currentPos.x
		  	  	  	  	+  (myConfig.length1 * cos(myConfig.phi1 * PI/180) * cos(myConfig.phi0 * PI/180))
                        +  (myConfig.length2 * cos((myConfig.phi1 + myConfig.phi2) * PI/180)) * cos(myConfig.phi0 * PI/180)
                        +  (myConfig.length3 * cos((myConfig.phi1 + myConfig.phi2 + myConfig.phi3) * PI/180)) * cos(myConfig.phi0 * PI/180);

  currentPosition.y = myConfig.currentPos.y
		  	  	  	    +  (myConfig.length1 * sin(myConfig.phi1 * PI/180) * sin(myConfig.phi0 * PI/180))
                        +  (myConfig.length2 * sin((myConfig.phi1 + myConfig.phi2) * PI/180)) * sin(myConfig.phi0 * PI/180)
                        +  (myConfig.length3 * sin((myConfig.phi1 + myConfig.phi2 + myConfig.phi3)) * PI/180) * sin(myConfig.phi0 * PI/180);

  currentPosition.z = myConfig.currentPos.z
		                +  (myConfig.length1 * sin(myConfig.phi1 * PI/180)
                        +  (myConfig.length2 * sin((myConfig.phi1 + myConfig.phi2) * PI/180))
                        +  (myConfig.length3 * sin((myConfig.phi1 + myConfig.phi2 + myConfig.phi3) * PI/180)));
  return currentPosition;
}


inline std::ostream& operator<<(   std::ostream& os,
                  const Configuration & c)
{
  return os << "hoeken"  <<" " << ": " <<c.phi0 << ","<< c.phi1 << "," << c.phi2 << "," << c.phi3 << std::endl
		  	<< "lengtes" <<" " << ": " << c.length1 << "," << c.length2 << "," << c.length3 << std::endl;
}



#endif /* FORWARD_KINEMATIC_HPP_ */
