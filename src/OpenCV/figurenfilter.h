/*
 * figurenfilter.hpp
 *
 *  Created on: 7 mrt. 2017
 *      Author: maurice
 */
#pragma once
#ifndef FIGURENFILTER_HPP_
#define FIGURENFILTER_HPP_


#include <iomanip>
#include <stdlib.h>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

namespace shapeFinder
{

struct shapeInfo{
		shapeInfo();
		shapeInfo(double aX, double aY):x(aX),y(aY){}
		double x;
		double y;
		std::pair<double, double> getPair(){
			std::pair<double, double> p0int(x,y);
			return p0int;
		};
};

enum shape{CIRCLE, SEMI_CIRCLE, SQUARE, RECTANGLE, TRIANGLE};
std::vector<shapeFinder::shapeInfo> findShapes(cv::Mat& input, cv::Mat& output, cv::Mat& Mask, shape aShape);
void setLabel(cv::Mat& im, const std::string label, std::vector<cv::Point>& contour);
void addToShapes(std::vector<cv::Point>& contour,  std::vector<shapeFinder::shapeInfo>& vec );
static double angle(cv::Point pt1, cv::Point pt2, cv::Point pt0);
cv::Mat erosionKernel(int a_size, int erosion_elem);
void printFigureInfo(std::vector<cv::Point>& contour);
}

#endif /* FIGURENFILTER_HPP_ */
