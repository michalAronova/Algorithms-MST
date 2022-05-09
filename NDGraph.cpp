#include "NDGraph.h"

void NDGraph::MakeEmptyGraph(int numOfVertices)
{
	for(int i=0;i<numOfVertices;i++)
	{
		m_Graph.push_back(AdjList(i + 1));
	}
}

bool NDGraph::IsAdjacent(int u, int v)
{
	bool adjacent = false;
	if (m_Graph[u - 1].FindVertex(v) != nullptr)
	{
		adjacent = true;
	}
	return adjacent;
}

vector<int> NDGraph::GetAdjList(int vertex) const
{
	return m_Graph[vertex - 1].getAdjVerticesList();
}

void NDGraph::AddEdge(Edge edge)
{
	AddEdge(edge.getU(), edge.getV(), edge.getWeight());
}

void NDGraph::AddEdge(int u, int v, int c)
{
	EdgeNode* TouNode = new EdgeNode(u, c);
	EdgeNode* TovNode = new EdgeNode(v, c);
	TouNode->SetTwin(TovNode);
	TovNode->SetTwin(TouNode);
	m_Graph[u - 1].insertNode(TovNode);
	m_Graph[v - 1].insertNode(TouNode);
}

void NDGraph::RemoveEdge(int u, int v)
{
	int toRemove = FindEdgeIndex({ u, v });
	if(toRemove == -1)
	{
		throw "invalid input";
	}
	EdgeNode* uEdgeNode = m_Graph[u - 1].removeNode(v);
	m_Graph[v - 1].removeNode(uEdgeNode->GetTwin());
	m_EdgesList.erase(m_EdgesList.begin() + toRemove);
	delete uEdgeNode;
}

int NDGraph::FindEdgeIndex(vector<int> lookFor)
{
	int index = -1;
	bool found = false;
	for(int i = 0 ; i < m_EdgesList.size() && !found ; i++)
	{
		if(m_EdgesList[i].isEqual(lookFor))
		{
			index = i;
			found = true;
		}
	}
	return index;
}

void NDGraph::BuildGraph(const vector<Edge>& edges)
{
	for (const Edge& edge : edges)
	{
		AddEdge(edge);
	}
	m_EdgesList = edges;
}

bool NDGraph::IsConnected()
{
	vector<int> DFSTrees = DFS();
	int vertex1Root = DFSTrees[0];
	bool isConnected = true;

	for (int i = 1; i < DFSTrees.size() && isConnected; i++)
	{
		if(DFSTrees[i] != vertex1Root)
		{
			isConnected = false;
		}
	}
	return isConnected;
}

void NDGraph::SortEdges()
{
	if (!m_EdgesAreSorted)
	{
		QuickSort(m_EdgesList);
		m_EdgesAreSorted = true;
	}
}

int NDGraph::CalcPrim()
{
	vector<bool> inT;
	vector<int> min, p;
	inT.resize(m_verticesNum, false);
	min.resize(m_verticesNum);
	p.resize(m_verticesNum);

	min[0] = 0;
	p[0] = nil;

	for (int v = 1; v < m_verticesNum; v++)
	{
		min[v] = INT32_MAX;
		p[v] = nil;
	}

	int u, res = 0;
	MinHeap Q(min);
	while (!Q.IsEmpty())
	{
		u = Q.DeleteMin().GetData();
		inT[u - 1] = true;

		EdgeNode* curr = m_Graph[u - 1].Head();
		while (curr != nullptr)
		{
			int v = curr->GetVertex();
			int w = curr->GetWeight();
			if (!inT[v - 1] &&  w < min[v - 1])
			{
				min[v - 1] = w;
				p[v - 1] = u;
				Q.DecreaseKey(v, min[v - 1]);
			}
			curr = curr->GetNext();
		}
	}
	for (int weight : min)
	{
		res += weight;
	}
	return res;
}


int NDGraph::CalcKruskal()
{
	vector<Edge> edgeSet;
	DisjointSets UF(m_verticesNum);
	int u, v;
	SortEdges();

	for (int v = 0; v < m_verticesNum; v++)
	{
		UF.makeSet(v);
	}

	for (const Edge& edge : m_EdgesList)
	{
		u = UF.find(edge.getU() - 1);
		v = UF.find(edge.getV() - 1);
		if (u != v)
		{
			edgeSet.push_back(edge);
			UF.union_groups(u, v);
		}
	}
	return calcTotalWeight(edgeSet);
}

int NDGraph::calcTotalWeight(const vector<Edge>& edgeSet)
{
	int res = 0;
	for (const Edge& edge : edgeSet)
	{
		res += edge.getWeight();
	}
	return res;
}

vector<int> NDGraph::DFS() {
	int vertexNum = getVerticesNum();
	int currentRoot;
	int u;
	vector<colours> colour;
	vector<int> root;
	colour.resize(vertexNum);
	root.resize(vertexNum);

	for (u = 0; u < vertexNum; u++) {
		colour[u] = WHITE;
	}
	for (u = 0; u < vertexNum; u++) {
		if (colour[u] == WHITE) {
			currentRoot = u;
			VISIT(u, currentRoot, root, colour);
		}
	}
	return root;
}

void NDGraph::VISIT(int u, int currentRoot, vector<int>& Root, vector<colours>& colour) {
	Root[u] = currentRoot;
	colour[u] = GRAY;
	for (int v : GetAdjList(u + 1)) {
		if (colour[v - 1] == WHITE) {
			VISIT(v - 1, currentRoot, Root, colour);
		}
	}
	colour[u] = BLACK;
}