#ifndef POINT_HPP_
#define POINT_HPP_

struct Point
{
	Point(){};
	Point(double aX , double aY, double aZ): x(aX), y(aY), z(aZ){};
	double x = 0;
	double y = 0;
	double z = 0;


};

#endif // POINT_HPP_
