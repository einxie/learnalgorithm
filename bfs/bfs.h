#include <queue>

using namespace std;

enum {VERTEX_WHITE, VERTEX_GRAY, VERTEX_BLACK};
static const int VERTEX_LENGTH = 5;

struct Vertex {
    int index;
    int color;
    int distance;
    Vertex* parent;
};

class Bfs {
public:
    Bfs(int (*m_edges)[VERTEX_LENGTH]);
    ~Bfs();

    void GenerateBfsGraph(int index);
    void PrintBfsGraph();

private:
    std::queue<Vertex> vertex_queue;
    Vertex vertexes[VERTEX_LENGTH];
    int edges[VERTEX_LENGTH][VERTEX_LENGTH];
};

