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