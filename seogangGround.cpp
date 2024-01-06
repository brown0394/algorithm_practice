#include <iostream>
#include <vector>

#define INF 16

int main() {
	int vertexes, searchRange, edges;
	scanf_s("%d %d %d", &vertexes, &searchRange, &edges);
	std::vector<std::vector<int>> connections(vertexes + 1, std::vector<int>(vertexes + 1, INF));
	std::vector<int> items(vertexes + 1);
	std::vector<int> pickables(vertexes + 1);
	for (int i = 1; i <= vertexes; ++i) {
		scanf_s("%d", &items[i]);
		pickables[i] = items[i];
	}
	int from, to, cost;
	for (int i = 0; i < edges; ++i) {
		scanf_s("%d %d %d", &from, &to, &cost);
		if (cost <= searchRange) {
			connections[from][to] = cost;
			pickables[from] += items[to];
			connections[to][from] = cost;
			pickables[to] += items[from];
		}
	}

	for (int i = 1; i <= vertexes; ++i) {
		for (int j = 1; j <= vertexes; ++j) {
			if (i == j) continue;
			if (connections[j][i] == INF) continue;
			for (int k = 1; k <= vertexes; ++k) {
				if (j == k) continue;
				if (connections[j][k] > connections[j][i] + connections[i][k]) {
					if (connections[j][i] + connections[i][k] > searchRange) continue;
					if (connections[j][k] == INF) {
						connections[j][k] = connections[j][i] + connections[i][k];
						pickables[j] += items[k];
						pickables[k] += items[j];
					}
					else connections[j][k] = connections[j][i] + connections[i][k];
					connections[k][j] = connections[j][k];
				}
			}
		}
	}

	int max = 0;
	for (int i = 1; i <= vertexes; ++i) {
		if (max < pickables[i]) max = pickables[i];
	}
	printf("%d\n", max);
}