#include <iostream>

int main() {
	int height, width, row, col;
	scanf_s("%d %d %d %d", &row, &col, &height, &width);
	int horizontal = (col / (width + 1));
	if (col % (width + 1)) ++horizontal;
	int vertical = (row / (height + 1));
	if (row % (height + 1)) ++vertical;
	printf("%d\n", horizontal * vertical);
}
