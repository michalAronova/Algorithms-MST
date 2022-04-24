#ifndef _NDGRAPH_H
#define  _NDGRAPH_H

using namespace std;
#include "AdjList.h"
#include <vector>

class Edge
{
private:
	int m_u;
	int m_v;
	int m_weight;

public:
	Edge(int u, int v, int weight) : m_u(u), m_v(v), m_weight(weight) {}

	int getU() { return m_u; }
	int getV() { return m_v; }
	int getWeight() { return m_weight; }

	bool operator<(const Edge& right)  const { return m_weight < right.m_weight;  }
	bool operator>(const Edge& right)  const { return m_weight > right.m_weight;  }
	bool operator==(const Edge& right) const { return m_weight == right.m_weight; }
	bool operator!=(const Edge& right) const { return m_weight == right.m_weight; }

	static void SwapEdges(Edge& edgeA, Edge& edgeB)
	{
		Edge temp = edgeA;
		edgeA = edgeB;
		edgeB = temp;
	}
};

class NDGraph
{
private:
	int m_verticesNum;
	int m_EdgesNum;
	vector<AdjList> m_Graph;
	vector<Edge> m_EdgesList;
	bool m_EdgesAreSorted = false;

public:
	NDGraph(int numOfVertices) { MakeEmptyGraph(numOfVertices); }

	vector<int> GetAdjList(int vertex);
	int getVerticesNum() const { return m_verticesNum; }

	void MakeEmptyGraph(int numOfVertices);
	bool IsAdjacent(int u, int v);
	void AddEdge(int u, int v, int c);
	void AddEdge(Edge edge);
	void RemoveEdge(int u, int v);

	void BuildGraph(const vector<Edge>& edges);
	bool IsConnected();
	void SortEdges();

	int CalcPrim();
	int CalcKruskal();
};

#endif

