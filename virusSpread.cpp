#include <iostream>
#include <vector>
#include <queue>
#include <list>
//https://www.acmicpc.net/problem/31791
int row, col;
int buildingSafeTime, virusSpreadTime, initialV, buildings;
std::vector<std::vector<int>> world;
std::vector<std::vector<int>> cost;
struct node {
	int i, j;
};

struct building {
	int i, j, count;
};

void spread(std::queue<node>& q) {
	int i, j;
	int seq[]{ 1, 0, 1 };
	while (!q.empty()) {
		i = q.front().i;
		j = q.front().j;
		q.pop();
		if (i + 1 < row){
			int down = world[i][j] + cost[i + 1][j];
			if (down < world[i + 1][j] && down <= virusSpreadTime) {
				world[i + 1][j] = down;
				q.push({ i + 1, j });
			}
		}
		if (i) {
			int up = world[i][j] + cost[i - 1][j];
			if (up < world[i - 1][j] && up <= virusSpreadTime) {
				world[i - 1][j] = up;
				q.push({ i - 1, j });
			}
		}
		if (j + 1 < col) {
			int right = world[i][j] + cost[i][j + 1];
			if (right < world[i][j + 1] && right <= virusSpreadTime) {
				world[i][j + 1] = right;
				q.push({ i, j + 1 });
			}
		}
		if (j) {
			int left = world[i][j] + cost[i][j - 1];
			if (left < world[i][j - 1] && left <= virusSpreadTime) {
				world[i][j - 1] = left;
				q.push({ i, j - 1 });
			}
		}
	}
}

int main() {
	scanf_s("%d %d %d %d %d %d", &row, &col, &virusSpreadTime, &buildingSafeTime, &initialV, &buildings);
	world.resize(row, std::vector<int>(col, virusSpreadTime+1));
	cost.resize(row, std::vector<int>(col, 1));
	std::queue<node> q;
	char in;
	for (int i = 0; i < row; ++i) {
		getchar();
		for (int j = 0; j < col; ++j) {
			scanf_s("%c", &in);
			if (in == '*') {
				world[i][j] = 0;
				q.push({ i, j });
			}
			else if (in == '#') cost[i][j] = buildingSafeTime + 1;
		}
	}
	spread(q);
	bool somewhereSafe = false;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (world[i][j] > virusSpreadTime) {
				somewhereSafe = true;
				printf("%d %d\n", i + 1, j + 1);
			}
		}
	}
	if (!somewhereSafe) printf("-1\n");
}