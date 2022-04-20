#ifndef _ELEMENT_H
	#define  _ELEMENT_H

#pragma warning(disable: 4996)
using namespace std;

#include <iostream>

class Element {
private:
	int _parent;
	int _size;
	friend class DisjointSets;

public:
	Element(int, int);

};


#endif