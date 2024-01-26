#include <iostream>
#include <vector>

struct node {
	int row;
	int col;
};

int getDist(int i, int j) {
	if (i < 0) i *= -1;
	if (j < 0) j *= -1;
	int count = 0;
	while (i && j) {
		++count;
		--i;
		--j;
	}
	return count + i + j;
}

int main() {
	int row, col;
	scanf_s("%d %d", &row, &col);
	std::vector<std::vector<int>> ocean(row, std::vector<int>(col));
	std::vector<node> sharks;

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			scanf_s("%d", &ocean[i][j]);
			if (ocean[i][j]) sharks.push_back({ i, j });
		}
	}
	int minDist, dist;
	int maxSafeDist = 0;
	const int max = row + col;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (!ocean[i][j]) {
				minDist = max;
				for (auto it = sharks.begin(); it != sharks.end(); ++it) {
					dist = getDist(i - it->row, j - it->col);
					if (dist < minDist) minDist = dist;
				}
				if (minDist > maxSafeDist) maxSafeDist = minDist;
			}
		}
	}
	printf("%d\n", maxSafeDist);
}
