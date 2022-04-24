#include "Algorithms.h"

enum colour{ WHITE, GRAY, BLACK };

vector<int> DFS(const NDGraph& G) {
	int vertexNum = G.getVerticesNum();
	int currentRoot;
	int u;
	vector<colour> colours;
	for (u = 0; u < vertexNum; u++) {
		colours[u] = WHITE;
	}
	for (u = 0; u < vertexNum; u++) {
		if (colours[u] == WHITE) {
			currentRoot = u;
			VISIT(u, currentRoot);
		}
	}
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