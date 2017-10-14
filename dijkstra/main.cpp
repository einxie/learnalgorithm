#include "dijkstra.h"

int main() {
	int test_vetex[VERTEX_LENGTH][VERTEX_LENGTH] = {
		{0, 10, 0, 0, 5},
		{0, 0, 1, 0, 2},
		{0, 0, 0, 4, 0},
		{7, 0, 6, 0, 0},
		{0, 3, 9, 2, 0}
	};
	Dijkstra dijksta(test_vetex);
	dijksta.dijkstra_process();
	dijksta.dijkstra_print();
}
