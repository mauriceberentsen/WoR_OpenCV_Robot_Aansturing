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
#include "/home/agit/Documents/github/WoR_OpenCV_Robot_Aansturing/src/wor-r_bp2_ws/src/robot_arm_aansturing/src/kinematics/motion_controller.cpp"
#include <ros/ros.h>

std::string pictureWindow = "Picture";
const double baseHeight = 60;
std::string input, aColour, aShape;


int main(int argc, char **argv) {

	cv::Mat picture_raw, show ,dst;
	//cv::namedWindow(pictureWindow, CV_WINDOW_AUTOSIZE);
	Configuration c;

	picture_raw = getCameraFeed(1);

	go_to_start_pos(argc,argv);

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
			//input = "blauw vierkant";
			std::cout<<input<<std::endl;
			picture_raw = getCameraFeed(1);
			std::stringstream  ss(input);
			Imageinfo info = getImageInfo(picture_raw);

			ss >> aColour >> aShape;

			SearchQuery target(picture_raw, dst, colourfinder::colour(c.findColour(aColour)),shapeFinder::shape(c.findShape(aShape)));
			SearchQuery whiteCircle(picture_raw, dst, colourfinder::colour(c.findColour("wit")),shapeFinder::shape(c.findShape("cirkel")));
			goal targetParam = findGoal(target, info, baseHeight);
			goal whiteCirle = 	findGoal(whiteCircle, info, baseHeight);
			std::cout << "target:\t"<< "angle:" << targetParam.angle << "\tx:" << targetParam.x << "\ty:" << targetParam.y << std::endl;
			std::cout << "goal:\t" <<"angle:" << whiteCirle.angle << "\tx:" << whiteCirle.x << "\ty:" << whiteCirle.y << std::endl;

			execute_motion(argc,argv,targetParam.angle,targetParam.x,targetParam.y,whiteCirle.angle,whiteCirle.x,whiteCirle.y);

		}
	}



}

