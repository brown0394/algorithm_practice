#include <iostream>
#include <vector>
#include <queue>

struct node {
	int to;
	int cost;
};

bool operator < (const node& one, const node& two) {
	return one.cost > two.cost;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int vertexes, edges;
	std::cin >> vertexes >> edges;
	std::vector<std::vector<node>> connection(vertexes + 1);
	for (int i = 0; i < edges; ++i) {
		int from, to, cost;
		std::cin >> from >> to >> cost;
		connection[from].push_back({to, cost});
		connection[to].push_back({ from, cost });
	}
	std::priority_queue<node> pq;
	pq.push({1, 0});
	std::vector<bool> visited(vertexes + 1);
	int maxCost = 0;
	int total = 0;
	while (!pq.empty()) {
		int cur = pq.top().to;
		int cost = pq.top().cost;
		pq.pop();
		if (visited[cur]) continue;
		if (cost > maxCost) maxCost = cost;
		total += cost;
		visited[cur] = true;
		for (auto it = connection[cur].begin(), end = connection[cur].end(); it != end; ++it) {
			if (visited[it->to]) continue;
			pq.push(std::move(*it));
		}
	}
	std::cout << total - maxCost << '\n';
}