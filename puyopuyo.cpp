#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <bitset>

#define ROW 12
#define COL 6

struct node {
	int row;
	int col;
};

std::vector<char[COL]> arr(ROW);
int firstRow = ROW;
std::queue<node> q;

bool bfs(std::vector<std::bitset<COL>>& visited, std::vector<std::bitset<COL>>&visitedInit) {
	int row, col;
	int group = 0;
	std::list<node> groupInfo;
	char comp = arr[q.front().row][q.front().col];
	while (!q.empty()) {
		row = q.front().row;
		col = q.front().col;
		q.pop();
		++group;
		if (group > 3) {
			arr[row][col] = '.';
			visitedInit[row][col] = true;
		}
		else groupInfo.push_back({ row, col });
		if (row + 1 < ROW && comp == arr[row + 1][col]
			&& !visited[row + 1][col]) {
			visited[row + 1][col] = true;
			q.push({ row + 1, col });
		}
		if (row && comp == arr[row - 1][col]
			&& !visited[row - 1][col]) {
			visited[row - 1][col] = true;
			q.push({ row - 1, col });
		}
		if (col + 1 < COL && comp == arr[row][col + 1]
			&& !visited[row][col + 1]) {
			visited[row][col + 1] = true;
			q.push({ row, col + 1 });
		}
		if (col && comp == arr[row][col - 1]
			&& !visited[row][col - 1]) {
			visited[row][col - 1] = true;
			q.push({ row, col - 1 });
		}
	}
	if (group > 3) {
		for (auto it = groupInfo.begin(); it != groupInfo.end(); ++it) {
			arr[it->row][it->col] = '.';
			visitedInit[it->row][it->col] = true;
		}
		return true;
	}
	return false;
}

void afterPop(std::vector<std::bitset<COL>>& visited, std::vector<std::bitset<COL>>& visitedInit) {
	for (int i = firstRow; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			if (arr[i][j] == '.') {
				int idx = i;
				while (idx && arr[idx - 1][j] != '.') {
					arr[idx][j] = arr[idx - 1][j];
					arr[idx - 1][j] = '.';
					visitedInit[idx][j] = visitedInit[idx - 1][j];
					visitedInit[idx - 1][j] = true;
					--idx;
				}
			}
		}
	}
	bool decrease;
	for (int i = firstRow; i < ROW; ++i) {
		visited[i] = visitedInit[i];
	}
	for (int i = firstRow; i < ROW; ++i) {
		decrease = true;
		for (int j = 0; j < COL; ++j) {
			if (arr[i][j] != '.') {
				decrease = false;
				break;
			}
		}
		if (!decrease) break;
		++firstRow;
	}
}

void print(std::vector<std::bitset<COL>>& visitedInit) {
	printf("\n");
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			if (visitedInit[i][j])
				printf(".");
			else
				printf("a");
		}
		printf("\n");
	}
}

int main() {
	std::vector<std::bitset<COL>> visited(ROW);
	
	for (int i = 0; i < ROW; ++i) {
		for (int j = 0; j < COL; ++j) {
			scanf_s("%c", &arr[i][j]);
			if (arr[i][j] == '.') visited[i][j] = true;
			else if (firstRow > i) firstRow = i;
		}
		getchar();
	}
	std::vector<std::bitset<COL>> visitedInit(visited);
	bool popped;
	int streak = 0;
	while (true) {
		popped = false;
		for (int i = firstRow; i < ROW; ++i) {
			for (int j = 0; j < COL; ++j) {
				if (!visited[i][j]) {
					visited[i][j] = true;
					q.push({ i, j });
					if (bfs(visited, visitedInit)) popped = true;
				}
			}
		}
		afterPop(visited, visitedInit);
		if (popped) ++streak;
		else break;
	}
	printf("%d\n", streak);
}
