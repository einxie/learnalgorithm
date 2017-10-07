#include "bfs.h"

int main() {
	int test_vetex[8][8] = {
		{0, 1, 0, 0, 1, 0, 0, 0},
		{1, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 1, 0, 1, 1, 0},
		{0, 0, 1, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 0, 0, 0, 1, 0},
		{0, 0, 1, 1, 0, 1, 0, 1},
		{0, 0, 0, 1, 0, 0, 1, 0}
	};
	Bfs bfs(test_vetex);
	// bfs.GenerateBfsGraph();
	bfs.BfsVisit(1);
	bfs.PrintBfsGraph();
}
