#include "dag.h"

int main() {
	int test_vetex[6][6] = {
		{0, 0, 0, 2, 4, 7},
		{2, 0, 0, 0, 0, 6},
		{3, 5, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, -2, 0, 0},
		{0, 0, 0, 1, -1, 0}
	};
	Dag dag(test_vetex);
    dag.dag_shortest_paths();
    dag.dag_print();
}
