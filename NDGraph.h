#ifndef _NDGRAPH_H
#define  _NDGRAPH_H

using namespace std;
#include "Edge.h"
#include "AdjList.h"
#include "DisjointSets.h"
#include "Algorithms.h"
#include "MinHeap.h"

#include <vector>

#define nil -1
enum colours { WHITE, GRAY, BLACK };

class NDGraph
{
private:
	int m_verticesNum;
	vector<AdjList> m_Graph;
	vector<Edge> m_EdgesList;
	bool m_EdgesAreSorted = false;

public:
	NDGraph(int numOfVertices, const vector<Edge>& edges)
	{
		m_verticesNum = numOfVertices;
		MakeEmptyGraph(numOfVertices);
		BuildGraph(edges);
	}

	vector<int> GetAdjList(int vertex) const; 
	int getVerticesNum() const { return m_verticesNum; }

	void MakeEmptyGraph(int numOfVertices);
	bool IsAdjacent(int u, int v);
	void AddEdge(int u, int v, int c);
	void AddEdge(Edge edge);
	void RemoveEdge(int u, int v);
	int  FindEdgeIndex(vector<int> lookFor);

	void BuildGraph(const vector<Edge>& edges);
	bool IsConnected();
	void SortEdges();

	int CalcPrim();
	int CalcKruskal();

	int calcTotalWeight(const vector<Edge>& edgeSet);

	vector<int> DFS();
	void VISIT(int u, int currentRoot, vector<int>& Root, vector<colours>& colours);
};

#endif

