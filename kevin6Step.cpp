#include <iostream>
#include <vector>
#include <numeric>

#define MAX 200

int main() {
	int users, edges;
	scanf_s("%d %d", &users, &edges);
	std::vector<std::vector<int>>userTable(users, std::vector<int>(users, MAX));
	int from, to;
	for (int i = 0; i < edges; ++i) {
		scanf_s("%d %d", &from, &to);
		userTable[from-1][to-1] = 1;
		userTable[to-1][from-1] = 1;
	}

	for (int i = 0; i < users; ++i) {
		for (int j = 0; j < users; ++j) {
			if (userTable[j][i] != MAX) {
				for (int k = 0; k < users; ++k) {
					if (userTable[i][k] == MAX || j == k) continue;
					if (userTable[j][k] > userTable[j][i] + userTable[i][k]) {
						userTable[j][k] = userTable[j][i] + userTable[i][k];
						userTable[k][j] = userTable[j][k];
					}
				}
			}
		}
	}
	int idx = 0;
	int min = std::accumulate(userTable[0].begin(), userTable[0].end(), 0);
	int sum;
	for (int i = 1; i < users; ++i) {
		sum = std::accumulate(userTable[i].begin(), userTable[i].end(), 0);
		if (min > sum) {
			min = sum;
			idx = i;
		}
	}
	printf("%d\n", idx + 1);
}