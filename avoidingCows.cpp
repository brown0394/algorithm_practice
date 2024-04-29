#include <iostream>
#include <vector>
#include <queue>
#include <map>

#define INVALID 2000000000

struct node {
	int to;
	int* cost;
	bool operator < (const node& other) {
		return *cost > *other.cost;
	}
};

bool operator < (const node& one, const node& another) {
	return *one.cost > *another.cost;
}

int main() {
	int vertex, edge;
	scanf("%d %d", &vertex, &edge);
	std::vector<std::map<int, int>> costs(vertex + 1);
	std::priority_queue<node> heap;
	std::vector<int> startPoint(vertex + 1, INVALID);
	int from, to, cost;
	for (int i = 0; i < edge; ++i) {
		scanf("%d %d %d", &from, &to, &cost);
		if (from == 1) {
			if (startPoint[to] > cost) {
				if (startPoint[to] == INVALID) heap.push({ to, &startPoint[to] });
				startPoint[to] = cost;
			}
		}
		else if (to == 1) {
			if (startPoint[from] > cost) {
				if (startPoint[from] == INVALID) heap.push({ from, &startPoint[from] });
				startPoint[from] = cost;
			}
		}
		else {
			auto found = costs[from].find(to);
			if (found == costs[from].end()) {
				costs[from].insert({ to, cost });
				costs[to].insert({ from, cost });
			}
			else if (found->second > cost) {
				found->second = cost;
				found = costs[to].find(from);
				found->second = cost;
			}
		}
	}
	while (!heap.empty()) {
		node cur = heap.top();
		heap.pop();
		for (auto it = costs[cur.to].begin(); it != costs[cur.to].end(); ++it) {
			if (startPoint[it->first] > *cur.cost + it->second) {
				heap.push({ it->first, &startPoint[it->first] });
				startPoint[it->first] = *cur.cost + it->second;
			}
		}
	}
	printf("%d\n", startPoint[vertex]);
}