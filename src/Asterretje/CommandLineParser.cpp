/*
 * CommandLineParser.cpp
 *
 *  Created on: Mar 16, 2017
 *      Author: root
 */

#include "CommandLineParser.hpp"
#include "AStar.hpp"
#include "Graph.hpp"

CommandLineParser::CommandLineParser()
{
	// TODO Auto-generated constructor stub
}

CommandLineParser::~CommandLineParser() {
	// TODO Auto-generated destructor stub
}

std::vector<std::string> CommandLineParser::readFile(char* aFileName)
{
	std::ifstream file(aFileName);
	std::string line;
	std::vector<std::string> content;
	std::string::size_type n;

	if (file.is_open())
	{
		while (getline(file, line))
		{
			n  = line.find(";");

			if(n==std::string::npos) content.push_back(line);
			else if(n!=0)
			{
				content.push_back(line.substr(0,n));
			}
		}
		file.close();
	}
	else
	{
		throw std::invalid_argument
		{ "given file could not be opened or does not exist" };
	}
	return content;
}

void CommandLineParser::parseContent(std::vector<std::string> aFile)
{
	std::regex headerPart ("([[])([[:w:]]+)[[:space:]]+([[:digit:]]+)(])");
	std::regex vertexContent("([[:w:]]+)[[:space:]]*[,][[:space:]]*([[:digit:]]+)[[:space:]]*[,][[:space:]]*([[:digit:]]+)[[:space:]]*[,][[:space:]]*([[:digit:]]+)[[:space:]]*");
	std::regex edgeContent ("([[:w:]]+)[[:space:]]*[,][[:space:]]*([[:w:]]+)[[:space:]]*[,][[:space:]]*([[:digit:]]+)");
	std::smatch matchResults;
	std::size_t nVertex = 0;
	bool vertexfound = false;
	bool edgefound = false;
	std::size_t nEdges = 0;

	Graph g;

		std::for_each(aFile.begin(),aFile.end(),[&g,&headerPart,&vertexContent,&edgeContent,&matchResults,&nVertex,&nEdges,&vertexfound,&edgefound](std::string& s)
				{
					if(std::regex_search(s, matchResults, headerPart))
					{
						if(matchResults.str(2) == "vertices")
						{
							vertexfound = true;
							edgefound = false;
							nVertex = stoul(matchResults.str(3));
						}
						else if(matchResults.str(2) == "edges")
						{
							vertexfound = false;
							edgefound = true;
							nEdges = stoul(matchResults.str(3));
						}
						else throw std::runtime_error("found: "+matchResults.str(1)+" this header is invalid." );

					}
					if(vertexfound)
					{
						if(std::regex_search(s, matchResults, vertexContent))
						{
							g.addVertex(PathAlgorithm::Vertex(matchResults.str(1),std::stoi(matchResults.str(2)),std::stoi(matchResults.str(3)),std::stoi(matchResults.str(4))));
						}

					}
					else if(edgefound)
					{
						if(std::regex_search(s, matchResults, edgeContent))
						{

							g.addEdge(PathAlgorithm::Edge(g.findVertexbyName(matchResults.str(1)),
															g.findVertexbyName(matchResults.str(2)),
															std::stoi(matchResults.str(3))));

						}
					}
				});


		g.printEdges();

		//g.findShortestPath("start","finish");


}

void CommandLineParser::parseFile(char* aFileName)
{
	parseContent(readFile(aFileName));
}
