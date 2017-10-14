#include "bellmanford.h"

int main() {
	int test_vetex[VERTEX_LENGTH][VERTEX_LENGTH] = {
		{0, 6, 0, 0, 7},
		{0, 0, 5, -4, 8},
		{0, -2, 0, 0, 0},
		{2, 0, 7, 0, 9},
		{0, 0, -3, 9, 0}
	};
	Bellmanford bellmanford(test_vetex);
	bellmanford.bellman_ford_process();
	bellmanford.bellman_ford_print();
}
