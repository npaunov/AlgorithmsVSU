#include "Work1.h"
#include <iostream>

using namespace std;

int inc_arr[20][20];
int ed_no = 0;

// For oriented (directed) graph, use 1 for start vertex, -1 for end vertex
void add_edge(int u, int v) {
	inc_arr[u][ed_no] = 1;   // u is the start vertex
	inc_arr[v][ed_no] = -1;  // v is the end vertex
	ed_no++;
}

void displayMatrix(int v, int e) {
	int i, j;
	for (i = 0; i < v; i++)	{
		for (j = 0; j < e; j++) {
			cout << inc_arr[i][j] << " ";
		}
		cout << endl;
	}
}

void Work1() {
	int v = 6;
	int e = 9;

	// Example: add_edge(start, end);
	add_edge(0, 4);
	add_edge(0, 3);
	add_edge(1, 2);
	add_edge(1, 4);
	add_edge(1, 5);
	add_edge(2, 3);
	add_edge(2, 5);
	add_edge(5, 3);
	add_edge(5, 4);

	displayMatrix(v, e);
}