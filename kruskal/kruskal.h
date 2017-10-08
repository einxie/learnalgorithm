#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "disjointset.h"
#include <queue>

using std::priority_queue;

static const int VERTEX_LENGTH = 9;
enum {VERTEX_WHITE, VERTEX_GRAY, VERTEX_BLACK};

struct Edge {
    int index_u;
    int index_v;
    int weight;
};

class EdgeCompare {
public:
	bool operator()(Edge edge_1, Edge edge_2) const {
		return edge_1.weight > edge_2.weight;
	}
};

class Kruskal {
public:
    Kruskal(int (*m_edges)[VERTEX_LENGTH]);
    ~Kruskal();
	
	void mst_kruskal();
	void mst_print();
	
private:
    Vertex vertexes[VERTEX_LENGTH];
	vector<Edge> spath;
    int edges[VERTEX_LENGTH][VERTEX_LENGTH];
	priority_queue<Edge, vector<Edge>, EdgeCompare> edges_pqueue;
	DisjointSet k_dsets;
};

#endif
