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
}
bool NDGraph::IsConnected()
{
	//DFS: Visit(1) and marking visited vertices -> if all visited, connected. otherwise not connected
}

void NDGraph::SortEdges()
{
	Algorithms::QuickSort(m_EdgesList);
	m_EdgesAreSorted = true;
}

int NDGraph::CalcPrim()
{
	if (!IsConnected())
		throw "No MST";
}
int NDGraph::CalcKruskal()
{
	if (!IsConnected())
		throw "No MST";
}