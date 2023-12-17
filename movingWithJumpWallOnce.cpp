#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

struct node {
	int i;
	int j;
	int count;
	bool canJumpAWall;
};
int main() {
	int row, col;
	scanf_s("%d %d", &row, &col);
	std::vector<std::vector<char>> map(row, std::vector<char>(col));
	std::vector<std::bitset<1000>> visited(row);
	std::vector<std::bitset<1000>> visitedAfterJump(row);
	for (int i = 0; i < row; ++i) {
		getchar();
		for (int j = 0; j < col; ++j) {
			scanf_s("%c", &map[i][j], 1);
		}
	}
	if (row == 1 && col == row) {
		printf("1\n");
	}
	else {
		std::queue<node> q;
		q.push({ 0, 0, 1, true });
		visited[0][0] = true;
		visitedAfterJump[0][0] = true;
		int count;
		bool canJumpAWall, found = false;
		int limit[2]{ row, col };
		int x[2]{ 1, 0 }, y[2]{0, 1};
		int idx[2];
		while (!q.empty() && !found) {
			idx[0] = q.front().i;
			idx[1] = q.front().j;
			count = q.front().count;
			canJumpAWall = q.front().canJumpAWall;
			q.pop();
			for (int seq = 0; seq < 2; ++seq) {
				if (idx[seq] + 1 < limit[seq]) {
					if (canJumpAWall && !visited[idx[0] + x[seq]][idx[1] + y[seq]]) {
						if (idx[0] + x[seq] == row - 1 && idx[1] + y[seq] == col - 1) {
							found = true;
							break;
						}
						visited[idx[0] + x[seq]][idx[1] + y[seq]] = true;
						if (map[idx[0] + x[seq]][idx[1] + y[seq]] == '0') q.push({ idx[0] + x[seq], idx[1] + y[seq], count + 1, canJumpAWall });
						else {
							visitedAfterJump[idx[0] + x[seq]][idx[1] + y[seq]] = true;
							q.push({ idx[0] + x[seq], idx[1] + y[seq], count + 1, false });
						}
					}
					else if (!canJumpAWall && !visitedAfterJump[idx[0] + x[seq]][idx[1] + y[seq]]) {
						if (idx[0] + x[seq] == row - 1 && idx[1] + y[seq] == col - 1) {
							found = true;
							break;
						}
						visitedAfterJump[idx[0] + x[seq]][idx[1] + y[seq]] = true;
						if (map[idx[0] + x[seq]][idx[1] + y[seq]] == '0') q.push({ idx[0] + x[seq], idx[1] + y[seq], count + 1, canJumpAWall });
					}
				}
				if (idx[seq] - 1 >= 0) {
					if (canJumpAWall && !visited[idx[0] - x[seq]][idx[1] - y[seq]]) {
						if (idx[0] - x[seq] == row - 1 && idx[1] - y[seq] == col - 1) {
							found = true;
							break;
						}
						visited[idx[0] - x[seq]][idx[1] - y[seq]] = true;
						if (map[idx[0] - x[seq]][idx[1] - y[seq]] == '0') q.push({ idx[0] - x[seq], idx[1] - y[seq], count + 1, canJumpAWall });
						else {
							visitedAfterJump[idx[0] - x[seq]][idx[1] - y[seq]] = true;
							q.push({ idx[0] - x[seq], idx[1] - y[seq], count + 1, false });
						}
					}
					else if (!canJumpAWall && !visitedAfterJump[idx[0] - x[seq]][idx[1] - y[seq]]) {
						if (idx[0] - x[seq] == row - 1 && idx[1] - y[seq] == col - 1) {
							found = true;
							break;
						}
						visitedAfterJump[idx[0] - x[seq]][idx[1] - y[seq]] = true;
						if (map[idx[0] - x[seq]][idx[1] - y[seq]] == '0') q.push({ idx[0] - x[seq], idx[1] - y[seq], count + 1, canJumpAWall });
					}
				}
			}
		}
		if (found) printf("%d\n", count + 1);
		else printf("-1\n");
	}

}