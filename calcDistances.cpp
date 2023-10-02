#include <iostream>
#include <queue>
#include <vector>

struct data {
	int i;
	int j;
	int distance;
};

int main() {
	int row, col;
	scanf_s("%d %d", &row, &col);

	std::vector<std::vector<int>> answer(row, std::vector<int>(col, 0));
	std::vector<std::vector<bool>> visited(row, std::vector<bool>(col, false));
	std::queue<data> q;
	int in;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			scanf_s("%d", &in);
			switch (in) {
			case 0: { visited[i][j] = true; break; }
			case 2: { q.push({i, j, 0}); visited[i][j] = true; break; }
			}
		}
	}
	int i, j;
	int distance = 1;
	while (!q.empty()) {
		i = q.front().i;
		j = q.front().j;
		distance = q.front().distance;
		q.pop();
		if (j + 1 < col && !visited[i][j + 1]) {
			q.push({ i, j + 1 , distance + 1});
			visited[i][j + 1] = true;
			answer[i][j + 1] = distance + 1;
		}
		if (i + 1 < row && !visited[i + 1][j]) {
			q.push({ i + 1, j, distance + 1 });
			visited[i + 1][j] = true;
			answer[i + 1][j] = distance + 1;
		}
		if (j - 1 >= 0 && !visited[i][j - 1]) {
			q.push({ i, j - 1 , distance + 1});
			visited[i][j - 1] = true;
			answer[i][j - 1] = distance + 1;
		}
		if (i - 1 >= 0 && !visited[i - 1][j]) {
			q.push({ i - 1, j, distance + 1 });
			visited[i - 1][j] = true;
			answer[i - 1][j] = distance + 1;
		}
	}
	for (int i = 0; i < row; ++i) {
		if (visited[i][0]) {
			printf("%d", answer[i][0]);
		}
		else {
			printf("-1");
		}
		for (int j = 1; j < col; ++j) {
			if (visited[i][j]) {
				printf(" %d", answer[i][j]);
			}
			else {
				printf(" -1");
			}
		}
		putchar('\n');
	}
}