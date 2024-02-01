#include <iostream>
#include <vector>

class ladderGame {
private:
	int row;
	int col;
	int laddersPut;
	int max;
	std::vector<std::vector<int>> ladders;
	std::vector<int> laddersDest;
	void updateDests();
	void print();
	inline bool isResultAsIntended();
	void putLadder(int i, int j, int depth, int added);
public:
	ladderGame(int p_row, int p_col) : row(p_row), col(p_col),
		ladders(p_row + 1, std::vector<int>(p_col + 1)),
		laddersDest(p_col + 1), max(~(1 << 31)) {
		laddersPut = max;
	}
	inline void addLadderEdges(int row, int col);
	int getHowManyPathNeeded();
};

void ladderGame::addLadderEdges(int row, int col) {
	ladders[row][col] = col + 1;
	ladders[row][col + 1] = col;
}

void ladderGame::print() {
	printf("\n");
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= col; ++j) {
			if (ladders[i][j] > j) printf("%d-", j);
			else printf("%d ", j);
		}
		printf("\n");
	}
}

void ladderGame::updateDests() {
	for (int j = 1; j <= col; ++j) {
		if (ladders[1][j]) {
			laddersDest[j] = ladders[1][j];
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

bool ladderGame::isResultAsIntended() {
	for (int i = 1; i <= col; ++i) {
		if (laddersDest[i] != i) return false;
	}
	return true;
}

void ladderGame::putLadder(int i, int j, int depth, int added) {
	if (laddersPut - 1 <= depth) return;
	while (true) {
		while (ladders[i][j] || ladders[i][j + 1]) {
			++j;
			if (j == col) {
				j = 1;
				++i;
				if (i > row) return;
			}
		}
		addLadderEdges(i, j);
		updateDests();
		if (isResultAsIntended()) {
			//print();
			//printf("\n%d\n", depth + 1);
			laddersPut = depth + 1;
		}
		else if (added <= 2) putLadder(i, j, depth + 1, added + 1);
		ladders[i][j] = 0;
		ladders[i][j + 1] = 0;
		++j;
		if (j == col) {
			j = 1;
			++i;
			if (i > row) return;
		}
	}
}

int ladderGame::getHowManyPathNeeded() {
	//print();
	updateDests();
	if (!isResultAsIntended()) {
		putLadder(1, 1, 0, 0);
	}
	else laddersPut = 0;
	if (laddersPut == max) return -1;
	return laddersPut;
}

int main() {
	int row, col, edges;
	scanf_s("%d %d %d", &col, &edges, &row);
	ladderGame ladder(row, col);
	for (int i = 0; i < edges; ++i) {
		scanf_s("%d %d", &row, &col);
		ladder.addLadderEdges(row, col);
	}
	printf("%d\n", ladder.getHowManyPathNeeded());
}
