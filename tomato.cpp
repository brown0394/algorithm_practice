#include <iostream>
#include <queue>
#include <vector>

int main() {
	int row, col;
	scanf_s("%d %d", &col, &row);

	std::vector<std::vector<int>> table(row, std::vector<int>(col));
	std::vector<std::vector<bool>> visited(row, std::vector<bool>(col, false));
	int greenTomato = 0;
	std::queue<std::pair<int, int>> q1;
	std::queue<std::pair<int, int>> q2;
	std::queue<std::pair<int, int>>* toVisit = &q1;
	std::queue<std::pair<int, int>>* toStore = &q2;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			scanf_s("%d", &table[i][j]);
			switch (table[i][j]) {
			case 0: {++greenTomato; break; }
			case 1: { toVisit->push(std::make_pair(i, j)); }
			case -1: {visited[i][j] = true; break; }
			}
		}
	}
	int i, j;
	int days = -1;
	while (!toVisit->empty() || !toStore->empty()) {
		while (!toVisit->empty()) {
			i = toVisit->front().first;
			j = toVisit->front().second;
			toVisit->pop();
			if (j + 1 < col && !visited[i][j + 1]) {
				toStore->push(std::make_pair(i, j + 1));
				visited[i][j + 1] = true;
				--greenTomato;
			}
			if (i + 1 < row && !visited[i + 1][j]) {
				toStore->push(std::make_pair(i + 1, j));
				visited[i + 1][j] = true;
				--greenTomato;
			}
			if (j - 1 >= 0 && !visited[i][j - 1]) {
				toStore->push(std::make_pair(i, j - 1));
				visited[i][j - 1] = true;
				--greenTomato;
			}
			if (i - 1 >= 0 && !visited[i - 1][j]) {
				toStore->push(std::make_pair(i - 1, j));
				visited[i - 1][j] = true;
				--greenTomato;
			}
		}
		std::queue<std::pair<int, int>>* temp = toVisit;
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