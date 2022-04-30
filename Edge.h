#ifndef _EDGE_H
#define _EDGE_H

using namespace std;
#include <vector>

class Edge
{
private:
	int m_u;
	int m_v;
	int m_weight;

public:
	Edge(int u, int v, int weight) : m_u(u), m_v(v), m_weight(weight) {}
	Edge(vector<int> edge) : m_u(edge[0]), m_v(edge[1]), m_weight(edge[2]) {}
	int getU() const { return m_u; }
	int getV() const { return m_v; }
	int getWeight() const { return m_weight; }

	bool operator<(const Edge& right)  const { return m_weight < right.m_weight; }
	bool operator>(const Edge& right)  const { return m_weight > right.m_weight; }
	bool operator==(const Edge& right) const { return m_weight == right.m_weight; }
	bool operator!=(const Edge& right) const { return m_weight == right.m_weight; }

	static void SwapEdges(Edge& edgeA, Edge& edgeB)
	{
		Edge temp = edgeA;
		edgeA = edgeB;
		edgeB = temp;
	}

	bool isEqual(const vector<int>& edge) const
	{
		return ((m_u == edge[0] && m_v == edge[1]) || (m_u == edge[1] && m_v == edge[0]));
	}
};

#endif