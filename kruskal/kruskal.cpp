#include "kruskal.h"
#include <iostream>

Kruskal::Kruskal(int (*m_edges)[VERTEX_LENGTH]) {
    if(m_edges == 0) {
        return;
    }
    for(int i = 0; i < VERTEX_LENGTH; i++) {
        Vertex vertex;
        vertex.index = i;
        vertex.parent = 0;
        vertexes[i] = vertex;
        for(int j = 0; j < VERTEX_LENGTH; j++) {
            edges[i][j] = m_edges[i][j];
            if(m_edges[i][j] > 0 && j > i) {
			    Edge edge;
			    edge.index_u = i;
			    edge.index_v = j;
			    edge.weight = m_edges[i][j];
			    edges_pqueue.push(edge);
            }
        }
    }
}

Kruskal::~Kruskal() {}

void Kruskal::mst_kruskal() {
	for(int i = 0; i < VERTEX_LENGTH; ++i) {
		k_dsets.make_set(vertexes[i]);
	}
    //std::cout << "pqueue size:" << edges_pqueue.size() << std::endl;
	for(; edges_pqueue.size() > 0;) {
		Edge edge = edges_pqueue.top();
        //std::cout << "pqueue edge u:" << edge.index_u+1 << " v:" << edge.index_v+1 << " weight:" << edge.weight << std::endl;
		edges_pqueue.pop();
		Vertex vertex_1 = k_dsets.find_set(vertexes[edge.index_u]);
		Vertex vertex_2 = k_dsets.find_set(vertexes[edge.index_v]);
		if(vertex_1.index >= 0 && vertex_2.index >= 0 && vertex_1.index != vertex_2.index) {
			spath.push_back(edge);
			k_dsets.union_set(vertex_1, vertex_2);
		}
	}
}

void Kruskal::mst_print() {
	std::cout << "---------------------print begin" << std::endl;
	for(int i = 0; i < spath.size(); i++) {
		std::cout << "edge from:" << spath[i].index_u+1 << ", to:" <<
		spath[i].index_v+1 << ", weight:" << spath[i].weight << std::endl;
	}
	std::cout << "---------------------print end" << std::endl;
}
