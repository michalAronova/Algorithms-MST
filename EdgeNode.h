#ifndef _EDGENODE_H
#define  _EDGENODE_H

class EdgeNode
{
private:
	EdgeNode* m_NextNode = nullptr;
	EdgeNode* m_PrevNode = nullptr;
	EdgeNode* m_TwinNode = nullptr;
	int m_Vertex;
	int m_Weight;

public:
	EdgeNode(int vertex, int weight, EdgeNode* next = nullptr) : m_Vertex(vertex), m_Weight(weight), m_NextNode(next) {};

	EdgeNode* GetNext()   { return m_NextNode; }
	EdgeNode* GetPrev()   { return m_PrevNode; }
	EdgeNode* GetTwin()   { return m_TwinNode; }
	int		  GetVertex() { return m_Vertex;   }
	int		  GetWeight() { return m_Weight;   }

	void	  SetNext(EdgeNode* next) { m_NextNode = next; }
	void	  SetPrev(EdgeNode* prev) { m_PrevNode = prev; }
	void	  SetTwin(EdgeNode* twin) { m_TwinNode = twin; }
	void	  SetVertex(int vertex)   { m_Vertex = vertex; }
	void	  SetWeight(int weight)   { m_Weight = weight; }
};

#endif