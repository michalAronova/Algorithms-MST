#include "AdjList.h"

EdgeNode* AdjList::Head() const
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
	if(m_Head == nullptr)
	{
		m_Head = node;
	}
	else
	{
		node->SetNext(m_Head);
		m_Head->SetPrev(node);
		m_Head = node;
	}
}

EdgeNode* AdjList::removeNode(int vertex)
{
	EdgeNode* removed = FindVertex(vertex);

	if(removed == nullptr)
	{
		throw "invalid input";
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



vector<int> AdjList::getAdjVerticesList() const
{
	EdgeNode* curr = Head();
	vector<int> adjVerticesList;
	while(curr!=nullptr)
	{
		adjVerticesList.push_back(curr->GetVertex());
		curr = curr->GetNext();
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
