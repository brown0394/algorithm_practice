#include <iostream>

int main() {
	int row, col;
	scanf_s("%d %d", &row, &col);

	if (row == 1) printf("1\n");
	else if (row < 3) {
		int count = 1;
		for (int i = 3; i <= 7; i += 2) {
			if (col < i) {
				printf("%d\n", count);
				return 0;
			}
			++count;
		}
		printf("4\n");
	}
	else {
		if (col < 5) printf("%d\n", col);
		else if (col < 7) printf("4\n");
		else {
			printf("%d\n", (col - 4) + 2);
		}
	}
}
