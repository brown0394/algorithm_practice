#include <iostream>
#include <vector>
#include <bitset>

int main() {
	int row, col;
	scanf("%d %d", &row, &col);

	std::vector<std::bitset<51>> matA(row);
	std::vector<std::bitset<51>> matB(row);
	std::bitset<51> flipper;
	char in;
	for (int i = 0; i < row; ++i) {
		getchar();
		for (int j = 0; j < col; ++j) {
			scanf("%c", &in);
			if (in == '1') matA[i][j] = true;
		}
	}
	for (int i = 0; i < row; ++i) {
		getchar();
		for (int j = 0; j < col; ++j) {
			scanf("%c", &in);
			if (in == '1') matB[i][j] = true;
		}
	}
	int count = 0;
	for (int i = 0; i < row - 2; ++i) {
		for (int j = 0; j < col - 2; ++j) {
			if (matA[i][j] != matB[i][j]) {
				flipper = 7;
				flipper <<= j;
				matA[i] ^= flipper;
				matA[i + 1] ^= flipper;
				matA[i + 2] ^= flipper;
				++count;
			}
		}
	}
	for (int i = 0; i < row; ++i) {
		if (matA[i] != matB[i]) {
			count = -1;
			break;
		}
	}
	printf("%d\n", count);
}
