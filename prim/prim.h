#ifndef PRIM_H
#define PRIM_H

#include <list>
#include <vector>

using std::list;
using std::vector;

static const int VERTEX_LENGTH = 9;

struct Vertex {
    int index;
    int key;
    Vertex* parent;
    bool operator<(Vertex vertex) {
        return key < vertex.key;
    }
};

struct Edge {
    int index_u;
    int index_v;
    int weight;
};

class Prim {
public:
    Prim(int (*m_edges)[VERTEX_LENGTH]);
    ~Prim();
	
	void mst_prim();
	void mst_print();
	
protected:
    void mst_prim_inner(int index);
	
private:
    Vertex vertexes[VERTEX_LENGTH];
    int edges[VERTEX_LENGTH][VERTEX_LENGTH];
	vector<Edge> spath;
};

#endif
