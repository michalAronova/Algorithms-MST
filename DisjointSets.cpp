#include "DisjointSets.h"

DisjointSets::DisjointSets(int n)
{
	for (int i = 0; i < n; i++)
	{
		_A.push_back({ -1,0 });
	}
}

void DisjointSets::makeSet(int x)
{
	_A[x]._parent = x;
	_A[x]._size = 1;
}

int DisjointSets::find(int x)
{
	if (_A[x]._parent == x) {
		return x;
	}
	else {
		return(_A[x]._parent = find(_A[x]._parent)); //path compression improvement
	}
}

void DisjointSets::union_groups(int x, int y) //use union by size improvement
{
	int xRep = find(x);
	int yRep = find(y);

	if (_A[xRep]._size > _A[yRep]._size)
	{
		_A[yRep]._parent = xRep;
		_A[xRep]._size += _A[yRep]._size;
	}
	else {
		_A[xRep]._parent = yRep;
		_A[yRep]._size += _A[xRep]._size;
	}
}