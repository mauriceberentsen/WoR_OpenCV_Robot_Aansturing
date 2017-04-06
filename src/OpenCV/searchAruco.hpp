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

Imageinfo getImageInfo(cv::Mat& input);







#endif /* SEARCHARUCO_HPP_ */
