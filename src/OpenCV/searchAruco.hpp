/*
 * searchAruco.hpp
 *
 *  Created on: 4 apr. 2017
 *      Author: maurice
 */

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>

#ifndef SEARCHARUCO_HPP_
#define SEARCHARUCO_HPP_

int realSize = 42; /*mm*/

struct Imageinfo
{
		std::pair<double, double> nulPunt;
		double ratioPixelToMM;
		double correctionX;
		double correctionY;
		Imageinfo(std::pair<double, double> aNarucoPoint, double aRatio, double aCorX, double aCorY)
		:nulPunt(aNarucoPoint), ratioPixelToMM(aRatio), correctionX(aCorX), correctionY(correctionY)
		{

		}
		Imageinfo(){};

};

Imageinfo getImageInfo(cv::Mat& input)
{
	Imageinfo info;
    std::vector<int> ids;
    std::vector<std::vector<cv::Point2f> > corners;
    cv::aruco::detectMarkers(input, cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250), corners, ids);
    // if at least one marker detected
    if (ids.size() > 0 && ids.size() < 2)
    {
	    for(auto c : corners)
	    {
	    	float centX = (c.at(0).x + c.at(2).x) /2;
	    	float centY = (c.at(0).y + c.at(2).y) /2;
	    	double length = cv::norm(c.at(0) - c.at(1));
	    	cv::Point pt(centX, centY);
	    	info.nulPunt = std::pair<double,double>(centX,centY);
	    	info.ratioPixelToMM = realSize / length  ;
	    	info.correctionX =  info.nulPunt.first - 100 / info.ratioPixelToMM;
	    	info.correctionY = info.nulPunt.second;
	    }
    }
    return info;
}







#endif /* SEARCHARUCO_HPP_ */
