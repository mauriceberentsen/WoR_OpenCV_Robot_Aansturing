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

#include "multipicture.h"
#include "SearchQuery.h"
#include "searchAruco.hpp"
#include "Configuration.h"
#include "webcam.h"

std::string pictureWindow = "Picture";

std::string input, aColour, aShape;


int main(int argc, char **argv) {

	cv::Mat picture_raw, show ,dst;
	cv::namedWindow(pictureWindow, CV_WINDOW_AUTOSIZE);
	Configuration c;

	picture_raw = getCameraFeed(0);

	if(argc > 1)
	{
		Configuration d(argv[1], picture_raw);
		cv::imshow(pictureWindow, picture_raw);
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
			SearchQuery qu(picture_raw, dst, colourfinder::colour(c.findColour(aColour)),shapeFinder::shape(c.findShape(aShape)));
			if(qu.result.size() >0)
			{
			double baseX = (info.nulPunt.first - info.correctionX) * info.ratioPixelToMM;
			double baseY = (info.nulPunt.second - info.correctionY) * info.ratioPixelToMM;

			std::cout<<"X_found: "<<baseX<< "| found_Y: " << baseY <<std::endl;

			double foundX  = (qu.result.front().x - info.correctionX) * info.ratioPixelToMM;
			double foundY = (qu.result.front().y - info.correctionY) * info.ratioPixelToMM;

			double deltaX = abs(baseX - foundX);
			double deltaY = abs(baseY - foundY);
			double delta = std::sqrt(std::pow(deltaX,2) + std::pow(deltaY,2));

			std::cout<<"Xfound: "<<foundX<< "| foundY: " << foundY  << "  |  " << delta <<std::endl;
			}

			combineScreens(dst, picture_raw,show);
			cv::imshow(pictureWindow, show);
			cv::waitKey(10);
		}
	}



}

