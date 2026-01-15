#include "Work2.h"
#include <iostream>
#include <vector>
using namespace std;

void Work2() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adjMat(n +1, vector<int>(n + 1, 0));

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;


		adjMat[u][v] = 1;
		adjMat[v][u] = 1; // Undirected graph
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << adjMat[i][j] << " ";
		}
		cout << endl;
	}

}