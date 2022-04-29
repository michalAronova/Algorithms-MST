#ifndef _PROGRAM_H
#define _PROGRAM_H

#include "NDGraph.h"
#include <stdlib.h>
#include <string>

#include <fstream>
#include <sstream>
using namespace std;

class Program
{
public:
	void Run(int argc, char** argv);
	void PrintToConsoleAndFile(const char* outputFileName, const string& toPrint);
	void PrintMSTResult(const char* outputFileName, const string& algorithm, int MSTWeight);
	void PrintToFile(const char* outputFileName, const string& message);
	vector<Edge> getValidInput(char* inputFileName, int& verticesNum, int& u, int& v);
	Edge getValidEdge(const string& line);
	string makeStringFromNumber(int number);

private:
	///validation methods
	///				technical			|			logic
	/// only digits						| each edge node is from 1-#nodes
	///	first  is #nodes				| 
	///	second is #edges				| 
	///	then check that there are		| 
	///	indeed (#edges) 'threes'		| 
	///	and another edge (to Remove)	| edge is in the graph
};

#endif