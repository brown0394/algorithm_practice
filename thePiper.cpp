#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> floorMap;
std::vector<std::vector<int>> visit;
const int EMPTY = 0;
const int SEARCHING = 1;
const int DONE = 2;
int safeZones = 0;

void findDest(int i, int j) {
	if (visit[i][j] == DONE) {
		return;
	}
	else if (visit[i][j] == SEARCHING) {
		++safeZones;
		return;
	}
	visit[i][j] = SEARCHING;
	switch (floorMap[i][j]) {
	case 'U': { findDest(i - 1, j); break; }
	case 'D': { findDest(i + 1, j); break; }
	case 'L': { findDest(i, j - 1); break; }
	case 'R': { findDest(i, j + 1); break; }
	}
	visit[i][j] = DONE;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int row, col;
	std::cin >> row >> col;
	floorMap.resize(row);
	visit.resize(row, std::vector<int>(col, EMPTY));
	for (int i = 0; i < row; ++i) std::cin >> floorMap[i];
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			if (visit[i][j] == EMPTY) {
				findDest(i, j);
			}
		}
	}
	std::cout << safeZones << '\n';
}