#include "AdjList.h"

EdgeNode* AdjList::Head()
{
	return m_Head;
}

EdgeNode* AdjList::FindVertex(int vertex)
{
	EdgeNode* curr = Head();
	EdgeNode* requiredVertex = nullptr;
	bool found = false;
	while (curr != nullptr && !found)
	{
		if (curr->GetVertex() == vertex)
		{
			found = true;
			requiredVertex = curr;
		}
		curr = curr->GetNext();
	}
	return requiredVertex;
}

bool AdjList::isVertexInList(int vertex)
{
	EdgeNode* curr = Head();
	bool found = false;
	while(curr!=nullptr && !found)
	{
		if (curr->GetVertex() == vertex)
			found = true;
		curr = curr->GetNext();
	}
	return found;
}

void AdjList::insertNode(int vertex, int weight)
{
	EdgeNode* newNode = new EdgeNode(vertex, weight, Head());
	insertNode(newNode);
}

void AdjList::insertNode(EdgeNode* node)
{
	m_Head->SetPrev(node);
	m_Head = node;
}

EdgeNode* AdjList::removeNode(int vertex)
{
	EdgeNode* removed = FindVertex(vertex);

	if(removed == nullptr)
	{
		throw "Error: Vertex to remove not found!";
	}
	if(removed->GetPrev() == nullptr)
	{
		m_Head = removed->GetNext();
	}
	else
	{
		(removed->GetPrev())->SetNext(removed->GetNext());
	}
	return removed;
}

void AdjList::removeNode(EdgeNode* node)
{
	if (node->GetPrev() == nullptr)
	{
		m_Head = node->GetNext();
	}
	else
	{
		(node->GetPrev())->SetNext(node->GetNext());
	}
	delete node;
}

int AdjList::getWeightOf(int vertex)
{
	EdgeNode* required = FindVertex(vertex);

	if(required == nullptr)
	{
		throw "Error: Vertex not found!";
	}
	return required->GetWeight();
}

vector<int> AdjList::getAdjVerticesList()
{
	EdgeNode* curr = Head();
	vector<int> adjVerticesList;
	while(curr!=nullptr)
	{
		adjVerticesList.push_back(curr->GetVertex());
	}
	return adjVerticesList;
}

AdjList::~AdjList()
{
	EdgeNode* curr = Head();
	EdgeNode* next;
	while(curr!=nullptr)
	{
		next = curr->GetNext();
		delete curr;
		curr = next;
	}
}
