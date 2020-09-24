
#include <iostream>
#include <vector>

#include "weighted_graph.h"

using namespace std;

int main(void) {

	vector<Edge<int>> edges = {
		{ {1,2},  1},
		{ {1,6}, -1},
		{ {2,3},  2},
		{ {6,7},  5},
		{ {6,4},  4},
		{ {4,5},  3}
	};

	WeightedGraph<int> graph(edges);

	graph.print_edges();
	cout << endl;
	graph.print_vertexes();

	return 0;
}