#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <queue>

const int row = 5;
const int col = 5;
std::vector<std::vector<std::bitset<col>>> maze(row, std::vector<std::bitset<col>>(row));
std::vector<int> indexes{ 0, 1, 2, 3, 4 };
std::vector<std::vector<int>> entry(row);
std::vector<int> spin(5);
const int fail = 5 * 5 * 5 + 10;

struct rc {
	int r, c;
};

struct node {
	int i, j, k;
	int move;
};

std::vector<rc> exits{ {4, 4}, {0, 4}, {0, 0}, {4, 0} };

void convertSpin(int from, int to, rc& coord) {
	if (from == to) return;
	int t;
	switch (from) {
	case 0: { break; }
	case 1: {
		t = coord.c;
		coord.c = 4 - coord.r;
		coord.r = t;
		break;
	}
	case 2: {
		coord.r = 4 - coord.r;
		coord.c = 4 - coord.c;
		break;
	}
	case 3: {
		t = coord.r;
		coord.r = 4 - coord.c;
		coord.c = t;
		break;
	}
	}
	switch (to) {
	case 0: { break; }
	case 1: {
		t = coord.c;
		coord.c = coord.r;
		coord.r = 4 - t;
		break;
	}
	case 2: {
		coord.r = 4 - coord.r;
		coord.c = 4 - coord.c;
		break;
	}
	case 3: {
		t = 4 - coord.r;
		coord.r = coord.c;
		coord.c = t;
		break;
	}
	}
}

const int seq[]{1, 0, 0, 1, 0, 0, 1, -1, 0, 0, -1, 0, 0, -1 };

int bfs() {
	std::vector<std::vector<std::bitset<col>>> visit(maze);
	rc cur{0, 0};
	convertSpin(0, spin[0], cur);
	std::queue<node> q;
	q.push({ 0, cur.r, cur.c, 0 });
	visit[indexes[0]][cur.r][cur.c] = false;
	node n;
	while (!q.empty()) {
		n = q.front();
		q.pop();
		for (int i = 0; i < 14; i += 2) {
			if (i == 6) {
				++i;
			}
			if (n.i + seq[i] < row && n.j + seq[i + 1] < row && n.k + seq[i + 2] < row &&
				n.i + seq[i] >= 0 && n.j + seq[i + 1] >= 0 && n.k + seq[i + 2] >= 0) {
				if (seq[i]) {
					cur.r = n.j;
					cur.c = n.k;
					convertSpin(spin[n.i], spin[n.i + seq[i]], cur);
					if (visit[indexes[n.i + seq[i]]][cur.r][cur.c]) {
						if (n.i + seq[i] == 4) {
							if (exits[spin[4]].r == cur.r && exits[spin[4]].c == cur.c)
								return n.move + 1;
						}
						visit[indexes[n.i + seq[i]]][cur.r][cur.c] = false;
						q.push({ n.i + seq[i], cur.r, cur.c, n.move + 1 });
					}
				}
				else if (visit[indexes[n.i + seq[i]]][n.j + seq[i + 1]][n.k + seq[i + 2]]) {
					if (n.i == 4) {
						if (exits[spin[4]].r == n.j + seq[i + 1] && exits[spin[4]].c == n.k + seq[i + 2])
							return n.move + 1;
					}
					visit[indexes[n.i + seq[i]]][n.j + seq[i + 1]][n.k + seq[i + 2]] = false;
					q.push({ n.i, n.j + seq[i + 1], n.k + seq[i + 2], n.move + 1 });
				}
			}
		}
	}
	return fail;
}

int findPath() {
	int min = fail;
	if (entry[indexes[0]].empty() || entry[indexes[4]].empty()) return fail;
	for (auto first = entry[indexes[0]].begin(), fend = entry[indexes[0]].end(); first != fend; ++first) {
		spin[0] = *first;
		for (int i = 0; i < 4; ++i) {
			spin[1] = i;
			for (int j = 0; j < 4; ++j) {
				spin[2] = j;
				for (int k = 0; k < 4; ++k) {
					spin[3] = k;
					for (auto last = entry[indexes[4]].begin(), lend = entry[indexes[4]].end(); last != lend; ++last) {
						spin[4] = (*last + 2) % 4;
						int result = bfs();
						if (result < min) {
							min = result;
							if (min == 12) return min;
						}
					}
				}
			}
		}
	}
	return min;
}

void print(int idx, int from, int to) {
	rc cur{ 0, 0 };
	putchar('\n');
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cur.r = i;
			cur.c = j;
			convertSpin(0, from, cur);
			if (maze[idx][cur.r][cur.c]) printf("1 ");
			else printf("0 ");
		}
		putchar('\n');
	}
	putchar('\n');
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cur.r = i;
			cur.c = j;
			convertSpin(0, from, cur);
			convertSpin(from, to, cur);
			if (maze[idx][cur.r][cur.c]) printf("1 ");
			else printf("0 ");
		}
		putchar('\n');
	}
	putchar('\n');
}

int main() {
	int in;
	int min = fail;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < 5; ++k) {
				scanf_s("%d", &in);
				maze[i][j][k] = (in == 1);
			}
		}
	}
	//print(3, 0, 2);
	int result;
	for (int i = 0; i < 5; ++i) {
		if (maze[i][0][0]) entry[i].push_back(0);
		if (maze[i][4][0]) entry[i].push_back(1); 
		if (maze[i][4][4]) entry[i].push_back(2);
		if (maze[i][0][4]) entry[i].push_back(3);
	}
	do {
		result = findPath();
		if (result < min) {
			min = result;
			if (min == 12) break;
		}
	} while (std::next_permutation(indexes.begin(), indexes.end()));
	if (min == fail) printf("-1\n");
	else printf("%d\n", min);
}