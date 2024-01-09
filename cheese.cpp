#include <iostream>
#include <vector>
#include <queue>
#include <set>

struct node {
	int i;
	int j;
};

struct cheese {
	int i;
	int j;
	bool operator < (const cheese& other)const;
	bool operator == (cheese& other) { return i == other.i && j == other.j; }

};

bool cheese::operator <(const cheese& other)const {
	if (i == other.i) return j < other.j;
	return i < other.i;
}

class cheeseRefrig {
private:
	int row, col;
	std::vector<std::vector<int>> arr;
	std::queue<node> airQ;
	std::set<cheese> cheeseSet1;
	std::set<cheese> cheeseSet2;
	std::set<cheese>* outerCheese;
	std::set<cheese>* nOuterCheese;
	void checkAir();
	void print();
public:
	cheeseRefrig(int p_row, int p_col);
	int getmeltingTime();
};

cheeseRefrig::cheeseRefrig(int p_row, int p_col):row(p_row), col(p_col), arr(row, std::vector<int>(col, 0)) {
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			scanf_s("%d", &arr[i][j]);
			if (i == 0 || i == row - 1 || j == 0 || j == col - 1) {
				arr[i][j] = 2;
				airQ.push({ i, j });
			}
		}
	}
	outerCheese = &cheeseSet1;
	nOuterCheese = &cheeseSet2;
}

void cheeseRefrig::print() {
	printf("\n\n");
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
void cheeseRefrig::checkAir() {
	int i, j;
	while (!airQ.empty()) {
		i = airQ.front().i;
		j = airQ.front().j;
		airQ.pop();
		if (i + 1 < row) {
			if (!arr[i + 1][j]) {
				arr[i + 1][j] = 2;
				airQ.push({ i + 1, j });
			}
			else if (arr[i + 1][j] == 1) outerCheese->insert({ i + 1, j});
		}
		if (j + 1 < col) {
			if (!arr[i][j + 1]) {
				arr[i][j + 1] = 2;
				airQ.push({ i, j + 1 });
			}
			else if (arr[i][j + 1] == 1) outerCheese->insert({ i, j + 1});
		}
		if (i - 1 >= 0) {
			if (!arr[i - 1][j]) {
				arr[i - 1][j] = 2;
				airQ.push({ i - 1, j });
			}
			else if (arr[i - 1][j] == 1) outerCheese->insert({ i - 1, j});
		}
		if (j - 1 >= 0) {
			if (!arr[i][j - 1]) {
				arr[i][j - 1] = 2;
				airQ.push({ i, j - 1 });
			}
			else if (arr[i][j - 1] == 1) outerCheese->insert({ i, j - 1});
		}
	}
}

int cheeseRefrig::getmeltingTime() {
	int timePassed = 0;
	checkAir();
	print();
	int exposed;
	std::vector<node> toCheck;
	std::set<cheese>* temp;
	toCheck.reserve(4);
	while (!outerCheese->empty()) {
		++timePassed;
		for (auto it = outerCheese->begin(); it != outerCheese->end(); ++it) {
			exposed = 0;
			if (it->i + 1 < row) {
				if (arr[it->i + 1][it->j] == 2) ++exposed;
				else toCheck.push_back({ it->i + 1, it->j });
			}
			if (it->i - 1 >= 0) {
				if (arr[it->i - 1][it->j] == 2) ++exposed;
				else toCheck.push_back({ it->i - 1, it->j });
			}
			if (it->j + 1 < col) {
				if (arr[it->i][it->j + 1] == 2) ++exposed;
				else toCheck.push_back({ it->i, it->j + 1});
			}
			if (it->j - 1 >= 0) {
				if (arr[it->i][it->j - 1] == 2) ++exposed;
				else toCheck.push_back({ it->i, it->j - 1 });
			}
			if (exposed > 1) {
				arr[it->i][it->j] = 2;
				for (auto it2 = toCheck.begin(); it2 != toCheck.end(); ++it2) {
					if (!arr[it2->i][it2->j]) {
						airQ.push({ it2->i, it2->j });
						arr[it2->i][it2->j] = 2;
					}
					else if (arr[it2->i][it2->j] == 1) nOuterCheese->insert({ it2->i, it2->j });
				}
			}
			else nOuterCheese->insert({ it->i, it->j });
			toCheck.clear();
		}
		temp = outerCheese;
		outerCheese = nOuterCheese;
		nOuterCheese = temp;
		nOuterCheese->clear();
		checkAir();
		print();
	}
	return timePassed;
}

int main() {
	int row, col;
	scanf_s("%d %d", &row, &col);
	cheeseRefrig refrig(row, col);
	printf("%d", refrig.getmeltingTime());

}