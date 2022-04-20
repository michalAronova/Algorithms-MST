#ifndef _ADJLIST_H
#define  _ADJLIST_H

#include "EdgeNode.h"
#include <vector>
using namespace std;
class AdjList
{
private:
	int m_Vertex;
	EdgeNode* m_Head = nullptr;
public:
	AdjList(int vertex) { m_Vertex = vertex; };
	EdgeNode*	Head();
	EdgeNode*   FindVertex(int vertex);
	bool		isVertexInList(int vertex); //maybe dont need it
	void		insertNode(int vertex, int weight);
	void		insertNode(EdgeNode* node);
	EdgeNode*	removeNode(int vertex);
	void		removeNode(EdgeNode* node);
	int			getWeightOf(int vertex);
	vector<int> getAdjVerticesList();
	~AdjList();
};

#endif