#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define INF 3000000
class node {
public:
	int idx;
	int* cost;
	node(int p_idx, int* p_cost);
	bool operator <(const node& other) const;
};

bool node::operator<(const node& other) const {
	return *other.cost < *this->cost;
}

node::node(int p_idx, int* p_cost) {
	idx = p_idx;
	cost = p_cost;
}

int main() {
	int vertexes, edges;
	scanf("%d %d", &vertexes, &edges);
	std::vector<std::map<int, int>> arr(vertexes + 1);
	int start;
	scanf("%d", &start);
	int from, to, cost;
	std::vector<node> pq;
	std::vector<int> startArr(vertexes + 1, INF);
	for (int i = 0; i < edges; ++i) {
		scanf("%d %d %d", &from, &to, &cost);
		if (from == start) {
			if (startArr[to] == INF) {
				startArr[to] = cost;
				pq.push_back(node(to, &startArr[to]));
			}
			else if (startArr[to] > cost) startArr[to] = cost;
		}
		else {
			auto found = arr[from].find(to);
			if (found == arr[from].end()) {
				arr[from].insert({ to, cost });
			}
			else if (found->second > cost) {
				found->second = cost;
			}
		}
	}
	std::make_heap(pq.begin(), pq.end());
	int idx;
	while (!pq.empty()) {
		std::pop_heap(pq.begin(), pq.end());
		idx = pq.back().idx;
		cost = *pq.back().cost;
		pq.pop_back();
		for (auto it = arr[idx].begin(); it != arr[idx].end(); ++it) {
			if (it->first != start) {
				if (startArr[it->first] > cost + it->second) {
					startArr[it->first] = cost + it->second;
					pq.push_back(node(it->first, &startArr[it->first]));
					std::push_heap(pq.begin(), pq.end());
				}
			}
		}
	}
	
	for (int i = 1; i <= vertexes; ++i) {
		if (i == start) {
			printf("0\n");
		}
		else if(startArr[i] == INF) {
			printf("INF\n");
		}
		else {
			printf("%d\n", startArr[i]);
		}
	}
}