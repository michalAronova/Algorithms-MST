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
	inputFile.open(inputFileName);
	if(!inputFile.is_open())
	{
		throw "invalid input";
	}

	int n;
	string line;
	getline(inputFile, line);
	stringstream sstream(line);
	sstream >> n;
	if(sstream.fail())
	{
		throw "invalid input";
	}
	if(sstream.tellg() != EOF)
	{
		string dummy;
		sstream >> dummy;
		if(dummy.size() == 0)
		{
			
		}
	}

	
	// open file v
	// check that file is opened v
	// loop through lines
	// first=nodes+second=edges need to be one integer each
	// then we need to have (edges)+1 iterations ->if exceeds it is error
	// (edges) iterations need to have 3 integers -> first 2 must be from (1-nodes) -> last one some integer (may be negative) (method - getEdge)
	// last iteration should be 2 integers both nodes (1-nodes)
	//
	// for each line - check 'line finished' - if the line continues after what we want, invalid input
	//
	// if all okay - check that last pair is in the previous (both directions! u->v OR v->u)
}

void run()
{
	string str;

	int numberOfCommands;
	cin >> numberOfCommands;

	if (numberOfCommands <= 0)
	{
		throw "wrong input";
	}

	cin.get();
	getline(cin, str);
	handleFirstLine(str);

	DataStructure ds = DataStructure::CreateEmpty();

	for (int i = 0; i < numberOfCommands - 1; i++)
	{
		getline(cin, str);
		checkValidCommand(str);
		doStuff(str, ds);
	}

	getline(cin, str);
	if (str != "")
	{
		throw "wrong input";
	}
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
	outputFile.open(outputFileName);
	if (!outputFile.is_open())
	{
		throw "invalid input";
	}
	outputFile << message << endl;
	outputFile.close();
}

Edge Program::getValidEdge(const string& line)
{
	
}

string makeStringFromNumber(int number)
{
	stringstream sstream;
	string numStr;

	sstream << number;
	sstream >> numStr;
	return numStr;
}
