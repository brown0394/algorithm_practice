#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

const int row = 5;
const int col = 5;
std::vector<std::vector<std::bitset<col>>> maze(row, std::vector<std::bitset<col>>(row));
std::vector<int> indexes{ 0, 1, 2, 3, 4 };
std::vector<std::vector<int>> entry(row);

struct rc {
	int r, c;
};

struct node {
	int i, j, k;
	int move;
};

void convertSpin(int from, int to, rc& coord) {
	if (from == to) return;
	int t;
	switch (from) {
	case 0: { break; }
	case 1: {

		break;
	}
	case 2: {

		break;
	}
	case 3: {
		
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

		break;
	}
	}
}

int bfs(int s1, int s2, int s3, int s4, int s5) {
	std::vector<std::vector<std::bitset<col>>> visit(maze);


}

int findPath() {
	if (entry[indexes[0]].empty() && entry[indexes[4]].empty()) return 0;
	for (auto first = entry[0].begin(), fend = entry[0].end(); first != fend; ++first) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 4; ++j) {
				for (int k = 0; k < 4; ++k) {
					for (auto last = entry[4].begin(), lend = entry[4].end(); last != lend; ++last) {
						bfs(*first, i, j, k, *last);
					}
				}
			}
		}
	}
}

int main() {
	int in;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			for (int k = 0; k < 5; ++k) {
				scanf_s("%d", &in);
				maze[i][j][k] = (in == 1);
			}
		}
	}
	for (int i = 0; i < 5; ++i) {
		if (maze[i][0][0]) entry[i].push_back(0);
		if (maze[i][0][4]) entry[i].push_back(1); 
		if (maze[i][4][4]) entry[i].push_back(2);
		if (maze[i][4][0]) entry[i].push_back(3);
		
	}
	int a = 10;
	do {
		for (int i = 0; i < 5; ++i) {
			printf("%d ", indexes[i]);
		}
		putchar('\n');
	} while (std::next_permutation(indexes.begin(), indexes.end()));
}