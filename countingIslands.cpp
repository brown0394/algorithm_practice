#include <iostream>
#include <vector>
#include <queue>

struct node {
	int i;
	int j;
};
int row, col;
std::vector<std::vector<int>> terrains;

void markMap() {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			scanf_s("%d", &terrains[i][j]);
		}
	}
}

void markConnectedLands(std::queue<node>& q) {
	int i, j;
	while (!q.empty()) {
		i = q.front().i;
		j = q.front().j;
		q.pop();
		if (i + 1 < row && terrains[i + 1][j] == 1) {
			++terrains[i + 1][j];
			q.push({ i + 1, j });
		}
		if (j + 1 < col && terrains[i][j + 1] == 1) {
			++terrains[i][j + 1];
			q.push({ i, j + 1 });
		}
		if (i + 1 < row && j + 1 < col && terrains[i + 1][j + 1] == 1) {
			++terrains[i + 1][j + 1];
			q.push({i + 1, j + 1});
		}
		if (i && terrains[i - 1][j] == 1) {
			++terrains[i - 1][j];
			q.push({ i - 1, j });
		}
		if (j && terrains[i][j - 1] == 1) {
			++terrains[i][j - 1];
			q.push({ i, j - 1 });
		}
		if (i && j && terrains[i - 1][j - 1] == 1) {
			++terrains[i - 1][j - 1];
			q.push({ i - 1, j - 1 });
		}
		if (i && j + 1 < col && terrains[i - 1][j + 1] == 1) {
			++terrains[i - 1][j + 1];
			q.push({ i - 1, j + 1 });
		}
		if (j && i + 1 < row && terrains[i + 1][j - 1] == 1) {
			++terrains[i + 1][j - 1];
			q.push({ i + 1, j - 1 });
		}
	}
}

int countIslands() {
	int islands = 0;
	std::queue<node> q;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (terrains[i][j] == 1) {
				q.push({ i, j });
				++terrains[i][j];
				++islands;
				markConnectedLands(q);
			}
		}
	}
	return islands;
}

int main() {
	scanf_s("%d %d", &col, &row);
	while (row || col) {
		terrains.resize(row, std::vector<int>(col));
		markMap();
		int i, j;
		printf("%d\n", countIslands());
		scanf_s("%d %d", &col, &row);
		terrains.clear();
	}
}
