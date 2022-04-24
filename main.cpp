#include "DisjointSets.h"

void main() {
	DisjointSets forest(6);

	for (int i = 0; i < 6; i++)
	{
		forest.makeSet(i);
	}
	forest.union_groups(forest.find(1), forest.find(2));
	forest.union_groups(3, 1);

	cout << forest.find(3) << endl;

}

/*
* Build graph (1) v
* DFS to check if connected (1) v
* visit for DFS (1) v
* Prim (1)
* Kruskal (1)
* QuickSort to sort edged (1) v
* edge as bridge - check if theres an answer in the forum
* input validation (3)
* excpetins (2)
* main
* 
* edge weight initialization: INT32_MAX
*/