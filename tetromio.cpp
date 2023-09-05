#include <iostream>
#include <vector>


int checkTwoMulThreeMat(std::vector<std::vector<int>>& table, int rstart, int cstart) {
	int bar = table[rstart][cstart] + table[rstart + 1][cstart] + table[rstart + 2][cstart];
	int min = bar + table[rstart][cstart + 1];
	int two = bar + table[rstart+1][cstart + 1];
	min = (min < two) ? min : two;
	two = bar + table[rstart+2][cstart + 1];
	min = (min < two) ? min : two;

	bar = table[rstart][cstart+1] + table[rstart + 1][cstart+1] + table[rstart + 2][cstart+1];
	two = bar + table[rstart][cstart];
	min = (min < two) ? min : two;
	two = bar + table[rstart+1][cstart];
	min = (min < two) ? min : two;
	two = bar + table[rstart + 2][cstart];
	min = (min < two) ? min : two;

	bar = table[rstart + 1][cstart] + table[rstart + 1][cstart + 1];
	two = bar + table[rstart][cstart] + table[rstart + 2][cstart + 1];
	min = (min < two) ? min : two;
	two = bar + table[rstart][cstart + 1] + table[rstart + 2][cstart];
	min = (min < two) ? min : two;
	return min;
}

int checkThreeMulTwoMat(std::vector<std::vector<int>>& table, int rstart, int cstart) {
	int bar = table[rstart][cstart] + table[rstart][cstart+1] + table[rstart][cstart+2];
	int min = bar + table[rstart + 1][cstart];
	int two = bar + table[rstart + 1][cstart + 1];
	min = (min < two) ? min : two;
	two = bar + table[rstart + 1][cstart + 2];
	min = (min < two) ? min : two;

	bar = table[rstart + 1][cstart] + table[rstart + 1][cstart + 1] + table[rstart + 1][cstart + 2];
	two = bar + table[rstart][cstart];
	min = (min < two) ? min : two;
	two = bar + table[rstart][cstart + 1];
	min = (min < two) ? min : two;
	two = bar + table[rstart][cstart + 2];
	min = (min < two) ? min : two;

	bar = table[rstart][cstart + 1] + table[rstart + 1][cstart + 1];
	two = bar + table[rstart][cstart] + table[rstart + 1][cstart + 2];
	min = (min < two) ? min : two;
	two = bar + table[rstart+ 1][cstart] + table[rstart][cstart + 2];
	min = (min < two) ? min : two;
	return min;
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

}

int main() {
	int row;
	int col;
	scanf_s("%d %d", &row, &col);
	std::vector<std::vector<int>> table(row);


	for (int i = 0; i < row; ++i) {
		table[i].reserve(col);
		for (int j = 0; j < col; ++j) {
			scanf_s("%d", &table[i][j]);
		}
	}
}