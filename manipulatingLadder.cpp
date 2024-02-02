#include <iostream>
#include <vector>
#include <bitset>
#include <stack>

struct node {
	int diffScore;
	int start1;
	int start2;
	int dest1;
	int dest2;
};

class ladderGame {
private:
	int row;
	int col;
	int laddersPut;
	int max;
	int laddersDiff;
	std::vector<std::bitset<280>> ladders;
	std::vector<int> laddersDest;
	void updateDests();
	void updateDests(int i, int j);
	void revertChange();
	void print();
	void putLadder(int i, int j, int depth);
	std::stack<node> stk;
public:
	ladderGame(int p_row, int p_col) : row(p_row), col(p_col),
		ladders(p_row + 1),	laddersDest(p_col + 1), max(~(1 << 31)) {
		laddersPut = max;
	}
	inline void addLadderEdges(int edges);
	int getHowManyPathNeeded();
};

void ladderGame::addLadderEdges(int edges) {
	int r, c;
	for (int i = 0; i < edges; ++i) {
		scanf_s("%d %d", &r, &c);
		ladders[r][c] = true;
	}
}

void ladderGame::print() {
	printf("\n");
	for (int i = 1; i <= row; ++i) {
		for (int j = 1; j <= col; ++j) {
			if (ladders[i][j]) printf("%d-", j);
			else printf("%d ", j);
		}
		printf("\n");
	}
}

void ladderGame::updateDests() {
	for (int j = 1; j <= col; ++j) {
		if (ladders[1][j]) laddersDest[j] = j + 1;
		else if (ladders[1][j-1]) laddersDest[j] = j - 1;
		else laddersDest[j] = j;
	}
	for (int i = 2; i <= row; ++i) {
		for (int j = 1; j <= col; ++j) {
			if (ladders[i][laddersDest[j]]) {
				++laddersDest[j];
			}
			else if (ladders[i][laddersDest[j] - 1]) {
				--laddersDest[j];
			}
		}
	}
	laddersDiff = 0;
	for (int i = 1; i <= col; ++i) {
		if (laddersDest[i] != i) laddersDiff += i;
	}
}

void ladderGame::updateDests(int i, int j) {
	int cur1 = j + 1;
	int cur2 = j;
	for (int k = i + 1; k <= row; ++k) {
		if (ladders[k][cur1]) ++cur1;
		else if (ladders[k][cur1 - 1]) --cur1;
		if (ladders[k][cur2]) ++cur2;
		else if (ladders[k][cur2 - 1]) --cur2;
	}
	int start1 = j;
	int start2 = j + 1;
	for (int k = i - 1; k >= 0; --k) {
		if (ladders[k][start1]) ++start1;
		else if (ladders[k][start1 - 1]) --start1;
		if (ladders[k][start2]) ++start2;
		else if (ladders[k][start2 - 1]) --start2;
	}
	stk.push({ laddersDiff, start1, start2, laddersDest[start1], laddersDest[start2] });
	if (laddersDest[start1] != cur1) {
		if (cur1 == start1) laddersDiff -= start1;
		else if (laddersDest[start1] == start1) laddersDiff += start1;
		laddersDest[start1] = cur1;
	}
	if (laddersDest[start2] != cur2) {
		if (cur2 == start2) laddersDiff -= start2;
		else if (laddersDest[start2] == start2) laddersDiff += start2;
		laddersDest[start2] = cur2;
	}
}

void ladderGame::revertChange() {
	laddersDiff = stk.top().diffScore;
	laddersDest[stk.top().start1] = stk.top().dest1;
	laddersDest[stk.top().start2] = stk.top().dest2;
	stk.pop();
}

void ladderGame::putLadder(int i, int j, int depth) {
	if (j == col) {
		j = 1;
		++i;
	}
	for (int k = i; k <= row; ++k) {
		for (int l = j; l < col; ++l) {
			while (ladders[k][l - 1] || ladders[k][l]) {
				++l;
				if (l == col) {
					l = 1;
					++k;
					if (k > row) return;
				}
			}
			ladders[k][l] = true;
			updateDests(k, l);
			if (!laddersDiff) {
				print();
				printf("\n%d\n", depth + 1);
				laddersPut = depth + 1;
			}
			else if (depth < laddersPut - 1) putLadder(k, l + 2, depth + 1);
			ladders[k][l] = false;
			revertChange();
		}
	}
}

int ladderGame::getHowManyPathNeeded() {
	print();
	updateDests();
	if (laddersDiff) {
		putLadder(1, 1, 0);
	}
	else return 0;
	if (laddersPut == max) return -1;
	return laddersPut;
}

int main() {
	int row, col, edges;
	scanf_s("%d %d %d", &col, &edges, &row);
	ladderGame ladder(row, col);
	ladder.addLadderEdges(edges);
	printf("%d\n", ladder.getHowManyPathNeeded());
}
