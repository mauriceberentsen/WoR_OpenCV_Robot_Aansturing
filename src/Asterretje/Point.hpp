#ifndef POINT_HPP_
#define POINT_HPP_

struct Point
{
	double x = 0;
	double y = 0;
	double z = 0;

	Point(double aX , double aY, double aZ): x(aX), y(aY), z(aZ){};
};

#endif // POINT_HPP_
