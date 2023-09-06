#include <iostream>
#include <vector>


int checkThreeMulTwoMat(std::vector<std::vector<int>>& table, int rstart, int cstart) {
	int bar = table[rstart][cstart] + table[rstart + 1][cstart] + table[rstart + 2][cstart];
	int max = bar + table[rstart][cstart + 1];
	int two = bar + table[rstart+1][cstart + 1];
	max = (max > two) ? max : two;
	two = bar + table[rstart+2][cstart + 1];
	max = (max > two) ? max : two;

	bar = table[rstart][cstart+1] + table[rstart + 1][cstart+1] + table[rstart + 2][cstart+1];
	two = bar + table[rstart][cstart];
	max = (max > two) ? max : two;
	two = bar + table[rstart+1][cstart];
	max = (max > two) ? max : two;
	two = bar + table[rstart + 2][cstart];
	max = (max > two) ? max : two;

	bar = table[rstart + 1][cstart] + table[rstart + 1][cstart + 1];
	two = bar + table[rstart][cstart] + table[rstart + 2][cstart + 1];
	max = (max > two) ? max : two;
	two = bar + table[rstart][cstart + 1] + table[rstart + 2][cstart];
	max = (max > two) ? max : two;
	return max;
}

int checkTwoMulThreeMat(std::vector<std::vector<int>>& table, int rstart, int cstart) {
	int bar = table[rstart][cstart] + table[rstart][cstart+1] + table[rstart][cstart+2];
	int max = bar + table[rstart + 1][cstart];
	int two = bar + table[rstart + 1][cstart + 1];
	max = (max > two) ? max : two;
	two = bar + table[rstart + 1][cstart + 2];
	max = (max > two) ? max : two;

	bar = table[rstart + 1][cstart] + table[rstart + 1][cstart + 1] + table[rstart + 1][cstart + 2];
	two = bar + table[rstart][cstart];
	max = (max > two) ? max : two;
	two = bar + table[rstart][cstart + 1];
	max = (max > two) ? max : two;
	two = bar + table[rstart][cstart + 2];
	max = (max > two) ? max : two;

	bar = table[rstart][cstart + 1] + table[rstart + 1][cstart + 1];
	two = bar + table[rstart][cstart] + table[rstart + 1][cstart + 2];
	max = (max > two) ? max : two;
	two = bar + table[rstart+ 1][cstart] + table[rstart][cstart + 2];
	max = (max > two) ? max : two;
	return max;
}

int checkSquare(std::vector<std::vector<int>>& table, int rstart, int cstart) {
	return table[rstart][cstart] + table[rstart][cstart + 1] + table[rstart + 1][cstart] + table[rstart + 1][cstart + 1];
}

int checkBarVertical(std::vector<std::vector<int>>& table, int rstart, int cstart) {
	return table[rstart][cstart] + table[rstart + 1][cstart] + table[rstart + 2][cstart] + table[rstart + 3][cstart];
}

int checkBarHorizontal(std::vector<std::vector<int>>& table, int rstart, int cstart) {
	return table[rstart][cstart] + table[rstart][cstart + 1] + table[rstart][cstart + 2] + table[rstart][cstart + 3];
}

int calcMinResult(std::vector<std::vector<int>>& table, int row, int col) {
	int max = 0;
	int two;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (i + 2 < row && j + 1 < col) {
				two = checkThreeMulTwoMat(table, i, j);
				max = (max > two) ? max : two;
			}
			if (i + 1 < row) {
				if (j + 1 < col) {
					two = checkSquare(table, i, j);
					max = (max > two) ? max : two;
				}
				if (j + 2 < col) {
					two = checkTwoMulThreeMat(table, i, j);
					max = (max > two) ? max : two;
				}
			}
			if (i + 3 < row) {
				two = checkBarVertical(table, i, j);
				max = (max > two) ? max : two;
			}
			if (j + 3 < col) {
				two = checkBarHorizontal(table, i, j);
				max = (max > two) ? max : two;
			}
		}
	}
	return max;
}

int main() {
	int row;
	int col;
	scanf_s("%d %d", &row, &col);
	std::vector<std::vector<int>> table(row);


	for (int i = 0; i < row; ++i) {
		table[i].reserve(col);
		for (int j = 0; j < col; ++j) {
			int num;
			scanf_s("%d", &num);
			table[i].push_back(num);
		}
	}
	printf("%d\n", calcMinResult(table, row, col));
}