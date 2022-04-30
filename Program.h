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
	Edge getEdgeFromLine(const string& line, int verticesNum);
	bool checkValidEdge(const vector<int>& res, int verticesNum);
	bool checkEdgeInVector(const vector<Edge>& edges, const vector<int>& edgeToRemove);
	vector<int> getNumbersFromLine(const string& line, int max);
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