#include "Program.h"

void Program::Run(int argc, char** argv)
{
	if (argc != 3)
	{
		throw "invalid input";
	}

	int verticesNum = 0, u = 0, v = 0, kruskal1, prim, kruskal2;
	vector<Edge> edges = getValidInput(argv[1], verticesNum, u, v);
	NDGraph graph(verticesNum, edges);

	if(!graph.IsConnected())
	{
		throw "invalid input";
	}
	kruskal1 = graph.CalcKruskal();
	PrintMSTResult(argv[2], "Kruskal", kruskal1);
	prim = graph.CalcPrim();
	PrintMSTResult(argv[2], "Prim", prim);

	graph.RemoveEdge(u, v);
	if (!graph.IsConnected())
	{
		throw "NO MST";
	}
	kruskal2 = graph.CalcKruskal();
	PrintMSTResult(argv[2], "Kruskal", kruskal2);
}


vector<Edge> Program::getValidInput(char* inputFileName, int& verticesNum, int& u, int& v)
{
	ifstream inputFile;
	inputFile.open(inputFileName, ios::in);
	if(!inputFile.is_open())
	{
		throw "invalid input";
	}

	int m; //#edges; 
	string line;
	vector<Edge> res;
	vector<int> edgeToRemove;
	getline(inputFile, line);
	verticesNum = getNumbersFromLine(line, 1).front();
	getline(inputFile, line);
	m = getNumbersFromLine(line, 1).front();
	if (verticesNum < 0 || m < 0)
	{
		throw "invalid input";
	}
	for (int i = 0; i < m; i++) //get all the edges
	{
		getline(inputFile, line);
		Edge edge = getEdgeFromLine(line, verticesNum);
		res.push_back(edge);
	}
	getline(inputFile, line); //edge to remove
	edgeToRemove = getNumbersFromLine(line, 2);
	if (checkEdgeInVector(res, edgeToRemove))
	{
		u = edgeToRemove[0];
		v = edgeToRemove[1];
	}
	else
	{
		throw "invalid input";
	}

	return res;
}

Edge Program::getEdgeFromLine(const string& line, int verticesNum)
{
	vector<int> edge = getNumbersFromLine(line, 3);
	bool valid = checkValidEdge(edge, verticesNum);
	if (!valid)
	{
		throw "invalid input";
	}
	return Edge(edge);
}

vector<int> Program::getNumbersFromLine(const string& line, int max)
{
	int n;
	vector<int> res;
	stringstream sstream(line);
	for (int i = 0; i < max; i++)
	{
		sstream >> n;
		if (sstream.fail())
		{
			throw "invalid input";
		}
		res.push_back(n);
	}
	string dummy;
	sstream >> dummy;
	if (!sstream.fail()) //if there's more string in line --> got more data than expected in a line --> invalid input
	{
		throw "invalid input";
	}
	return res;
}

bool Program::checkValidEdge(const vector<int>& edge, int verticesNum)
{
	if (edge[0] > verticesNum || edge[0] < 1)
	{
		return false;
	}
	if (edge[1] > verticesNum || edge[1] < 1)
	{
		return false;
	}
	return true;
}

bool Program::checkEdgeInVector(const vector<Edge>& edges, const vector<int>& edgeToRemove)
{
	bool found = false;
	for (const Edge& edge : edges)
	{
		if (edge.isEqual(edgeToRemove))
		{
			found = true;
		}
	}
	return found;
}

void Program::PrintMSTResult(const char* outputFileName, const string& algorithm, int MSTWeight)
{
	string MSTWeightString = makeStringFromNumber(MSTWeight);
	string toPrint = algorithm + " <" + MSTWeightString + ">";
	PrintToConsoleAndFile(outputFileName, toPrint);
}

void Program::PrintToConsoleAndFile(const char* outputFileName, const string& toPrint)
{
	cout << toPrint<< endl;
	PrintToFile(outputFileName, toPrint);
}

void Program::PrintToFile(const char* outputFileName, const string& message)
{
	ofstream outputFile;
	outputFile.open(outputFileName, ios_base::app);
	if (!outputFile.is_open())
	{
		throw "invalid input";
	}
	outputFile << message << endl;
	outputFile.close();
}

string Program::makeStringFromNumber(int number)
{
	stringstream sstream;
	string numStr;

	sstream << number;
	sstream >> numStr;
	return numStr;
}
