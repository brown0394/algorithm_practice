#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define INVALID 2000000000

bool comp(const std::pair<const int, int>* one, const std::pair<const int, int>* another) {
	return one->second > another->second;
}

int main() {
	int vertex, edge;
	scanf_s("%d %d", &vertex, &edge);
	std::vector<std::map<int, int>> costs(vertex + 1);
	std::vector<std::pair<const int, int>*> heap;
	int from, to, cost;
	for (int i = 0; i < edge; ++i) {
		scanf_s("%d %d %d", &from, &to, &cost);
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
	int idx = 1;
	for (auto it = costs[1].begin(); it != costs[1].end(); ++it) {
		heap.push_back(&(*it));
		if (it->first == idx) ++idx;
		else {
			for (; idx < it->first; ++idx) {
				costs[1].insert({ idx, INVALID });
			}
		}
	}
	for (; idx <= vertex; ++idx) {
		costs[1].insert({ idx, INVALID });
	}
	std::make_heap(heap.begin(), heap.end(), comp);
	while (!heap.empty()) {
		std::pop_heap(heap.begin(), heap.end(), comp);
		std::pair<const int, int>* cur = heap.back();
		heap.pop_back();
		bool change = false;
		for (auto it = costs[cur->first].begin(); it != costs[cur->first].end(); ++it) {
			if (it->first == 1) continue;
			auto found = costs[1].find(it->first);
			if (found->second > cur->second + it->second) {
				if (found->second == INVALID) heap.push_back(&(*found));
				found->second = cur->second + it->second;
				change = true;
			}
		}
		if (change) std::make_heap(heap.begin(), heap.end(), comp);
	}
	printf("%d\n", costs[1][vertex]);
}