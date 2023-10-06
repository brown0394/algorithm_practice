#include <iostream>

int main() {
	int row, col, n;
	scanf_s("%d %d %d", &n, &row, &col);
	int table = 2 << n;
	int count = 0;
	int half = table;
	int  lim = table;
	int rowBase = 0;
	int colBase = 0;
	while (true) {
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
		if (row < (rowBase + lim) && (colBase + half)) {
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
}