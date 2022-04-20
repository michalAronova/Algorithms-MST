#ifndef UNION_FIND_H
	#define UNION_FIND_H

#include <vector>
#include "Element.h"

class DisjointSets {
private:
	vector<Element> _A;

public:
	//c'tor
	DisjointSets(int);

	void makeSet(int);
	int find(int);
	void union_groups(int, int);
};

#endif