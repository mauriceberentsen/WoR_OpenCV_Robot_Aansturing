#include <opencv2/core.hpp>
#include "findGoals.hpp"


goal findGoal(SearchQuery& search, Imageinfo& info , double baseHeight)
{
	goal aGoal;

	if(search.result.size() >0)
		{
		double baseX = (info.nulPunt.first - info.correctionX) * info.ratioPixelToMM;
		double baseY = (info.nulPunt.second - info.correctionY) * info.ratioPixelToMM;
		std::cout<<"X_found: "<<baseX<< "| found_Y: " << (info.correctionY) * info.ratioPixelToMM <<std::endl;

		std::cout<<"X_cor: "<<(info.correctionX) * info.ratioPixelToMM<< "| Y_cor: " << baseY <<std::endl;

		double foundX  = (search.result.front().x - info.correctionX) * info.ratioPixelToMM;
		double foundY = (search.result.front().y - info.correctionY) * info.ratioPixelToMM;

		double ab = (std::pow(foundX,2) + std::pow(foundY,2));

		double schuine_zijde = std::sqrt(ab);

		double ang = std::atan(foundY/foundX)* 180 / CV_PI;



		aGoal.angle = ang;
		aGoal.x = schuine_zijde /10;
		aGoal.y = baseHeight * -1 /10;

		return aGoal;
		}
	else
	{
		throw std::runtime_error("No object found");
	}

}
/*
 * findGoals.cpp
 *
 *  Created on: 6 apr. 2017
 *      Author: maurice
 */




