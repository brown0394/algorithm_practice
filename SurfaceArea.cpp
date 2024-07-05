#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int testCases;
	int row, col;
	char mat[50][50];
	scanf_s("%d", &testCases);
	for (int i = 0; i < testCases; ++i) {
		scanf_s("%d %d", &row, &col);
		for (int j = 0; j < row; ++j) {
			getchar();
			scanf_s("%s", mat[j], 50);
		}
		int fc = 0, l = 0, r = 0, u = 0, d = 0;
		for (int j = 0; j < row; ++j) {
			for (int k = 0; k < col; ++k) {
				if (mat[j][k] > '0') {
					++fc;
				}
				if (!k) l += (mat[j][k] - '0');
				else if (mat[j][k] > mat[j][k - 1]) {
					l += mat[j][k] - mat[j][k - 1];
				}
				if (k == col - 1) r += (mat[j][k] - '0');
				else if (mat[j][k] > mat[j][k + 1]) {
					r += mat[j][k] - mat[j][k + 1];
				}
				if (!j) u += (mat[j][k] - '0');
				else if (mat[j][k] > mat[j - 1][k]) {
					u += mat[j][k] - mat[j - 1][k];
				}
				if (j == row - 1) d += (mat[j][k] - '0');
				else if (mat[j][k] > mat[j + 1][k]) {
					d += mat[j][k] - mat[j + 1][k];
				}
			}
		}
		fc *= 2;
		printf("%d\n", fc + r + l + d + u);
	}
	
}