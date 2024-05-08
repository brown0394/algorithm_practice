#include <iostream>
#include <vector>
#include <queue>

#define INVALID 1000000000

struct node {
	int i;
	int j;
};
std::vector<std::vector<int>> cave;
std::vector<std::vector<int>> path;
bool operator < (const node& one, const node& another) {
	return path[one.i][one.j] > path[another.i][another.j];
}

int main() {
	int n, count = 1;
	while (true) {
		scanf_s("%d", &n);
		if (!n) break;
		cave.resize(n, std::vector<int> (n));
		path.resize(n, std::vector<int>(n, INVALID));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf_s("%d", &cave[i][j]);
			}
		}
		std::priority_queue<node> pq;
		path[0][0] = cave[0][0];
		path[1][0] = cave[0][0] + cave[1][0];
		path[0][1] = cave[0][0] + cave[0][1];
		pq.push({ 1, 0 });
		pq.push({ 0, 1 });
		int i, j;
		while (!pq.empty()) {
			i = pq.top().i;
			j = pq.top().j;
			pq.pop();
			if (i && path[i - 1][j] > path[i][j] + cave[i - 1][j]) {
				path[i - 1][j] = path[i][j] + cave[i - 1][j];
				pq.push({ i - 1, j });
			}
			if (j && path[i][j - 1] > path[i][j] + cave[i][j - 1]) {
				path[i][j - 1] = path[i][j] + cave[i][j - 1];
				pq.push({ i, j - 1 });
			}
			if (i + 1 < n && path[i + 1][j] > path[i][j] + cave[i + 1][j]) {
				path[i + 1][j] = path[i][j] + cave[i + 1][j];
				pq.push({ i + 1, j });
			}
			if (j + 1 < n && path[i][j + 1] > path[i][j] + cave[i][j + 1]) {
				path[i][j + 1] = path[i][j] + cave[i][j + 1];
				pq.push({ i, j + 1 });
			}
		}
		printf("Problem %d: %d\n", count++, path[n - 1][n - 1]);
		cave.clear();
		path.clear();
	}
}