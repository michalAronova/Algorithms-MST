#ifndef _ALGORITHMS_H
#define  _ALGORITHMS_H
	
#pragma warning(disable: 4996)
using namespace std;

#include <iostream>
#include <vector>
#include "NDGraph.h"
#include "AdjList.h"

vector<int> DFS(const NDGraph& G);
void QuickSort(vector<Edge>& edges);
void QuickSort(vector<Edge>& edges, int left, int right);
int Partition(vector<Edge>& edges, int left, int right);
void VISIT(int u, const NDGraph& G, int currentRoot, vector<int>& Root, vector<colours>& colours);


#endif