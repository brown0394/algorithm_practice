#include <iostream>
#include <vector>
#include <queue>

enum direction {
	HORIZONTAL = 1,
	VERTICAL,
	DIAGONAL
};

struct node {
	int i;
	int j;
	direction dir;
};

int main() {
	int n;
	scanf_s("%d", &n);
	std::vector<std::vector<int>> mat(n, std::vector<int>(n));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf_s("%d", &mat[i][j]);
		}
	}
	int possibleRoutes = 0;
	std::queue<node> q;
	q.push({ 0, 1, HORIZONTAL });
	node cur;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur.i == n - 1 && cur.j == n - 1) {
			++possibleRoutes;
			continue;
		}
		switch (cur.dir) {
		case VERTICAL: {
			if (cur.i + 1 < n && !mat[cur.i + 1][cur.j]) {
				q.push({ cur.i + 1, cur.j, VERTICAL });
				if (cur.j + 1 < n && !mat[cur.i][cur.j + 1] && !mat[cur.i + 1][cur.j + 1]) {
					q.push({ cur.i + 1, cur.j + 1, DIAGONAL });
				}
			}
			break;
		}
		case HORIZONTAL: {
			if (cur.j+ 1 < n && !mat[cur.i][cur.j + 1]) {
				q.push({ cur.i, cur.j + 1, HORIZONTAL });
				if (cur.i + 1 < n && !mat[cur.i + 1][cur.j] && !mat[cur.i + 1][cur.j + 1]) {
					q.push({ cur.i + 1, cur.j + 1, DIAGONAL });
				}
			}
			break;
		}
		case DIAGONAL: {
			int added = 0;
			if (cur.i + 1 < n && !mat[cur.i + 1][cur.j]) {
				q.push({ cur.i + 1, cur.j, VERTICAL });
				++added;
			}
			if (cur.j + 1 < n && !mat[cur.i][cur.j + 1]) {
				q.push({ cur.i, cur.j + 1, HORIZONTAL });
				++added;
			}
			if (added == 2 && !mat[cur.i + 1][cur.j + 1]) q.push({ cur.i + 1, cur.j + 1, DIAGONAL });
			break;
		}
		}
	}
	printf("%d\n", possibleRoutes);
}