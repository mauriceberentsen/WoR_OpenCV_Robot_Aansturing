/*
 * CommandLineParser.hpp
 *
 *  Created on: Mar 16, 2017
 *      Author: root
 */

#ifndef COMMANDLINEPARSER_HPP_
#define COMMANDLINEPARSER_HPP_

#include <iostream>
#include <fstream>
#include <regex>
#include <algorithm>
#include <exception>
#include <vector>

class CommandLineParser
{
public:
	/**
	 * @brief default constructor
	 */
	CommandLineParser();

	/**
	 * @brief this function will parse the content of the given file
	 * @param aFileName name of the input file
	 */
	void parseFile(char* aFileName);

	/**
	 * @brief destructor
	 */
	virtual ~CommandLineParser();

private:
	std::vector<std::string> readFile(char* aFileName);
	void parseContent(std::vector<std::string> aFile);
};

#endif /* COMMANDLINEPARSER_HPP_ */
