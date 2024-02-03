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
	int laddersDiff;
	std::vector<std::bitset<280>> ladders;
	std::vector<int> laddersDest;
	void updateDests();
	void updateDests(int i, int j);
	void revertChange();
	void print();
	bool putLadder(int i, int j, int depth);
	std::stack<node> stk;
public:
	ladderGame(int p_row, int p_col) : row(p_row), col(p_col),
		ladders(p_row + 1),	laddersDest(p_col + 1) {
	}
	inline void addLadderEdges(int edges);
	int getHowManyPathNeeded();
};

void ladderGame::addLadderEdges(int edges) {
	int r, c;
	for (int i = 0; i < edges; ++i) {
		scanf("%d %d", &r, &c);
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
	for (int k = i - 1; k >= 1; --k) {
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

bool ladderGame::putLadder(int i, int j, int depth) {
	if (j >= col) {
		j = 1;
		++i;
	}
	bool exit = false;
	for (int k = i; k <= row; ++k) {
		for (int l = j; l < col; ++l) {
			j = 1;
			while (ladders[k][l - 1] || ladders[k][l] || ladders[k][l + 1]) {
				++l;
				if (l == col) {
					l = 1;
					++k;
					if (k > row) return false;
				}
			}
			ladders[k][l] = true;
			updateDests();
			if (!laddersDiff) {
				//print();
				//printf("\n%d\n", depth + 1);
				exit = true;
			}
			else if (depth < laddersPut) exit = putLadder(k, l, depth + 1);
			ladders[k][l] = false;
			//revertChange();
			if (exit) return true;
		}
	}
	return false;
}

int ladderGame::getHowManyPathNeeded() {
	updateDests();
	if (laddersDiff) {
		laddersPut = 0;
		while (laddersPut <= 2) {
			//print();
			if (putLadder(1, 1, 0)) break;
			++laddersPut;
		}
	}
	else return 0;
	if (laddersPut > 2) return -1;
	return laddersPut + 1;
}

int main() {
	int row, col, edges;
	scanf("%d %d %d", &col, &edges, &row);
	ladderGame ladder(row, col);
	ladder.addLadderEdges(edges);
	printf("%d\n", ladder.getHowManyPathNeeded());
}
