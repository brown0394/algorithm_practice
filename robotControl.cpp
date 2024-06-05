#include <iostream>
#include <vector>

int main() {
	int row, col;
	scanf_s("%d %d", &row, &col);
	std::vector<std::vector<int>> mars(row, std::vector<int>(col));
	std::vector<std::vector<int>> costs(row, std::vector<int>(col));
	std::vector<int> lcosts(col);
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			scanf_s("%d", &mars[i][j]);
		}
	}
	costs[0][0] = mars[0][0];
	for (int i = 1; i < col; ++i) {
		costs[0][i] = costs[0][i - 1] + mars[0][i];
	}
	for (int i = 1; i < row; ++i) {
		costs[i][0] = mars[i][0] + costs[i - 1][0];
		for (int j = 1; j < col; ++j) {
			if (costs[i - 1][j] > costs[i][j - 1]) {
				costs[i][j] = mars[i][j] + costs[i - 1][j];
			}
			else costs[i][j] = mars[i][j] + costs[i][j - 1];
		}
		lcosts[col - 1] = mars[i][col - 1] + costs[i - 1][col - 1];
		if (costs[i][col - 1] < lcosts[col - 1]) {
			costs[i][col - 1] = lcosts[col - 1];
		}
		for (int j = col - 2; j >= 0; --j) {
			if (lcosts[j + 1] > costs[i - 1][j]) {
				lcosts[j] = mars[i][j] + lcosts[j + 1];
			}
			else {
				lcosts[j] = mars[i][j] + costs[i - 1][j];
			}
			if (lcosts[j] > costs[i][j]) costs[i][j] = lcosts[j];
		}
	}
	printf("%d\n", costs[row - 1][col - 1]);
}