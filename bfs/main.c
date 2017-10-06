#include "bfs.h"

int main() {
	int test_vetex[5][5] = {
		{0, 1, 0, 0, 1},
		{1, 0, 1, 1, 1},
		{0, 1, 0, 1, 0},
		{0, 1, 1, 0, 1},
		{1, 1, 0, 1, 0}
	};
	Bfs bfs(test_vetex);
	bfs.GenerateBfsGraph(0);
	bfs.PrintBfsGraph();
}
