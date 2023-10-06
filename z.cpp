#include <iostream>

int main() {
	int row, col, n;
	scanf_s("%d %d %d", &n, &row, &col);
	int table = 2 << (n - 1);
	int count = 0;
	int half = table;
	int  lim = table;
	int rowBase = 0;
	int colBase = 0;
	while (lim > 1) {
		lim = half;
		half = half >> 1;
		if (row < (rowBase + half) && col < (colBase + half)) {
			continue;
		}
		if (row < (rowBase + half) && col < (colBase + lim)) {
			count += half * half;
			colBase += half;
			continue;
		}
		if (row < (rowBase + lim) && col < (colBase + half)) {
			count += half * half * 2;
			rowBase += half;
			continue;
		}
		else {
			count += half * half * 3;
			rowBase += half;
			colBase += half;
			continue;
		}

	}

	printf("%d\n", count);
}