#ifndef _EDGE_H
#define _EDGE_H
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
};

#endif