
enum {VERTEX_WHITE, VERTEX_GRAY, VERTEX_BLACK};
static const int VERTEX_LENGTH = 5;

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

private:
    Vertex vertexes[VERTEX_LENGTH];
    int edges[VERTEX_LENGTH][VERTEX_LENGTH];
	int visit_time;
};

