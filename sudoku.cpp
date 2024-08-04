#include <iostream>
#include <vector>
#include <bitset>
std::vector<std::bitset<10>> horizontal(9);
std::vector<std::bitset<10>> vertical(9);
std::vector<std::vector<std::bitset<10>>> block(3, std::vector<std::bitset<10>>(3));
std::vector<std::vector<int>> puzzle(9, std::vector<int>(9));

void getEmptyLoc(int& i, int& j) {
	for (; i < 9; ++i) {
		for (; j < 9; ++j) {
			if (!puzzle[i][j]) return;
		}
		j = 0;
	}
}

bool tryCase(int i, int j) {
	getEmptyLoc(i, j);
	if (i >= 9) return true;
	for (int k = 1; k <= 9; ++k) {
		if (!horizontal[i][k] && !vertical[j][k] && !block[i / 3][j / 3][k]) {
			horizontal[i][k] = true;
			vertical[j][k] = true;
			block[i/3][j/3][k] = true;
			if (tryCase(i, j + 1)) {
				puzzle[i][j] = k;
				return true;
			}
			horizontal[i][k] = false;
			vertical[j][k] = false;
			block[i/3][j/3][k] = false;
		}
	}
	return false;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			char num;
			std::cin.get(num);
			puzzle[i][j] = num - '0';
			if (puzzle[i][j]) {
				horizontal[i][puzzle[i][j]] = true;
				vertical[j][puzzle[i][j]] = true;
				block[i / 3][j / 3][puzzle[i][j]] = true;
			}
		}
		std::cin.get();
	}
	tryCase(0, 0);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			std::cout << puzzle[i][j];
		}
		std::cout << '\n';
	}
}