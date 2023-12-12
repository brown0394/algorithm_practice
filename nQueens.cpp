#include <iostream>
#include <vector>
#include <stack>

struct node {
	int row;
	int col;
};

class ChessBoard {
private: 
	std::vector<int> colQueenPlaced;
	std::stack<node> stk;
	int queens;
	bool checkPromising(int row, int col);
public:
	ChessBoard(int p_queens);
	int calcPossibleLocations();
};

ChessBoard::ChessBoard(int p_queens): colQueenPlaced(p_queens + 1), queens(p_queens) {
}

bool ChessBoard::checkPromising(int row, int col) {
	for (int i = 1; i < row; ++i) {
		if (col == colQueenPlaced[i] || abs(i - row) == abs(colQueenPlaced[i] - col)) {
			return false;
		}
	}
	return true;
}

int ChessBoard::calcPossibleLocations() {
	stk.push(node{ 1, 1 });
	int locs = 0;
	while (!stk.empty()) {
		if (stk.top().col > queens) {
			stk.pop();
		}
		else {
			int i = stk.top().col;
			int row = stk.top().row;
			if (row < queens) {
				for (; i <= queens; ++i) {
					if (checkPromising(row, i)) {
						colQueenPlaced[row] = i;
						stk.top().col = i + 1;
						stk.push(node{ row + 1, 1 });
						break;
					}
				}
				if (i > queens) {
					stk.pop();
				}
			}
			else {
				for (; i <= queens; ++i) {
					if (checkPromising(row, i)) {
						++locs;
						break;
					}
				}
				stk.pop();
			}
		}
	}
	return locs;
}

int main() {
	int queens;
	scanf_s("%d", &queens);
	ChessBoard board(queens);
	printf("%d\n", board.calcPossibleLocations());
}