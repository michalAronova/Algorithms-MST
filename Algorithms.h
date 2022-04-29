#ifndef _ALGORITHMS_H
#define  _ALGORITHMS_H
	
#pragma warning(disable: 4996)
using namespace std;

#include <iostream>
#include <vector>
#include "NDGraph.h"
#include "AdjList.h"
enum colours { WHITE, GRAY, BLACK };

vector<int> DFS(const NDGraph& G);
void VISIT(int u, const NDGraph& G, int currentRoot, vector<int>& Root, vector<colours>& colours);
void QuickSort(vector<Edge>& edges);
void QuickSort(vector<Edge>& edges, int left, int right);
int Partition(vector<Edge>& edges, int left, int right);


#endif