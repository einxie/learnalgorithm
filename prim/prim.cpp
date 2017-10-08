#include "prim.h"
#include <iostream>
using std::cout;
using std::endl;

Prim::Prim(int (*m_edges)[VERTEX_LENGTH]) {
    if(m_edges == 0) {
        return;
    }
    for(int i = 0; i < VERTEX_LENGTH; i++) {
        Vertex vertex;
        vertex.index = i;
        vertex.key = -1;
        vertex.parent = 0;
        vertexes[i] = vertex;
        for(int j = 0; j < VERTEX_LENGTH; j++) {
            edges[i][j] = m_edges[i][j];
        }
    }
}

Prim::~Prim() {}

void Prim::mst_prim() {
    mst_prim_inner(0);
}

void Prim::mst_prim_inner(int index) {
    for(int i = 0; i < VERTEX_LENGTH - 1; i++) {
        Edge edge;
        edge.weight = -1;
        int pos_j, pos_k;
        //cout << "mst pos:" << i << " index:" << vertexes[i].index << " key:" << vertexes[i].key << endl;
        for(int j = 0; j <=i; j++) {
            for(int k = i + 1; k < VERTEX_LENGTH; k++) {
                if(edges[vertexes[j].index][vertexes[k].index] > 0 && (edge.weight < 0 || edge.weight > edges[vertexes[j].index][vertexes[k].index])) {
                    pos_j = j;
                    pos_k = k;
                    edge.index_u = vertexes[j].index;
                    edge.index_v = vertexes[k].index;
                    edge.weight = edges[vertexes[j].index][vertexes[k].index];
                    //cout << "update posj:" << pos_j << " posk:" << pos_k << " indexu:" << edge.index_u+1 << " indexv:" << edge.index_v+1 << " weight:" << edge.weight << endl;
                }
            }
        }
        vertexes[pos_j].key = edge.weight;
        if(pos_k != i + 1) {
            Vertex tmp = vertexes[i + 1];
            vertexes[i + 1] = vertexes[pos_k];
            vertexes[pos_k] = tmp;
        }
        spath.push_back(edge);
    }
}

void Prim::mst_print() {
	std::cout << "---------------------print begin" << std::endl;
	for(int i = 0; i < spath.size(); i++) {
		std::cout << "edge from:" << spath[i].index_u+1 << ", to:" <<
		spath[i].index_v+1 << ", weight:" << spath[i].weight << std::endl;
	}
	std::cout << "---------------------print end" << std::endl;
}
