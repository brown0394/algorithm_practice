#include <iostream>
#include <vector>
#include <algorithm>

struct node {
	int to;
	int* cost;
};

bool sortStd(node& one, node& two) {
	return *one.cost > *two.cost;
}

int main() {
	int cities, buseLines;
	const int MAX = ~(1 << 31);
	scanf_s("%d %d", &cities, &buseLines);
	std::vector<std::vector<int>> cityConnections(cities + 1, std::vector<int>(cities + 1, MAX));

	int from, to, cost;
	for (int i = 0; i < buseLines; ++i) {
		scanf_s("%d %d %d", &from, &to, &cost);
		if (cost < cityConnections[from][to]) cityConnections[from][to] = cost;
	}
	scanf_s("%d %d", &from, &to);
	cityConnections[from][from] = 0;
	std::vector<node> pq(cityConnections[from].size());
	for (int i = 0; i < cityConnections[from].size(); ++i) {
		pq[i].to = i;
		pq[i].cost = &cityConnections[from][i];
	}
	pq.erase(pq.begin() + from);
	pq.erase(pq.begin());
	std::make_heap(pq.begin(), pq.end(), sortStd);
	int dest;
	bool update;
	while (!pq.empty()) {
		std::pop_heap(pq.begin(), pq.end(), sortStd);
		dest = pq.back().to;
		cost = *pq.back().cost;
		pq.pop_back();
		update = false;
		for (int i = 1; i < cityConnections[dest].size(); ++i) {
			if (cityConnections[dest][i] == MAX || cityConnections[from][dest] == MAX) continue;
			if (cityConnections[dest][i] + cityConnections[from][dest] < cityConnections[from][i]) {
				cityConnections[from][i] = cityConnections[dest][i] + cityConnections[from][dest];
				update = true;
			}
		}
		if (update) {
			std::make_heap(pq.begin(), pq.end(), sortStd);
		}
	}
	printf("%d\n", cityConnections[from][to]);
}