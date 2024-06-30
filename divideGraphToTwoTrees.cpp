#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

void print(std::vector<int>& v) {
	printf("\n");
	if (v.empty()) return;
	std::sort(v.begin(), v.end());
	auto it = v.begin();
	printf("%d", *it++);
	for (auto end = v.end(); it != end; ++it) printf(" %d", *it);
}
std::vector<bool> visited;
struct node {
	int to, edgeN;
};

void bfs(std::vector<int>& nodes, std::vector<int>& edges, std::vector<std::vector<node>>& connections, int nodeN) {
	nodes.push_back(nodeN);
	std::queue<int> q;
	q.push(nodeN);
	while (!q.empty()) {
		nodeN = q.front();
		q.pop();
		for (auto elems : connections[nodeN]) {
			if (!visited[elems.to]) {
				visited[elems.to] = true;
				q.push(elems.to);
				nodes.push_back(elems.to);
				edges.push_back(elems.edgeN);
			}
		}
	}
}

int main() {
	int nodes, edges;
	scanf_s("%d %d", &nodes, &edges);
	std::vector<std::vector<node>> connections(nodes + 1);
	visited.resize(nodes + 1, false);
	std::vector<int> nodes1;
	std::vector<int> edges1;
	std::vector<int> nodes2;
	std::vector<int> edges2;
	int from, to;
	for (int i = 1; i <= edges; ++i) {
		scanf_s("%d %d", &from, &to);
		connections[from].push_back({ to, i });
		connections[to].push_back({ from, i });
		
	}
	if (nodes < 3) {
		printf("-1\n");
		return 0;
	}
	int one = 0, two = 0;
	for (int i = 1; i <= nodes; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			if (nodes1.empty()) {
				bfs(nodes1, edges1, connections, i);
			}
			else if (nodes2.empty()) {
				bfs(nodes2, edges2, connections, i);
			}
			else {
				printf("-1\n");
				return 0;
			}
		}
	}
	if (nodes2.empty()) {
		nodes2.push_back(nodes1.back());
		nodes1.pop_back();
		edges1.pop_back();
	}
	else if (nodes1.size() == nodes2.size()) {
		printf("-1\n");
		return 0;
	}
	printf("%d %d", nodes1.size(), nodes2.size());
	print(nodes1);
	print(edges1);
	print(nodes2);
	print(edges2);
	printf("\n");
}