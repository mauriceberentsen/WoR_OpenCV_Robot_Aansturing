/*
 * findGoals.hpp
 *
 *  Created on: 6 apr. 2017
 *      Author: maurice
 */

#ifndef FINDGOALS_HPP_
#define FINDGOALS_HPP_
#include "SearchQuery.h"
#include "searchAruco.hpp"

struct goal
{
		double angle;
		double x;
		double y;
};

goal findGoal(SearchQuery& search, Imageinfo& info, double baseHeight);



#endif /* FINDGOALS_HPP_ */
