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

void DisjointSets::union_groups(int repX, int repY) //use union by size improvement
{
	if (_A[repX]._size > _A[repY]._size)
	{
		_A[repY]._parent = repX;
		_A[repX]._size += _A[repY]._size;
	}
	else {
		_A[repX]._parent = repY;
		_A[repY]._size += _A[repX]._size;
	}
}