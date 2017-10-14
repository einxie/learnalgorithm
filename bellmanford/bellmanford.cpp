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
            if(m_edges[i][j] != 0) {
                Edge edge;
                edge.index_u = i;
                edge.index_v = j;
                edge.weight = m_edges[i][j];
                edges.push_back(edge);
            }
        }
    }
}

Bellmanford::~Bellmanford() {}

bool Bellmanford::bellman_ford_process() {
    vertexes[0].distance = 0;
	for(int i = 0; i < VERTEX_LENGTH; i++) {
        for(int j = 0; j < edges.size(); j++) {
            relex(edges[j]);
        }
        //bellman_ford_print();
	}
	for(int j = 0; j < VERTEX_LENGTH; j++) {
        for(int j = 0; j < edges.size(); j++) {
            Edge edge = edges[j];
            if(vertexes[edge.index_v].distance > vertexes[edge.index_u].distance + edge.weight) {
                return false;
            }
		}
	}
	
	return true;
}

void Bellmanford::relex(Edge edge) {
	if(vertexes[edge.index_v].distance > vertexes[edge.index_u].distance + edge.weight) {
		vertexes[edge.index_v].distance = vertexes[edge.index_u].distance + edge.weight;
		vertexes[edge.index_v].parent = &vertexes[edge.index_u];
	}
}

void Bellmanford::bellman_ford_print() {
	std::cout << "---------------------print begin" << std::endl;
	for(int i = 0; i < VERTEX_LENGTH; i++) {
		std::cout << "vertex index:" << i+1 << ", distance:" << vertexes[i].distance << std::endl;
	}
    for(int i = 0; i < VERTEX_LENGTH; i++) {
        Vertex vertex = vertexes[i];
        cout << "vertex tree indexes:" << i+1 << " ";
        while(vertex.parent != 0) {
            vertex = *(vertex.parent);
            cout << vertex.index+1 << " ";
        }
        cout << endl;
    }

	std::cout << "---------------------print end" << std::endl;
}
