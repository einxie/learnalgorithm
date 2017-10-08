#ifndef DISJOINTSET_H
#define DISJOINTSET_H

#include <list>
#include <vector>

using std::vector;
using std::list;

struct Vertex {
    int index;
    int color;
    int distance;
    Vertex* parent;
};

class DisjointSet {
public:
	DisjointSet();
	~DisjointSet();
	void make_set(Vertex m_vertex);
	bool union_set(Vertex m_vertex_1, Vertex m_vertex_2);
	Vertex find_set(Vertex m_vertex);

protected:
	int find_set_inner(Vertex m_vertex);
	
private:
	vector<list<Vertex> > dsets;
};

#endif
