#include <iostream>
#include <vector>

class ladderGame {
private:
	int row;
	int col;
	std::vector<std::vector<int>> ladders;
	std::vector<int> laddersDest;
	void updateDests();
	bool areDestsAsIntended();
public:
	ladderGame(int p_row, int p_col) : row(p_row), col(p_col),
		ladders(p_row + 1, std::vector<int>(p_col + 1)),
		laddersDest(p_col + 1) {}
	void addLadderEdges(int row, int col);
	int getHowManyPathNeeded();
};

void ladderGame::addLadderEdges(int row, int col) {
	ladders[row][col] = col + 1;
	ladders[row][col + 1] = col;
}

void ladderGame::updateDests() {
	for (int j = 1; j <= col; ++j) {
		if (ladders[1][laddersDest[j]]) {
			laddersDest[j] = ladders[1][laddersDest[j]];
		}
		else laddersDest[j] = j;
	}
	for (int i = 2; i <= row; ++i) {
		for (int j = 1; j <= col; ++j) {
			if (ladders[i][laddersDest[j]]) {
				laddersDest[j] = ladders[i][laddersDest[j]];
			}
		}
	}
}

bool ladderGame::areDestsAsIntended() {
	for (int i = 1; i <= col; ++i) {
		if (i != laddersDest[i]) return false;
	}
	return true;
}

int ladderGame::getHowManyPathNeeded() {
	int paths = 0;
	updateDests();
	while (areDestsAsIntended()) {
		//dfs
	}

	return paths;
}

int main() {
	int row, col, edges;
	scanf_s("%d %d %d", &col, &edges, &row);
	ladderGame ladder(row, col);
	for (int i = 0; i < edges; ++i) {
		scanf_s("%d %d", &row, &col);
		ladder.addLadderEdges(row, col);
	}
	
}
