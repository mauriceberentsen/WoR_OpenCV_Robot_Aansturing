/*
 * webcam.cpp
 *
 *  Created on: 17 feb. 2017
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

cv::Mat edges, frame, dest, grey, output, detected_edges,dst, src;

int lowThreshold = 15;
cv::Size patternsize(3,3);

cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);

int chessboard() {
	cv::VideoCapture cap(1);

	if(!cap.isOpened())
	{
		return -1;
	}

	cv::namedWindow("filter", CV_WINDOW_AUTOSIZE);
	cv::namedWindow("natural_beauty", CV_WINDOW_AUTOSIZE);

	while(true)
	{
		for(;;)
		{
			cap >> src;
		    cv::Mat image, imageCopy;
		    image.copyTo(imageCopy);
		    std::vector<int> ids;
		    std::vector<std::vector<cv::Point2f> > corners;
		    cv::aruco::detectMarkers(src, cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250), corners, ids);
		    // if at least one marker detected
		    if (ids.size() > 0 && ids.size() < 2)
		    {
			    for(auto c : corners)
			    {

			    	float centX = (c.at(0).x + c.at(2).x) /2;
			    	float centY = (c.at(0).y + c.at(2).y) /2;
			    	cv::Point pt(centX, centY);
			    	cv::rectangle(src, pt , pt , CV_RGB(255,255,255), CV_FILLED);
			    }
		    }
		    cv::imshow("filter", src);

			if(cv::waitKey(30) >= 0)
			{
				break;
			}
		}
	}
}



