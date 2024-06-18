#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <algorithm>

std::vector<std::bitset<20>> visited(20, 0);
std::vector<std::bitset<20>> vMap(20, 0);
std::vector<std::vector<char>> room(20, std::vector<char>(20, 0));
std::vector<std::vector<int>> distances(21, std::vector<int>(21, 0));
const char startLoc = 20;
int dusts;
struct node {
	int r, c, move;
};
std::queue<node> dustLocs;
int row, col;
const int seq[]{ 1, 0, 1 };

void refreshVisited() {
	for (int i = 0; i < row; ++i) {
		visited[i] = vMap[i];
	}
}

void refreshVmap() {
	for (int i = 0; i < row; ++i) {
		vMap[i] = 0;
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

void bfs(node& start, int toFind) {
	std::queue<node> q;
	q.push(start);
	refreshVisited();
	visited[q.front().r][q.front().c] = true;
	int dustsFound = 1;
	char from = room[q.front().r][q.front().c];
	bool foundStartp = false;
	while (!q.empty()) {
		node cur(q.front());
		q.pop();
		for (int i = 0; i < 2; ++i) {
			if (cur.r + seq[i] < row && cur.c + seq[i + 1] < col) {
				if (!visited[cur.r + seq[i]][cur.c + seq[i + 1]]) {
					if (room[cur.r + seq[i]][cur.c + seq[i + 1]] <= startLoc) {
						if (room[cur.r + seq[i]][cur.c + seq[i + 1]] == startLoc) {
							foundStartp = true;
						}
						else {
							++dustsFound;
							distances[from][room[cur.r + seq[i]][cur.c + seq[i + 1]]] = cur.move + 1;
						}
						distances[room[cur.r + seq[i]][cur.c + seq[i + 1]]][from] = cur.move + 1;
						if (dustsFound == toFind && foundStartp) return;
					}
					visited[cur.r + seq[i]][cur.c + seq[i + 1]] = true;
					q.push({ cur.r + seq[i],  cur.c + seq[i + 1] , cur.move + 1 });
				}
			}
			if (cur.r - seq[i] >= 0 && cur.c - seq[i + 1] >= 0) {
				if (!visited[cur.r - seq[i]][cur.c - seq[i + 1]]) {
					if (room[cur.r - seq[i]][cur.c - seq[i + 1]] <= startLoc) {
						if (room[cur.r - seq[i]][cur.c - seq[i + 1]] == startLoc) {
							foundStartp = true;
						}
						else {
							++dustsFound;
							distances[from][room[cur.r - seq[i]][cur.c - seq[i + 1]]] = cur.move + 1;
						}
						distances[room[cur.r - seq[i]][cur.c - seq[i + 1]]][from] = cur.move + 1;
						if (dustsFound == toFind && foundStartp) return;
					}
					visited[cur.r - seq[i]][cur.c - seq[i + 1]] = true;
					q.push({ cur.r - seq[i],  cur.c - seq[i + 1] , cur.move + 1 });
				}
			}
		}
	}
}

void calcDustDists() {
	while (dustLocs.size() > 1) {
		bfs(dustLocs.front(), dusts);
		dustLocs.pop();
	}
	bfs(dustLocs.front(), 1);
	dustLocs.pop();
}

void flushDistVector() {
	for (int i = 0; i < dusts; ++i) {
		std::fill(distances[i].begin(), distances[i].begin() + dusts, 0);
	}
	std::fill(distances[20].begin(), distances[20].begin() + dusts, 0);
}

int minCostDist(node startP) {
	calcDustDists();
	int result = ~(1 << 31);
	bool valid = true;
	std::vector<int> visitSeq(dusts);
	for (int i = 0; i < dusts; ++i) {
		if (!distances[20][i]) {
			flushDistVector();
			return -1;
		}
		visitSeq[i] = i;
	}
	do {
		int last = 20;
		int dist = 0;
		for (auto it = visitSeq.begin(), end = visitSeq.end(); it != end; ++it) {
			dist += distances[last][*it];
			if (dist > result) break;
			last = *it;
		}
		if (dist < result) result = dist;
	} while (std::next_permutation(visitSeq.begin(), visitSeq.end()));
	flushDistVector();
	return result;
}

int main() {
	node startP;
	while (true) {
		char dustIdx = 0;
		scanf_s("%d %d", &col, &row);
		if (!row && !col) break;
		dusts = 0;
		for (int i = 0; i < row; ++i) {
			getchar();
			for (int j = 0; j < col; ++j) {
				room[i][j] = getchar();
				if (room[i][j] == 'x') vMap[i][j] = true;
				else if (room[i][j] == 'o') {
					room[i][j] = startLoc;
					startP.r = i;
					startP.c = j;
					startP.move = 0;
				}
				else if (room[i][j] == '*') {
					++dusts;
					dustLocs.push({ i, j, 0 });
					room[i][j] = dustIdx++;
				}
			}
		}
		printf("%d\n", minCostDist(startP));
		refreshVmap();
	}
}