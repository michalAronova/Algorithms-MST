#include "Algorithms.h"

enum colours{ WHITE, GRAY, BLACK };

vector<int> DFS(const NDGraph& G) {
	int vertexNum = G.getVerticesNum();
	int currentRoot;
	int u;
	vector<colours> colour;
	vector<int> root;
	for (u = 0; u < vertexNum; u++) {
		colour[u] = WHITE;
	}
	for (u = 0; u < vertexNum; u++) {
		if (colour[u] == WHITE) {
			currentRoot = u;
			VISIT(u, G, currentRoot, root, colour);
		}
	}
} 

void VISIT(int u, const NDGraph& G, int currentRoot, vector<int>& Root, vector<colours>& colour) {
	Root[u] = currentRoot;
	colour[u] = GRAY;
	for (int v : G.GetAdjList(u)) {
		if (colour[u] == WHITE) {
			VISIT(v, G, currentRoot, Root, colour);
		}
	 }
	colour[u] = BLACK;
}