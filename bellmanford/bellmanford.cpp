#include "bellmanford.h"
#include <iostream>
using std::cout;
using std::endl;

Bellmanford::Bellmanford(int (*m_edges)[VERTEX_LENGTH]) {
    if(m_edges == 0) {
        return;
    }
    for(int i = 0; i < VERTEX_LENGTH; i++) {
        Vertex vertex;
        vertex.index = i;
        vertex.distance = VERTEX_KEYMAX;
        vertex.parent = 0;
        vertexes[i] = vertex;
        for(int j = 0; j < VERTEX_LENGTH; j++) {
            edges[i][j] = m_edges[i][j];
        }
    }
}

Bellmanford::~Bellmanford() {}

bool Bellmanford::bellman_ford_process() {
    vertexes[0].distance = 0;
	for(int i = 0; i < VERTEX_LENGTH; i++) {
		for(int j = 0; j < VERTEX_LENGTH; j++) {
			for(int k = 0; k < VERTEX_LENGTH; k++) {
				if(edges[j][k] != 0) {
					relex(vertexes[j], vertexes[k]);
				}
			}
		}
        //bellman_ford_print();
	}
	for(int j = 0; j < VERTEX_LENGTH; j++) {
		for(int k = 0; k < VERTEX_LENGTH; k++) {
			if(edges[j][k] != 0) {
			    if(vertexes[k].distance > vertexes[j].distance + edges[j][k]) {
				    return false;
			    }
            }
		}
	}
	
	return true;
}

void Bellmanford::relex(Vertex vertex_u, Vertex vertex_v) {
    //cout << "before index:" << vertex_u.index+1 << ", distance:" << vertex_u.distance << " index:" << vertex_v.index+1 << ", distance:" << vertex_v.distance << " edge:" << edges[vertex_u.index][vertex_v.  index] << endl;
	if(vertex_v.distance > vertex_u.distance + edges[vertex_u.index][vertex_v.index]) {
		vertex_v.distance = vertex_u.distance + edges[vertex_u.index][vertex_v.index];
		vertex_u.parent = &vertexes[vertex_v.index];
		vertexes[vertex_v.index] = vertex_v;		
	}
    //cout << "after index:" << vertex_u.index+1 << ", distance:" << vertex_u.distance << " index:" << vertex_v.index+1 << ", distance:" << vertex_v.distance << " edge:" << edges[vertex_u.index][vertex_v.  index] << endl;
}

void Bellmanford::bellman_ford_print() {
	std::cout << "---------------------print begin" << std::endl;
	for(int i = 0; i < VERTEX_LENGTH; i++) {
		std::cout << "vertex index:" << i+1 << ", distance:" << vertexes[i].distance << std::endl;
	}
	std::cout << "---------------------print end" << std::endl;
}
