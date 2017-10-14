#include "dag.h"
#include <iostream>

using std::cout;
using std::endl;

Dag::Dag(int (*m_edges)[VERTEX_LENGTH]) {
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
    dfs = new Dfs(m_edges);
    dfs->GenerateDfsGraph();
    dfs->PrintDfsGraph();
}

Dag::~Dag() {
    delete dfs;
    dfs = 0;
}

void Dag::dag_shortest_paths() {
    vector<Vertex> vlist = dfs->GetSorted();
    vertexes[1].distance = 0;
    for(int i = vlist.size(); i >= 0; i--) {
        Vertex vertex = vlist[i];
        for(int j = 0; j < VERTEX_LENGTH; j++) {
            if(edges[vertex.index][j] != 0) {
                relax(vertex.index, j);
            }
        }
    }
}

void Dag::relax(int index_1, int index_2) {
    if(vertexes[index_2].distance > vertexes[index_1].distance + edges[index_1][index_2]) {
        vertexes[index_2].distance = vertexes[index_1].distance + edges[index_1][index_2];
        vertexes[index_2].parent = &vertexes[index_1];
    }
}

void Dag::dag_print() {
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
