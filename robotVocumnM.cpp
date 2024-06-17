#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

std::vector<std::bitset<20>> visited(20, 0);
std::vector<std::bitset<20>> vMap(20, 0);
std::vector<std::vector<char>> room(20, std::vector<char>(20, 0));

struct node {
	int r, c, move;
};
int row, col;
const int seq[]{ 1, 0, 1 };

void refreshVisited() {
	for (int i = 0; i < row; ++i) {
		visited[i] = vMap[i];
	}
}

void printMap() {
	printf("\n");
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			printf("%c", room[i][j]);
		}
		printf("\n");
	}
}

int searchClosestDust(node startP, int dusts) {
	printMap();
	if (!dusts) return startP.move;
	std::queue<node> q;
	q.push(startP);
	refreshVisited();
	visited[startP.r][startP.c] = true;
	while (!q.empty()) {
		node cur(q.front());
		q.pop();
		for (int i = 0; i < 2; ++i) {
			if (cur.r + seq[i] < row && cur.c + seq[i + 1] < col) {
				if (!visited[cur.r + seq[i]][cur.c + seq[i + 1]]) {
					if (room[cur.r + seq[i]][cur.c + seq[i + 1]] == '*') {
						room[cur.r + seq[i]][cur.c + seq[i + 1]] = '.';
						return searchClosestDust({ cur.r + seq[i],  cur.c + seq[i + 1] , cur.move + 1 }, dusts - 1);
					}
					visited[cur.r + seq[i]][cur.c + seq[i + 1]] = true;
					q.push({ cur.r + seq[i],  cur.c + seq[i + 1] , cur.move + 1 });
				}
			}
			if (cur.r - seq[i] >= 0 && cur.c - seq[i + 1] >= 0) {
				if (!visited[cur.r - seq[i]][cur.c - seq[i + 1]]) {
					if (room[cur.r - seq[i]][cur.c - seq[i + 1]] == '*') {
						room[cur.r - seq[i]][cur.c - seq[i + 1]] = '.';
						return searchClosestDust({ cur.r - seq[i],  cur.c - seq[i + 1] , cur.move + 1 }, dusts - 1);
					}
					visited[cur.r - seq[i]][cur.c - seq[i + 1]] = true;
					q.push({ cur.r - seq[i],  cur.c - seq[i + 1] , cur.move + 1 });
				}
			}
		}
	}
	return -1;
}

int main() {
	node startP;
	while (true) {
		scanf_s("%d %d", &col, &row);
		if (!row && !col) break;
		int dusts = 0;
		for (int i = 0; i < row; ++i) {
			getchar();
			for (int j = 0; j < col; ++j) {
				room[i][j] = getchar();
				if (room[i][j] == 'x') vMap[i][j] = true;
				else if (room[i][j] == 'o') {
					startP.r = i;
					startP.c = j;
					startP.move = 0;
				}
				else if (room[i][j] == '*') ++dusts;
			}
		}
		printf("%d\n", searchClosestDust(startP, dusts));
	}
}