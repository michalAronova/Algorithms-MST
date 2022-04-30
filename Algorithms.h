#ifndef _ALGORITHMS_H
#define  _ALGORITHMS_H
	
#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include "Edge.h"

using namespace std;


void QuickSort(vector<Edge>& edges);
void QuickSort(vector<Edge>& edges, int left, int right);
int Partition(vector<Edge>& edges, int left, int right);


#endif