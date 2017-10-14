#ifndef DAG_H
#define DAG_H
#include "dfs.h"

const static int VERTEX_KEYMAX = 100;

class Dag {
public:
    Dag(int (*m_edges)[VERTEX_LENGTH]);
    ~Dag();

    void dag_shortest_paths();
	void relax(int index_1, int index_2);
	void dag_print();

private:
    Vertex vertexes[VERTEX_LENGTH];
    int edges[VERTEX_LENGTH][VERTEX_LENGTH];

    Dfs* dfs;
};

#endif
