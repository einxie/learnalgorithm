#ifndef DIJKSTRA_H
#define DIJKSTRA_H

const int VERTEX_LENGTH = 5;
const int DISTANCE_MAX = 100;

struct Vertex {
    int index;
    int distance;
    Vertex* parent;
    bool operator<(Vertex vertex) {
        return distance < vertex.distance;
    }
};

class Dijkstra {
public:
    Dijkstra(int (*m_edges)[VERTEX_LENGTH]);
    ~Dijkstra();
	
	void dijkstra_process();
	void dijkstra_print();
	void relax(int index_1, int index_2);
	
protected:
	void dijkstra_inner(int index);
	
private:
    Vertex vertexes[VERTEX_LENGTH];
    int edges[VERTEX_LENGTH][VERTEX_LENGTH];
};

#endif
