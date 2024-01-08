#include <iostream>
#include <vector>
#include <cstring>

struct node {
	int i;
	int j;
	int dust;
};

class air {
private:
	int row;
	int col;
	int totalDust;
	int rowLen;
	int colLen;
	int** arr;
	std::vector<int> airPurifier;
	std::vector<node> dusts;
	void spreadDust();
	void purifyDust();
	void setDust();
	void print();
public:
	air(int p_row, int p_col);
	~air();
	int getTotalDustAtT(int time);
};

air::air(int p_row, int p_col):row(p_row), col(p_col) {
	totalDust = 0;
	dusts.reserve(row * col);
	arr = new int* [row];
	for (int i = 0; i < row; ++i) {
		arr[i] = new int[col];
		for (int j = 0; j < col; ++j) {
			scanf_s("%d", &arr[i][j]);
			if (arr[i][j] == -1) airPurifier.push_back(i);
			else {
				if (arr[i][j] >= 5) dusts.push_back({i, j, arr[i][j]});
				totalDust += arr[i][j];
			}
		}
	}
	rowLen = row - 1;
	colLen = col - 1;
}

air::~air() {
	delete[] arr;
}

void air::spreadDust() {
	int spread;
	for (auto it = dusts.begin(); it != dusts.end(); ++it) {
		spread = it->dust / 5;
		if (it->i + 1 < row && arr[it->i + 1][it->j] != -1) {
			arr[it->i + 1][it->j] += spread;
			arr[it->i][it->j] -= spread;
		}
		if (it->i - 1 >= 0 && arr[it->i - 1][it->j] != -1) {
			arr[it->i - 1][it->j] += spread;
			arr[it->i][it->j] -= spread;
		}
		if (it->j + 1 < col) {
			arr[it->i][it->j + 1] += spread;
			arr[it->i][it->j] -= spread;
		}
		if (it->j - 1 >= 0 && arr[it->i][it->j - 1] != -1) {
			arr[it->i][it->j - 1] += spread;
			arr[it->i][it->j] -= spread;
		}
	}
	dusts.clear();
}

void air::purifyDust() {
	totalDust -= (arr[airPurifier[0] - 1][0] + arr[airPurifier[1] + 1][0]);

	for (int i = airPurifier[0] - 1; i >= 1; --i) {
		arr[i][0] = arr[i - 1][0];
	}
	for (int i = airPurifier[1] + 1; i < rowLen; ++i) {
		arr[i][0] = arr[i + 1][0];
	}
	for (int i = 0; i < colLen; ++i) {
		arr[0][i] = arr[0][i + 1];
		arr[rowLen][i] = arr[rowLen][i + 1];
	}
	for (int i = 0; i < airPurifier[0]; ++i) {
		arr[i][colLen] = arr[i + 1][colLen];
	}
	for (int i = rowLen; i > airPurifier[1]; --i) {
		arr[i][colLen] = arr[i - 1][colLen];
	}
	for (int i = colLen; i > 1; --i) {
		arr[airPurifier[0]][i] = arr[airPurifier[0]][i - 1];
		arr[airPurifier[1]][i] = arr[airPurifier[1]][i - 1];
	}
	arr[airPurifier[0]][1] = 0;
	arr[airPurifier[1]][1] = 0;
}

void air::setDust() {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (arr[i][j] > 4) {
				dusts.push_back({ i, j, arr[i][j] });
			}
		}
	}
}

void air::print() {
	printf("\n\n");
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int air::getTotalDustAtT(int time) {
	for (int i = 0; i < time; ++i) {
		spreadDust();
		purifyDust();
		setDust();
	}
	return totalDust;
}

int main() {
	int row, col, time;
	scanf_s("%d %d %d", &row, &col, &time);
	air a(row, col);
	printf("%d\n", a.getTotalDustAtT(time));
}