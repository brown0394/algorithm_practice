#include <iostream>
#include <vector>

struct coord {
	int r, c;
};
std::vector<std::vector<int>> chessBoard;
std::vector<std::vector<std::vector<coord>>> diagonalLinks;
int size;
int getMaxBishopCalc(int r, int c, int put);
int putBishop(int r, int c, int put);

int getMaxBishopCalc(int r, int c, int put) {
	int j = c + 1;
	int max = 0;
	for (int i = r; i < size; ++i) {
		for (; j < size; ++j) {
			if (chessBoard[i][j] == 1) {
				int result = putBishop(i, j, put);
				if (result > max) max = result;
			}
		}
		j = 0;
	}
	if (max < put) return put;
	return max;
}

void inline putStateDiagonal(int r, int c, int p) {
	for (const coord& cd : diagonalLinks[r][c]) {
		chessBoard[cd.r][cd.c] += p;
	}
}

int putBishop(int r, int c, int put) {
	++chessBoard[r][c];
	putStateDiagonal(r, c, 1);
	int result1 = getMaxBishopCalc(r, c, put + 1);
	--chessBoard[r][c];
	putStateDiagonal(r, c, -1);
	int result2 = getMaxBishopCalc(r, c, put);
	if (result1 >= result2 && result1 >= put) return result1;
	else if (result2 > result1 && result2 >= put) return result2;
	return put;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	std::cin >> size;
	chessBoard.resize(size, std::vector<int>(size));
	diagonalLinks.resize(size, std::vector<std::vector<coord>>(size));
	coord first{ -1,-1 };
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cin >> chessBoard[i][j];
			if (!chessBoard[i][j]) continue;
			if (first.r < 0) {
				first.r = i; first.c = j;
			}
			int left = j - 1;
			int right = j + 1;
			int row = i-1;
			while (row >= 0) {
				if (left >= 0) {
					if (chessBoard[row][left]) {
						diagonalLinks[row][left].push_back({ i, j });
					}
					--left;
				}
				if (right < size) {
					if (chessBoard[row][right]) {
						diagonalLinks[row][right].push_back({ i, j });
					}
					++right;
				}
				--row;
			}
		}
	}
	std::cout << putBishop(first.r, first.c, 0) << '\n';
}