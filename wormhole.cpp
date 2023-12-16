#include <iostream>
#include <vector>
#include <map>

#define INF 200000000

struct node {
	int to;
	int cost;
};

int main() {
	int testCases;
	scanf_s("%d", &testCases);
	int stations, paths, wormHoles, from, to, cost, start;
	std::vector<std::map<int, int>> connections;
	std::vector<int> startLoc;
	for (int test = 0; test < testCases; ++test) {
		scanf_s("%d %d %d", &stations, &paths, &wormHoles);
		connections.resize(stations+1);
		startLoc.resize(stations + 1, INF);
		start = 0;
		for (int i = 0; i < paths; ++i) {
			scanf_s("%d %d %d", &from, &to, &cost);
			auto found = connections[from].find(to);
			if (found == connections[from].end()) {
				connections[from].insert({ to, cost });
				connections[to].insert({ from, cost });
			}
			else if (found->second > cost) {
				found->second = cost;
				found = connections[to].find(from);
				found->second = cost;
			}
		}
		for (int i = 0; i < wormHoles; ++i) {
			scanf_s("%d %d %d", &from, &to, &cost);
			if (!start) start = from;
			auto found = connections[from].find(to);
			if (found == connections[from].end()) connections[from].insert({ to, -cost });
			else if (found->second > -cost) found->second = -cost;
		}
		startLoc[from] = 0;
		for (int i = 1; i < stations; ++i) {
			for (int j = 1; j <= stations; ++j) {
				if (startLoc[j] < INF) {
					for (auto it = connections[j].begin(); it != connections[j].end(); ++it) {
						if (startLoc[j] + it->second < startLoc[it->first]) startLoc[it->first] = startLoc[j] + it->second;
					}
				}
			}
		}
		bool decreasingCycle = false;
		for (int i = 1; i <= stations; ++i) {
			for (auto it = connections[i].begin(); it != connections[i].end(); ++it) {
				if (startLoc[i] + it->second < startLoc[it->first]) {
					decreasingCycle = true;
					break;
				}
			}
		}
		if (decreasingCycle) printf("YES\n");
		else printf("NO\n");
		connections.clear();
		startLoc.clear();
	}
}