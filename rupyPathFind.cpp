#include <iostream>
#include <vector>

#define INVALID 1000000000

int main() {
	int n, count = 1;
	std::vector<std::vector<int>> cave;
	std::vector<std::vector<int>> path;
	while (true) {
		scanf_s("%d", &n);
		if (!n) break;
		cave.resize(n, std::vector<int> (n));
		path.resize(n, std::vector<int>(n));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf_s("%d", &cave[i][j]);
			}
		}
		path[0][0] = cave[0][0];
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (j && path[j - 1][i] < path[j][i - 1]) {
					path[j][i] = path[j - 1][i] + cave[j][i];
				}
				else {
					path[j][i] = path[j][i - 1] + cave[j][i];
				}
				if (j && path[i][j - 1] < path[i - 1][j]) {
					path[i][j] = path[i][j - 1] + cave[i][j];
				}
				else {
					path[i][j] = path[i - 1][j] + cave[i][j];
				}
			}
			if (path[i][i - 1] < path[i - 1][i]) {
				path[i][i] = path[i][i - 1] + cave[i][i];
				int idx = i;
				while (--idx >= 0) {
					if (path[idx][i] > path[idx + 1][i] + cave[idx][i]) {
						path[idx][i] = path[idx + 1][i] + cave[idx][i];
					}
					else break;
				}
			}
			else {
				path[i][i] = path[i - 1][i] + cave[i][i];
				int idx = i;
				while (--idx >= 0) {
					if (path[i][idx] > path[i][idx + 1] + cave[i][idx]) {
						path[i][idx] = path[i][idx + 1] + cave[i][idx];
					}
					else break;
				}
			}
		}
		printf("Problem %d: %d\n", count++, path[n - 1][n - 1]);
		cave.clear();
		path.clear();
	}
}