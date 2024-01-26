#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

struct node {
	int row;
	int col;
};


int main() {
	int row, col;
	scanf_s("%d %d", &col, &row);
	std::vector<std::vector<char>> battleField(row, std::vector<char>(col));
	std::vector<std::bitset<101>> visited(row);
	for (int i = 0; i < row; ++i) {
		getchar();
		for (int j = 0; j < col; ++j) {
			scanf_s("%c", &battleField[i][j]);
		}
	}
	std::queue<node> q;
	int k, l, group;
	int white = 0, blue = 0;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (!visited[i][j]) {
				q.push({ i, j });
				visited[i][j] = true;
				group = 0;
				while (!q.empty()) {
					k = q.front().row;
					l = q.front().col;
					++group;
					q.pop();
					if (k + 1 < row && !visited[k + 1][l] &&
						battleField[k + 1][l] == battleField[k][l]) {
						visited[k + 1][l] = true;
						q.push({ k + 1, l });
					}
					if (l + 1 < col && !visited[k][l + 1] &&
						battleField[k][l + 1] == battleField[k][l]) {
						visited[k][l + 1] = true;
						q.push({ k, l + 1 });
					}
					if (k && !visited[k - 1][l] &&
						battleField[k - 1][l] == battleField[k][l]) {
						visited[k - 1][l] = true;
						q.push({ k - 1, l });
					}
					if (l && !visited[k][l - 1] &&
						battleField[k][l - 1] == battleField[k][l]) {
						visited[k][l - 1] = true;
						q.push({ k, l - 1 });
					}
				}
				group *= group;
				if (battleField[i][j] == 'W') white += group;
				else blue += group;
			}
		}
	}
	printf("%d %d\n", white, blue);
}
