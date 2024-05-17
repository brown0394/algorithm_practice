#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

#define INF 2000000000

std::vector<std::vector<int>> maze;
int row, col;
int min;
std::vector<std::bitset<1005>> visited;
struct node {
	int i, j;
};

struct move {
	int i, j, count;
};

void spreadFire(std::queue<node> q) {
	int i, j;
	while (!q.empty()) {
		i = q.front().i;
		j = q.front().j;
		q.pop();
		if (i + 1 < row && maze[i + 1][j] > maze[i][j] + 1) {
			maze[i + 1][j] = maze[i][j] + 1;
			q.push({ i + 1, j });
		}
		if (i && maze[i - 1][j] > maze[i][j] + 1) {
			maze[i - 1][j] = maze[i][j] + 1;
			q.push({ i - 1, j });
		}
		if (j + 1 < row && maze[i][j + 1] > maze[i][j] + 1) {
			maze[i][j + 1] = maze[i][j] + 1;
			q.push({ i, j + 1});
		}
		if (j && maze[i][j - 1] > maze[i][j] + 1) {
			maze[i][j - 1] = maze[i][j] + 1;
			q.push({ i, j - 1 });
		}
	}
}

void findWayOut(node& initial) {
	std::queue<move> q;
	q.push({ initial.i, initial.j, 0 });
	int i, j, count;
	while (!q.empty()) {
		i = q.front().i;
		j = q.front().j;
		count = q.front().count + 1;
		q.pop();
		if (i == 0 || i == (row - 1) || j == 0 || j == (col - 1)) {
			min = count;
			break;
		}
		if (maze[i + 1][j] > count && !visited[i + 1][j]) {
			visited[i + 1][j] = true;
			q.push({ i + 1, j, count });
		}
		if (maze[i - 1][j] > count && !visited[i - 1][j]) {
			visited[i - 1][j] = true;
			q.push({ i - 1, j, count });
		}		
		if (maze[i][j + 1] > count && !visited[i][j + 1]) {
			visited[i][j + 1] = true;
			q.push({ i, j + 1, count });
		}		
		if (maze[i][j - 1] > count && !visited[i][j - 1]) {
			visited[i][j - 1] = true;
			q.push({ i, j - 1, count });
		}
	}

}

int main() {
	scanf_s("%d %d", &row, &col);
	maze.resize(row, std::vector<int>(col, INF));
	visited.resize(row);
	std::queue<node> q;
	char in;
	node initialPos;
	min = INF;
	for (int i = 0; i < row; ++i) {
		getchar();
		for (int j = 0; j < col; ++j) {
			scanf_s("%c", &in);
			if (in == '#') maze[i][j] = 0;
			else if (in == 'F') {
				maze[i][j] = 0;
				q.push({ i, j });
			}
			else if (in == 'J') {
				initialPos.i = i;
				initialPos.j = j;
			}
		}
	}
	spreadFire(q);
	findWayOut(initialPos);
	if (min == INF) printf("IMPOSSIBLE\n");
	else printf("%d\n", min);
}