#include <iostream>
#include <vector>
#include <algorithm>

struct node {
	int from;
	int to;
	int cost;
	bool operator<(const node& other) {
		return cost < other.cost;
	}
};
std::vector<int> parents;

int getParent(int child) {
	int parent = parents[child];
	while (parent != parents[parent]) parent = parents[parent];
	return parent;
}

int main() {
	int vertexes, edges;
	scanf_s("%d %d", &vertexes, &edges);
	std::vector<node> connections(edges);
	parents.resize(vertexes + 1, 0);
	for (int i = 0; i < edges; ++i) {
		scanf_s("%d %d %d", &connections[i].from, &connections[i].to, &connections[i].cost);
	}
	std::sort(connections.begin(), connections.end());
	int sum = 0;
	for (auto it = connections.begin(); it != connections.end(); ++it) {
		if (parents[it->from]) {
			parents[it->from] = getParent(parents[it->from]);
			if (parents[it->to]) {
				parents[it->to] = getParent(parents[it->to]);
				if (parents[it->to] == parents[it->from]) continue;
				parents[parents[it->to]] = parents[it->from];
			}
			else parents[it->to] = parents[it->from];
		}
		else {
			if (!parents[it->to]) {
				parents[it->from] = it->from;
				parents[it->to] = it->from;
			}
			else {
				parents[it->to] = getParent(parents[it->to]);
				parents[it->from] = parents[it->to];
			}
		}
		sum += it->cost;
	}
	printf("%d\n", sum);
}
