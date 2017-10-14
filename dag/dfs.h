#ifndef DFS_H
#define DFS_H

#include <vector>

using std::vector;

enum {VERTEX_WHITE, VERTEX_GRAY, VERTEX_BLACK};
static const int VERTEX_LENGTH = 6;

struct Vertex {
    int index;
    int color;
    int distance;
	int ftime;
    Vertex* parent;
};

class Dfs {
public:
    Dfs(int (*m_edges)[VERTEX_LENGTH]);
    ~Dfs();

    void GenerateDfsGraph();
	void DfsVisit(int index);
    void PrintDfsGraph();

    vector<Vertex> GetSorted();

private:
    Vertex vertexes[VERTEX_LENGTH];
    int edges[VERTEX_LENGTH][VERTEX_LENGTH];
	int visit_time;
    vector<Vertex> vlist;
};

#endif
