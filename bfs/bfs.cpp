#include "bfs.h"
#include <iostream>

using namespace std;

Bfs::Bfs(int (*m_edges)[VERTEX_LENGTH]) {
    if(m_edges == 0) {
        return;
    }
    for(int i = 0; i < VERTEX_LENGTH; i++) {
        Vertex vertex;
        vertex.index = i;
        vertex.color = VERTEX_WHITE;
        vertex.distance = 0;
        vertex.parent = 0;
        vertexes[i] = vertex;
        for(int j = 0; j < VERTEX_LENGTH; j++) {
            edges[i][j] = m_edges[i][j];
        }
    }
}

Bfs::~Bfs() {}

void Bfs::GenerateBfsGraph() {
    BfsVisit(0);
}

void Bfs::BfsVisit(int index) {
    if(index < 0 || index >= VERTEX_LENGTH) {
        return;
    }
    vertexes[index].color = VERTEX_GRAY;
    vertex_queue.push(vertexes[index]);
    while(!vertex_queue.empty()) {
        Vertex vertex = vertex_queue.front();
        vertex_queue.pop();
        for(int j = 0; j < VERTEX_LENGTH; j++) {
            if(edges[vertex.index][j] > 0) {
                if(vertexes[j].color == VERTEX_WHITE) {
                    vertexes[j].color = VERTEX_GRAY;
                    vertexes[j].distance = vertex.distance + 1;
                    vertexes[j].parent = &vertex;
                    vertex_queue.push(vertexes[j]);
                }
            }
        }
        vertexes[vertex.index].color = VERTEX_BLACK;
    }
}

void Bfs::PrintBfsGraph() {
    std::cout << "-------------------print graph begin" << std::endl;
    for(int i = 0; i < VERTEX_LENGTH; i++) {
        std::cout << "color:" << vertexes[i].color << ", distance:" << vertexes[i].distance << std::endl;
    }
    std::cout << "-------------------print graph end" << std::endl;
}
