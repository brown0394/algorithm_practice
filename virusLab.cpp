#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

struct node {
	int i;
	int j;
};

class virusMap {
private:
	int col;
	int row;
	int empty;
	int infected;
	std::vector<std::bitset<8>> visitedInit;
	std::vector<std::bitset<8>> visited;
	std::vector<node> viruses;
	std::vector<std::vector<short int>> emptySpaces;
	void putWall(int i, int j, int depth);
	void spreadVirus();
public:
	virusMap(int p_row, int p_col);
	int getSafeSpaces();
};
virusMap::virusMap(int p_row, int p_col) :col(p_col), row(p_row),
visitedInit(row, 0), visited(row, 0), emptySpaces(row) {
	int in;
	empty = 0;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			scanf_s("%d", &in);
			if (!in) {
				emptySpaces[i].push_back(j);
				++empty;
			}
			else {
				visitedInit[i][j] = true;
				if (in == 2) viruses.push_back({ i, j });
			}
		}
	}
	empty -= 3;
	infected = empty;
}

void virusMap::putWall(int i, int j, int depth) {
	if (depth) {
		for (; i < row; ++i) {
			for (; j < emptySpaces[i].size(); ++j) {
				visitedInit[i][emptySpaces[i][j]] = true;
				spreadVirus();
				visitedInit[i][emptySpaces[i][j]] = false;
			}
			j = 0;
		}
	}
	else {
		for (; i < row; ++i) {
			for (; j != emptySpaces[i].size(); ++j) {
				visitedInit[i][emptySpaces[i][j]] = true;
				putWall(i, j + 1, depth + 1);
				visitedInit[i][emptySpaces[i][j]] = false;
			}
			j = 0;
		}
	}
}

void virusMap::spreadVirus() {
	std::queue<node> q;
	int virusSpreads = 0;
	for (auto it = viruses.begin(); it != viruses.end(); ++it) {
		q.push(*it);
	}
	for (int i = 0; i < row; ++i) {
		visited[i] = visitedInit[i];
	}
	int i, j;
	while (!q.empty()) {
		i = q.front().i;
		j = q.front().j;
		q.pop();
		if (i + 1 < row && !visited[i + 1][j]) {
			visited[i + 1][j] = true;
			q.push({ i + 1, j });
			++virusSpreads;
		}
		if (i - 1 >= 0 && !visited[i - 1][j]) {
			visited[i - 1][j] = true;
			q.push({ i - 1, j });
			++virusSpreads;
		}
		if (j + 1 < col && !visited[i][j + 1]) {
			visited[i][j + 1] = true;
			q.push({ i, j + 1 });
			++virusSpreads;
		}
		if (j - 1 >= 0 && !visited[i][j - 1]) {
			visited[i][j - 1] = true;
			q.push({ i, j - 1 });
			++virusSpreads;
		}
		if (virusSpreads > infected) break;
	}
	if (virusSpreads < infected) infected = virusSpreads;

}

int virusMap::getSafeSpaces() {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < emptySpaces[i].size(); ++j) {
			visitedInit[i][emptySpaces[i][j]] = true;
			putWall(i, j + 1, 0);
			visitedInit[i][emptySpaces[i][j]] = false;
		}
	}
	return empty - infected;
}

int main() {
	int col, row;
	scanf_s("%d %d", &row, &col);
	virusMap vmp(row, col);
	printf("%d\n", vmp.getSafeSpaces());
}