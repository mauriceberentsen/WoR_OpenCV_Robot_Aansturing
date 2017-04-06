/*
 * webcam.hpp
 *
 *  Created on: 16 mrt. 2017
 *      Author: maurice
 */

#ifndef WEBCAM_H_
#define WEBCAM_H_

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>

cv::Mat getCameraFeed(int dex)
{
	cv::Mat output;
	cv::VideoCapture cap(dex);

		for (int x = 0; x < 10; ++x) {//collect 30 frames because the webcam has to initialize
			cap >> output;

			cv::waitKey(30);
		}
	return output;
}


#endif /* WEBCAM_H_ */
