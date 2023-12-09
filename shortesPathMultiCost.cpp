#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class node {
public:
	int idx;
	int* cost;
	node(int p_idx, int* p_cost);
	bool operator <(const node& other) const;
};

bool node::operator<(const node& other) const{
	return *other.cost < *this->cost;
}

node::node(int p_idx, int* p_cost) {
	idx = p_idx;
	cost = p_cost;
}

int main() {
	int vertexes, edges;
	scanf_s("%d %d", &vertexes, &edges);
	std::vector<std::map<int, int>> arr(vertexes + 1);
	int start;
	scanf_s("%d", &start);
	int from, to, cost;
	std::vector<node> pq;
	for (int i = 0; i < edges; ++i) {
		scanf_s("%d %d %d", &from, &to, &cost);
		auto found = arr[from].find(to);
		if (found == arr[from].end()) {
			arr[from].insert({ to, cost });
		}
		else if (found->second > cost) {
			found->second = cost;
		}
	}
	for (auto it = arr[start].begin(); it != arr[start].end(); ++it) {
		pq.push_back(node(it->first, &it->second));
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
				auto found = arr[start].find(it->first);
				if (found == arr[start].end()) {
					auto inserted = arr[start].insert({ it->first, cost + it->second });
					pq.push_back(node(it->first, &inserted.first->second));
					std::push_heap(pq.begin(), pq.end());
				}
				else if (found->second > cost + it->second){
					found->second = cost + it->second;
					std::make_heap(pq.begin(), pq.end());
				}
			}
		}
	}
	int i = 1;
	for (auto it = arr[start].begin(); it != arr[start].end(); ++it) {
		while (i < it->first) {
			if (i == start) {
				printf("0\n");
			}
			else {
				printf("INF\n");
			}
			++i;
		}
		printf("%d\n", it->second);
		++i;
	}
	while (i <= vertexes) {
		if (i == start) {
			printf("0\n");
		}
		else {
			printf("INF\n");
		}
		++i;
	}
}