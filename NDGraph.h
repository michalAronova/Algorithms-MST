#ifndef _NDGRAPH_H
#define  _NDGRAPH_H

using namespace std;
#include "AdjList.h"
#include <vector>

struct Edge
{
	int u;
	int v;
	int weight;
};

class NDGraph
{
private:
	int m_verticesNum;
	int m_EdgesNum;
	vector<AdjList> m_Graph;
	vector<Edge> m_EdgesList;

public:
	NDGraph(int numOfVertices) { MakeEmptyGraph(numOfVertices); }

	void MakeEmptyGraph(int numOfVertices);
	bool IsAdjacent(int u, int v);
	vector<int> GetAdjList(int vertex);
	void AddEdge(int u, int v, int c);
	void AddEdge(Edge edge);
	void RemoveEdge(int u, int v);

	void BuildGraph(vector<Edge> edges);
	bool IsConnected();

	int CalcPrim();
	int CalcKruskal();
};

#endif

