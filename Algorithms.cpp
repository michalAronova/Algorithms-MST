#include "Algorithms.h"

enum colour{ WHITE, GRAY, BLACK };

vector<int> DFS(const NDGraph& G) {
	int vertexNum = G.getVerticesNum();
	int currentRoot;
	int u;
	vector<colour> colours;
	for (u = 0; u < vertexNum; u++) {
		colours[u] = WHITE;
	}
	for (u = 0; u < vertexNum; u++) {
		if (colours[u] == WHITE) {
			currentRoot = u;
			VISIT(u, currentRoot);
		}
	}
} 

void 