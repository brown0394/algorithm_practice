#include <iostream>
#include <queue>
#include <vector>

struct node {
	int i;
	int j;
	int k;
};

int main() {
	int row, col, level;
	scanf_s("%d %d %d", &col, &row, &level);

	std::vector<std::vector<std::vector<int>>> table(level, std::vector<std::vector<int>>(row, std::vector<int>(col)));
	std::vector<std::vector<std::vector<int>>> visited(level, std::vector<std::vector<int>>(row, std::vector<int>(col, false)));
	int greenTomato = 0;
	std::queue<node> q1;
	std::queue<node> q2;
	std::queue<node>* toVisit = &q1;
	std::queue<node>* toStore = &q2;
	for (int i = 0; i < level; ++i) {
		for (int j = 0; j < row; ++j) {
			for (int k = 0; k < col; ++k) {
				scanf_s("%d", &table[i][j][k]);
				switch (table[i][j][k]) {
				case 0: {++greenTomato; break; }
				case 1: { toVisit->push(node{i, j, k}); }
				case -1: {visited[i][j][k] = true; break; }
				}
			}
		}
	}
	int i, j, k;
	int days = -1;
	while (!toVisit->empty() || !toStore->empty()) {
		while (!toVisit->empty()) {
			i = toVisit->front().i;
			j = toVisit->front().j;
			k = toVisit->front().k;
			toVisit->pop();
			if (k + 1 < col && !visited[i][j][k + 1]) {
				toStore->push(node{i, j, k + 1});
				visited[i][j][k + 1] = true;
				--greenTomato;
			}
			if (j + 1 < row && !visited[i][j + 1][k]) {
				toStore->push(node{ i, j + 1, k});
				visited[i][j + 1][k] = true;
				--greenTomato;
			}
			if (i + 1 < level && !visited[i + 1][j][k]) {
				toStore->push(node{ i + 1, j, k });
				visited[i + 1][j][k] = true;
				--greenTomato;
			}
			if (k - 1 >= 0 && !visited[i][j][k - 1]) {
				toStore->push(node{ i, j, k - 1});
				visited[i][j][k - 1] = true;
				--greenTomato;
			}
			if (j - 1 >= 0 && !visited[i][j - 1][k]) {
				toStore->push(node{ i, j - 1, k});
				visited[i][j - 1][k] = true;
				--greenTomato;
			}
			if (i - 1 >= 0 && !visited[i - 1][j][k]) {
				toStore->push(node{ i - 1, j, k });
				visited[i - 1][j][k] = true;
				--greenTomato;
			}
		}
		std::queue<node>* temp = toVisit;
		toVisit = toStore;
		toStore = temp;
		++days;
	}

	if (greenTomato) {
		printf("-1\n");
	}
	else {
		printf("%d\n", days);
	}

}