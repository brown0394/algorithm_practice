#include <iostream>
#include <vector>
#include <stack>

struct node {
	int row;
	int col;
};

class ChessBoard {
private: 
	std::vector<std::vector<int>> board;
	std::stack<node> stk;
	int queens;
	void setQueenAttackableLocs(int row, int col);
	void unsetQueenAttackableLocs(int row, int col);
public:
	ChessBoard(int p_queens);
	int calcPossibleLocations();
};

ChessBoard::ChessBoard(int p_queens): board(p_queens+1, std::vector<int>(p_queens+1)), queens(p_queens) {
}

void ChessBoard::setQueenAttackableLocs(int row, int col) {
	int side = 0;
	for (int i = row; i <= queens; ++i) {
		if (!board[i][col]) board[i][col] = row;
		if (col + side <= queens && !board[i][col + side]) board[i][col + side] = row;
		if (col - side >= 0 && !board[i][col - side]) board[i][col - side] = row;
		++side;
	}
}

void ChessBoard::unsetQueenAttackableLocs(int row, int col) {
	int side = 0;
	for (int i = row; i <= queens; ++i) {
		if (board[i][col] == row) board[i][col] = 0;
		if (col + side <= queens && board[i][col + side] == row) board[i][col + side] = 0;
		if (col - side >= 0 && board[i][col - side] == row) board[i][col - side] = 0;
		++side;
	}
}

int ChessBoard::calcPossibleLocations() {
	stk.push(node{ 1, 1 });
	int locs = 0;
	while (!stk.empty()) {
		if (stk.top().col > 1) {
			unsetQueenAttackableLocs(stk.top().row, stk.top().col - 1);
		}
		if (stk.top().col > queens) {
			stk.pop();
		}
		else {
			int i = stk.top().col;
			int row = stk.top().row;
			if (row < queens) {
				for (; i <= queens; ++i) {
					if (!board[row][i]) {
						setQueenAttackableLocs(row, i);
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
					if (!board[row][i]) {
						++locs;
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