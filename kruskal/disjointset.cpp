#include "disjointset.h"
#include <iostream>

DisjointSet::DisjointSet() {}

DisjointSet::~DisjointSet() {}

void DisjointSet::make_set(Vertex m_vertex) {
	Vertex vertex = find_set(m_vertex);
	if(vertex.index >= 0) {
		return;
	}
	list<Vertex> dset;
	dset.push_front(m_vertex);
    dsets.push_back(dset);
    //std::cout << "dsets size:" << dset.size() << std::endl;
}

int DisjointSet::find_set_inner(Vertex m_vertex) {
    //std::cout << "dsets size:" << dsets.size() << std::endl;
	if(dsets.size() == 0) {
		return -1;
	}
    for(int i = 0; i < dsets.size(); i++) {
        list<Vertex>::iterator liter;
		for(liter = dsets[i].begin(); liter != dsets[i].end(); liter++) {
            //std::cout << "****i:" << i << " isize:" << dsets[i].size() << " vertex:" << m_vertex.index << " iter:" << liter->index << std::endl;
			if(liter->index == m_vertex.index) {
				return i;
			}
		}		
	}
	return -1;
}

Vertex DisjointSet::find_set(Vertex m_vertex) {
    Vertex ret;
    ret.index = -1;
    int index = find_set_inner(m_vertex);
    //std::cout << "find vertex:" << m_vertex.index+1 << " index:" << index << std::endl;
    if(index < 0 || index >= dsets.size()) {
        return ret;
    }
	list<Vertex> dset = dsets[index];
	if(dset.size() == 0) {
		return ret;
	}
    ret = dset.back();
	return ret;
}

bool DisjointSet::union_set(Vertex m_vertex_1, Vertex m_vertex_2) {
    int index_1 = find_set_inner(m_vertex_1);
    int index_2 = find_set_inner(m_vertex_2);
	if(index_1 < 0 || index_1 >= dsets.size() || index_2 < 0 || index_2 >= dsets.size() || index_1 == index_2) {
		return false;
	}
	for(; dsets[index_2].size() > 0;) {
		Vertex vertex = dsets[index_2].back();
        dsets[index_2].pop_back();
		dsets[index_1].push_front(vertex);
	}
    // 删除空list
    if(index_2 != dsets.size() - 1) {
        dsets[index_2] = dsets[dsets.size() - 1];
    }
    dsets.pop_back();
	return true;
}
