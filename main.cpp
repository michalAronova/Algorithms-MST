#include "DisjointSets.h"
#include "Program.h"

void main(int argc, char** argv) 
{
	Program program;
	try
	{
		program.Run(argc, argv);
	}
	catch(const char* message)
	{
		cout << message;
		if(argc==3)
		{
			try 
			{
				program.PrintToFile(argv[2], message);
			}
			catch(const char* fileError) // catches only if unable to open file
			{
				cout << fileError << endl;
			}
		}
	}
}

/*
* Build graph (1) v
* DFS to check if connected (1) v
* visit for DFS (1) v
* Prim (1)
* Kruskal (1) v
* QuickSort to sort edged (1) v
* edge as bridge v
* input validation (3) v
* main
* 
* edge weight initialization: INT32_MAX
*/