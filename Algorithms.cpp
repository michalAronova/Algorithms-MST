#include "Algorithms.h"

vector<int> DFS(const NDGraph& G) {
	int vertexNum = G.getVerticesNum();
	int currentRoot;
	int u;
	vector<colours> colour;
	vector<int> root;
	for (u = 0; u < vertexNum; u++) {
		colour[u] = WHITE;
	}
	for (u = 0; u < vertexNum; u++) {
		if (colour[u] == WHITE) {
			currentRoot = u;
			VISIT(u, G, currentRoot, root, colour);
		}
	}
	return root;
}

void VISIT(int u, const NDGraph& G, int currentRoot, vector<int>& Root, vector<colours>& colour) {
	Root[u] = currentRoot;
	colour[u] = GRAY;
	for (int v : G.GetAdjList(u)) {
		if (colour[u] == WHITE) {
			VISIT(v, G, currentRoot, Root, colour);
		}
	 }
	colour[u] = BLACK;
}
void QuickSort(vector<Edge>& edges)
{
	QuickSort(edges, 0, edges.size() - 1);
}

void QuickSort(vector<Edge>& edges, int left, int right)
{
	if (left < right)
	{
		int part = Partition(edges, left, right);

		QuickSort(edges, left, part - 1);
		QuickSort(edges, part + 1, right);
	}
}

int Partition(vector<Edge>& edges, int left, int right)
{
	Edge pivot = edges[left];
	int i = left;
	int j = right;
	int pivotIndex = i;
	bool swapped = false;

	while (j > i)
	{
		if (edges[i] > edges[j])
		{
			Edge::SwapEdges(edges[i], edges[j]);
			swapped = true;
		}
		if(swapped)
		{
			if(pivotIndex == i)
			{
				pivotIndex = j;
				i++;
			}
			else
			{
				pivotIndex = i;
				j--;
			}
		}
		else
		{
			if (pivotIndex == i)
			{
				j--;
			}
			else
			{
				i++;
			}
		}
	}
	return pivotIndex;
}