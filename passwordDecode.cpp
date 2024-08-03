#include <iostream>
#include <vector>
#include <string>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int row, col;
	std::cin >> col;
	std::string str;
	std::cin >> str;
	row = str.size() / col;
	std::vector<std::vector<char>> newPass(row, std::vector<char>(col));
	int curCol = 0, curRow = 0;
	bool ltoR = true;
	for (auto it = str.begin(), end = str.end(); it != end; ++it) {
		newPass[curRow][curCol] = *it;
		if (ltoR) {
			if (++curCol == col) {
				--curCol;
				++curRow;
				ltoR = false;
			}
		}
		else {
			if (--curCol < 0) {
				++curCol;
				++curRow;
				ltoR = true;
			}
		}
	}
	for (int j = 0; j < col; ++j) {
		for (int i = 0; i < row; ++i) {
			std::cout << newPass[i][j];
		}
	}
	std::cout << '\n';
}