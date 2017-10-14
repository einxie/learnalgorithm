#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include <vector>

using std::vector;

static const int VERTEX_LENGTH = 5;
static const int VERTEX_KEYMAX = 100;

struct Vertex {
    int index;
    int distance;
    Vertex* parent;
};

struct Edge {
    int index_u;
    int index_v;
    int weight;
};

class VertexCompare {
public:
	bool operator()(Vertex vertex_1, Vertex vertex_2) const {
		return vertex_1.distance < vertex_2.distance;
	}
};

class Bellmanford {
public:
    Bellmanford(int (*m_edges)[VERTEX_LENGTH]);
    ~Bellmanford();
	
	bool bellman_ford_process();
	void bellman_ford_print();
	void relex(Vertex vertex_1, Vertex vertex_2);
	
private:
    Vertex vertexes[VERTEX_LENGTH];
	vector<Edge> spath;
    int edges[VERTEX_LENGTH][VERTEX_LENGTH];
};

#endif
