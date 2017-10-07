#include "dfs.h"

int main() {
	int test_vetex[6][6] = {
		{0, 1, 0, 1, 0, 0},
		{0, 0, 0, 0, 1, 0},
		{0, 0, 0, 0, 1, 1},
		{0, 1, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0, 0}
	};
	Dfs dfs(test_vetex);
	dfs.GenerateDfsGraph();
	dfs.PrintDfsGraph();
}
