#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

struct node {
	int i;
	int j;
	int count;
};
int boardSize;
node knight, target;
std::vector<std::bitset<300>> board;

int tryMoves(std::queue<node>& q) {
	int i, j, count;
	while (!q.empty()) {
		i = q.front().i;
		j = q.front().j;
		count = q.front().count;
		q.pop();
		if (i) {
			if (i - 1) {
				if (j && !board[i - 2][j - 1]) {
					if (i - 2 == target.i && j - 1 == target.j) return count + 1;
					board[i - 2][j - 1] = true;
					q.push({ i - 2, j - 1, count + 1 });
				}
				if (j + 1 < boardSize && !board[i - 2][j + 1]) {
					if (i - 2 == target.i && j + 1 == target.j) return count + 1;
					board[i - 2][j + 1] = true;
					q.push({ i - 2, j + 1, count + 1 });
				}
			}
			if (j - 2 >= 0 && !board[i - 1][j - 2]) {
				if (i - 1 == target.i && j - 2 == target.j) return count + 1;
				board[i - 1][j - 2] = true;
				q.push({ i - 1, j - 2, count + 1 });
			}
			if (j + 2 < boardSize && !board[i - 1][j + 2]) {
				if (i - 1 == target.i && j + 2 == target.j) return count + 1;
				board[i - 1][j + 2] = true;
				q.push({ i - 1, j + 2, count + 1 });
			}
		}
		if (i + 1 < boardSize) {
			if (i + 2 < boardSize) {
				if (j && !board[i + 2][j - 1]) {
					if (i + 2 == target.i && j - 1 == target.j) return count + 1;
					board[i + 2][j - 1] = true;
					q.push({ i + 2, j - 1, count + 1 });
				}
				if (j + 1 < boardSize && !board[i + 2][j + 1]) {
					if (i + 2 == target.i && j + 1 == target.j) return count + 1;
					board[i + 2][j + 1] = true;
					q.push({ i + 2, j + 1, count + 1 });
				}
			}
			if (j - 2 >= 0 && !board[i + 1][j - 2]) {
				if (i + 1 == target.i && j - 2 == target.j) return count + 1;
				board[i + 1][j - 2] = true;
				q.push({ i + 1, j - 2, count + 1 });
			}
			if (j + 2 < boardSize && !board[i + 1][j + 2]) {
				if (i + 1 == target.i && j + 2 == target.j) return count + 1;
				board[i + 1][j + 2] = true;
				q.push({ i + 1, j + 2, count + 1 });
			}
		}
	}
	return 0;
}

int main() {
	int testCases;
	scanf_s("%d", &testCases);
	board.resize(300);
	for (int i = 0; i < testCases; ++i) {
		scanf_s("%d %d %d %d %d", &boardSize, &knight.i, &knight.j, &target.i, &target.j);
		std::queue<node> q;
		knight.count = 0;
		q.push(knight);
		board[knight.i][knight.j] = true;
		printf("%d\n", tryMoves(q));
		for (int i = 0; i < boardSize; ++i) {
			board[i] = 0;
		}
	}
}
