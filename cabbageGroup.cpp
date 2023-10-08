#include <iostream>
#include <vector>
#include <queue>

struct cabbage {
	int x;
	int y;
};

void solve() {
	int row, col, locs;
	scanf_s("%d %d %d", &col, &row, &locs);
	std::vector<std::vector<bool>>field (row, std::vector<bool>(col, false));
	std::vector<cabbage> cabbages(locs);
	for (int i = 0; i < locs; ++i) {
		scanf_s("%d %d", &cabbages[i].x, &cabbages[i].y);
		field[cabbages[i].y][cabbages[i].x] = true;
	}
	std::queue<cabbage> q;
	int x, y;
	int count = 0;
	for (int i = 0; i < locs; ++i) {
		if (field[cabbages[i].y][cabbages[i].x]) {
			field[cabbages[i].y][cabbages[i].x] = false;
			q.push(cabbages[i]);
			++count;
			while (!q.empty()) {
				x = q.front().x;
				y = q.front().y;
				q.pop();
				if (x + 1 < col && field[y][x + 1]) {
					field[y][x + 1] = false;
					q.push({ x + 1, y });
				}
				if (x - 1 >= 0 && field[y][x - 1]) {
					q.push({ x - 1, y });
					field[y][x - 1] = false;
				}
				if (y + 1 < row && field[y + 1][x]) {
					q.push({ x, y + 1});
					field[y + 1][x] = false;
				}
				if (y - 1 >= 0 && field[y - 1][x]) {
					q.push({ x, y - 1 });
					field[y - 1][x] = false;
				}
			}


		}
	}
	printf("%d\n", count);
}

int main() {
	int N;
	scanf_s("%d", &N);
	for (int i = 0; i < N; ++i) {
		solve();
	}
}