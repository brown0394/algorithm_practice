#include <iostream>


int main() {
	int testCases;
	scanf_s("%d", &testCases);
	int board;

	for (int i = 1; i <= testCases; ++i) {
		if (i > 1) getchar();
		bool verticals[9][10]{ 0 };
		bool horizontals[9][10]{ 0 };
		bool blocks[3][3][10]{ 0 };
		bool valid = true;
		for (int j = 0; j < 9; ++j) {
			for (int k = 0; k < 9; ++k) {
				scanf_s("%d", &board);
				if (valid) {
					if (verticals[k][board]) valid = false;
					else verticals[k][board] = true;
					if (horizontals[j][board]) valid = false;
					else horizontals[j][board] = true;
					if (blocks[j / 3][k / 3][board]) valid = false;
					else blocks[j / 3][k / 3][board] = true;
				}
			}
		}
		printf("Case %d: ", i);
		if (!valid) printf("IN");
		printf("CORRECT\n");
	}
}