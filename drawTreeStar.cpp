#include <iostream>
#include <vector>

void drawTriangle(std::vector<std::vector<char>>& draw, int n, int i, int j) {
	if (n == 3) {
		draw[i - 2][j + 2] = '*';
		draw[i - 1][j + 1] = draw[i - 1][j + 3] = '*';
		draw[i][j] = draw[i][j + 1] = draw[i][j + 2] = draw[i][j + 3] = draw[i][j + 4] = '*';
		return;
	}
	int next = n >> 1;
	drawTriangle(draw, next, i, j);
	drawTriangle(draw, next, i, j + n);
	drawTriangle(draw, next, i - next, j + next);
}

int main() {
	int n;
	scanf_s("%d", &n);

	std::vector<std::vector<char>> draw(n);
	for (int i = 0; i < n; ++i) {
		draw[i].resize(n + i, ' ');
	}
	drawTriangle(draw, n, n-1, 0);
	for (int i = 0; i < n; ++i) {
		for (auto it = draw[i].begin(); it != draw[i].end(); ++it) {
			printf("%c", *it);
		}
		printf("\n");
	}
}