/*
 * main.cpp
 *
 *  Created on: 21 feb. 2017
 *      Author: maurice
 */

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include "findGoals.hpp"
#include "multipicture.h"
#include "SearchQuery.h"
#include "Configuration.h"
#include "webcam.h"

std::string pictureWindow = "Picture";
const double baseHeight = 60;
std::string input, aColour, aShape;


int main(int argc, char **argv) {

	cv::Mat picture_raw, show ,dst;
	//cv::namedWindow(pictureWindow, CV_WINDOW_AUTOSIZE);
	Configuration c;

	picture_raw = getCameraFeed(0);

	if(argc > 1)
	{
		Configuration d(argv[1], picture_raw);
		//cv::imshow(pictureWindow, picture_raw);
	}
	else
	{
		while(true){

			std::cout<< "vul eerst een kleur in daarna een figuur"<<std::endl;
			std::getline(std::cin, input);
			input = "blauw vierkant";
			picture_raw = getCameraFeed(1);
			std::stringstream  ss(input);
			Imageinfo info = getImageInfo(picture_raw);
			std::cout<<"X: "<<info.nulPunt.first << "| Y: " << info.nulPunt.second <<" Ratio:" <<info.ratioPixelToMM << std::endl;
			std::cout<<"Xcor: "<<info.correctionX << "| Ycor: " << info.correctionY  << std::endl;

			ss >> aColour >> aShape;
			std::cout << "vorm: " << aShape << " kleur:" << aColour << ": "<< std::endl;

			SearchQuery target(picture_raw, dst, colourfinder::colour(c.findColour(aColour)),shapeFinder::shape(c.findShape(aShape)));
			SearchQuery whiteCircle(picture_raw, dst, colourfinder::colour(c.findColour("wit")),shapeFinder::shape(c.findShape("cirkel")));
			goal targetParam = findGoal(target, info, baseHeight);
			goal whiteCirle = 	findGoal(whiteCircle, info, baseHeight);
			std::cout << "target:  "<< "angle:" << targetParam.angle << "x:" << targetParam.x << "y:" << targetParam.y << std::endl;
			std::cout << "goal:  " <<"angle:" << whiteCirle.angle << "x:" << whiteCirle.x << "y:" << whiteCirle.y << std::endl;

		}
	}



}

