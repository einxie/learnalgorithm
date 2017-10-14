#include "dfs.h"
#include <iostream>

using namespace std;

Dfs::Dfs(int (*m_edges)[VERTEX_LENGTH]) {
    if(m_edges == 0) {
        return;
    }
    for(int i = 0; i < VERTEX_LENGTH; i++) {
        Vertex vertex;
        vertex.index = i;
        vertex.color = VERTEX_WHITE;
        vertex.distance = -1;
		vertex.ftime = -1;
        vertex.parent = 0;
        vertexes[i] = vertex;
        for(int j = 0; j < VERTEX_LENGTH; j++) {
            edges[i][j] = m_edges[i][j];
        }
    }
}

Dfs::~Dfs() {}

void Dfs::GenerateDfsGraph() {
	visit_time = 0;
	for(int i = 0; i < VERTEX_LENGTH; ++i) {
		if(vertexes[i].color == VERTEX_WHITE) {
			DfsVisit(i);
		}
	}
}

void Dfs::DfsVisit(int index) {
    if(index < 0 || index >= VERTEX_LENGTH) {
        return;
    }
	vertexes[index].distance = ++visit_time;
	vertexes[index].color = VERTEX_GRAY;
	for(int j = 0; j < VERTEX_LENGTH; ++j) {
		if(edges[vertexes[index].index][j] > 0) {
			if(vertexes[j].color == VERTEX_WHITE) {
				vertexes[j].parent = &vertexes[index];
				DfsVisit(j);
			}
		}
	}
	vertexes[index].color = VERTEX_BLACK;
	vertexes[index].ftime = ++visit_time;
    vlist.push_back(vertexes[index]);
}

vector<Vertex> Dfs::GetSorted() {
    return vlist;
}

void Dfs::PrintDfsGraph() {
    std::cout << "-------------------print graph begin" << std::endl;
    for(int i = 0; i < VERTEX_LENGTH; i++) {
        std::cout << "index: " << i+1 << ", color:" << vertexes[i].color <<
		", distance:" << vertexes[i].distance << ", ftime:" << vertexes[i].ftime << std::endl;
    }
    std::cout << "-------------------print graph end" << std::endl;
    std::cout << "-------------------print topology sort begin" << std::endl;
    for(int i = 0; i < vlist.size(); i++) {
        std::cout << "index: " << vlist[i].index+1 << ", color:" << vlist[i].color <<
		", distance:" << vlist[i].distance << ", ftime:" << vlist[i].ftime << std::endl;
    }
    std::cout << "-------------------print topology sort end" << std::endl;
}
