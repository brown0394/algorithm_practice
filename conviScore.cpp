#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <bitset>

const int maxval = std::numeric_limits<int>().max();
std::vector<std::vector<int>> townMap;
std::vector<std::bitset<1001>> visited;
int row, col;
struct info {
	int r,c, move;
};

std::queue<info> q;

const int seq[]{ 1, 0, 1 };

int closestConviScore() {
	int minScore = maxval;
	int move;
	info inf;
	while (!q.empty()) {
		inf = q.front();
		if (townMap[inf.r][inf.c] && minScore > inf.move * townMap[inf.r][inf.c]) {
			minScore = inf.move * townMap[inf.r][inf.c];
		}
		q.pop();
		for (int k = 0; k < 2; ++k) {
			if (inf.r + seq[k] <= row && inf.c + seq[k + 1] <= col &&
				!visited[inf.r + seq[k]][inf.c + seq[k + 1]]) {
				visited[inf.r + seq[k]][inf.c + seq[k + 1]] = true;
				q.push({ inf.r + seq[k], inf.c + seq[k + 1], inf.move + 1 });
			}
			if (inf.r - seq[k] >= 0 && inf.c - seq[k + 1] >= 0 && 
				!visited[inf.r - seq[k]][inf.c - seq[k + 1]]) {
				visited[inf.r - seq[k]][inf.c - seq[k + 1]] = true;
				q.push({ inf.r - seq[k], inf.c - seq[k + 1], inf.move + 1 });
			}
		}
	}
	return minScore;
}

int main() {
	int roomN, conviN;
	scanf_s("%d %d %d %d", &row, &col, &roomN, &conviN);
	townMap.resize(row + 1, std::vector<int> (col + 1, 0));
	visited.resize(row + 1);
	for (int i = 0; i < roomN; ++i) {
		int r, c;
		scanf_s("%d %d", &r, &c);
		scanf_s("%d", &townMap[r][c]);
	}
	for (int i = 0; i < conviN; ++i) {
		int r, c;
		scanf_s("%d %d", &r, &c);
		q.push({ r, c, 0 });
		visited[r][c] = true;
	}
	printf("%d\n", closestConviScore());
}