#include <iostream>
#include <vector>

#define INF 20000000

int main() {
	int cities, buslines;
	scanf_s("%d %d", &cities, &buslines);
	std::vector<std::vector<int>> connections(cities + 1, std::vector<int>(cities + 1, INF));

	int from, to, cost;
	for (int i = 0; i < buslines; ++i) {
		scanf_s("%d %d %d", &from, &to, &cost);
		if (connections[from][to] > cost) connections[from][to] = cost;
	}

	for (int i = 1; i <= cities; ++i) {
		for (int j = 1; j <= cities; ++j) {
			if (i == j) continue;
			for (int k = 1; k <= cities; ++k) {
				if (j == k) continue;
				if (connections[j][k] > connections[j][i] + connections[i][k]) {
					connections[j][k] = connections[j][i] + connections[i][k];
				}
			}
		}
	}
	
	for (int i = 1; i <= cities; ++i) {
		if (connections[i][1] == INF) printf("0");
		else printf("%d", connections[i][1]);
		for (int j = 2; j <= cities; ++j) {
			if (connections[i][j] == INF) printf(" 0");
			else printf(" %d", connections[i][j]);
		}
		putchar('\n');
	}
}