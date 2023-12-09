#include <iostream>
#include <vector>
#include <queue>

#define INF 300000

class node {
public:
	int idx;
	int cost;
	node(int p_idx, int p_cost);
	bool operator <(const node& other) const;
};

bool node::operator<(const node& other) const {
	return other.cost < this->cost;
}

node::node(int p_idx, int p_cost) {
	idx = p_idx;
	cost = p_cost;
}

int main() {
	int vertexes, edges;
	scanf("%d %d", &vertexes, &edges);
	std::vector<std::vector<node>> arr(vertexes + 1);
	int start;
	scanf("%d", &start);
	arr[start].reserve(vertexes + 1);
	for (int i = 0; i <= vertexes; ++i) {
		arr[start].push_back(node(i, INF));
	}
	int from, to, cost;
	std::priority_queue<node> pq;
	for (int i = 0; i < edges; ++i) {
		scanf("%d %d %d", &from, &to, &cost);
		if (from == start) {
			arr[from][to].cost = cost;
			pq.push(node(to, cost));
		}
		else {
			arr[from].push_back(node(to, cost));
		}
	}
	int idx;
	while (!pq.empty()) {
		idx = pq.top().idx;
		cost = pq.top().cost;
		pq.pop();
		for (int i = 0; i < arr[idx].size(); ++i) {
			if (arr[idx][i].idx != start && arr[start][arr[idx][i].idx].cost >
				cost + arr[idx][i].cost) {
				arr[start][arr[idx][i].idx].cost = cost + arr[idx][i].cost;
				pq.push(node(arr[idx][i].idx, arr[start][arr[idx][i].idx].cost));
			}
		}
	}
	for (int i = 1; i <= vertexes; ++i) {
		if (i == start) {
			printf("0\n");
		}
		else if (arr[start][i].cost == INF) {
			printf("INF\n");
		}
		else {
			printf("%d\n", arr[start][i].cost);
		}
	}
}