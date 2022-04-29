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
	if (m_Graph[u].FindVertex(v) != nullptr)
	{
		adjacent = true;
	}
	return adjacent;
}

vector<int> NDGraph::GetAdjList(int vertex) const
{
	return m_Graph[vertex].getAdjVerticesList();
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
	m_Graph[u].insertNode(TovNode);
	m_Graph[v].insertNode(TouNode);
}

void NDGraph::RemoveEdge(int u, int v)
{
	EdgeNode* uEdgeNode = m_Graph[u].removeNode(v);
	m_Graph[v].removeNode(uEdgeNode->GetTwin());
	delete uEdgeNode;
}

void NDGraph::BuildGraph(const vector<Edge>& edges)
{
	for (const Edge& edge : edges)
	{
		AddEdge(edge);
	}
	m_EdgesList = edges;
	m_EdgesNum = edges.size();
}
bool NDGraph::IsConnected()
{
	vector<int> DFSTrees = DFS(*this);
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
	QuickSort(m_EdgesList);
	m_EdgesAreSorted = true;
}

int NDGraph::CalcPrim()
{

}
int NDGraph::CalcKruskal()
{

}