#include <queue>

using namespace std;

enum {VERTEX_WHITE, VERTEX_GRAY, VERTEX_BLACK};
static const int VERTEX_LENGTH = 5;

struct Vertex {
    int index;
    int color;
    int distance;
    struct Vertex* parent;
};

class Bfs {
public:
    Bfs(int (*m_edges)[VERTEX_LENGTH]);
    ~Bfs();

    void GenerateBfsGraph(int index);
    void PrintBfsGraph();

private:
    std::queue<struct Vertex> vertex_queue;
    struct Vertex vertexes[VERTEX_LENGTH];
    int edges[VERTEX_LENGTH][VERTEX_LENGTH];
};

