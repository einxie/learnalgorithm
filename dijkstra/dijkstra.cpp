#include "dijkstra.h"
#include <iostream>
using std::cout;
using std::endl;

Dijkstra::Dijkstra(int (*m_edges)[VERTEX_LENGTH]) {
    if(m_edges == 0) {
        return;
    }
    for(int i = 0; i < VERTEX_LENGTH; i++) {
        Vertex vertex;
        vertex.index = i;
        vertex.distance = DISTANCE_MAX ;
        vertex.parent = 0;
        vertexes[i] = vertex;
        for(int j = 0; j < VERTEX_LENGTH; j++) {
            edges[i][j] = m_edges[i][j];
        }
    }
}

Dijkstra::~Dijkstra() {}

void Dijkstra::dijkstra_process() {
    dijkstra_inner(0);
}

void Dijkstra::dijkstra_inner(int index) {
	if(index != 0) {
		Vertex temp = vertexes[0];
		vertexes[0] = vertexes[index];
		vertexes[index] = temp;
	}
    vertexes[0].distance = 0;
    for(int i = 0; i < VERTEX_LENGTH - 1; i++) {
		int index_min = i + 1;
		int distance_min = DISTANCE_MAX;
        for(int j = i + 1; j < VERTEX_LENGTH; j++) {
			if(edges[vertexes[i].index][vertexes[j].index] > 0) {
				relax(i, j);
			}
        }
        for(int j = i + 1; j < VERTEX_LENGTH; j++) {
			if(distance_min > vertexes[j].distance) {
				distance_min = vertexes[j].distance;
				index_min = j;
			}				
        }
		if(index_min != i + 1) {
			Vertex temp = vertexes[i + 1];
			vertexes[i + 1] = vertexes[index_min];
			vertexes[index_min] = temp;
		}
        cout << "after index:" << vertexes[i].index+1 << endl;
        dijkstra_print();
    }
}

void Dijkstra::relax(int index_1, int index_2) {
    if(vertexes[index_2].distance > vertexes[index_1].distance + edges[vertexes[index_1].index][vertexes[index_2].index]) {
        vertexes[index_2].distance = vertexes[index_1].distance + edges[vertexes[index_1].index][vertexes[index_2].index];
        vertexes[index_2].parent = &vertexes[index_1];
    }
}

void Dijkstra::dijkstra_print() {
	std::cout << "---------------------print begin" << std::endl;
	for(int i = 0; i < VERTEX_LENGTH; i++) {
		std::cout << "vertex index:" << vertexes[i].index+1 << ", distance:" << vertexes[i].distance << std::endl;
	}
    for(int i = 0; i < VERTEX_LENGTH; i++) {
        Vertex vertex = vertexes[i];
        cout << "vertex tree indexes:" << vertex.index+1 << " ";
        while(vertex.parent != 0) {
            vertex = *(vertex.parent);
            cout << vertex.index+1 << " ";
        }
        cout << endl;
    }
	std::cout << "---------------------print end" << std::endl;
}
