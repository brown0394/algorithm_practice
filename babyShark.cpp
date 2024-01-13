#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

struct loc {
	int i;
	int j;
};

struct node {
	int i;
	int j;
	int move;
};

class babyShark {
private:
	int len;
	std::vector<std::vector<int>> arr;
	loc cur;
	int sharkSize;
	int fishAte;
	int distanceMoved;
	int fishI;
	int fishJ;
	int foundTime;
	bool bfs();
	std::queue<node> q;
	void flushQ();
	std::vector<std::bitset<20>> visit;
	void resetVisit();
	void print();
	
public:
	babyShark(int p_size);
	int getMaxFishHunt();
};

babyShark::babyShark(int p_size) : len(p_size), arr(len, std::vector<int>(len)), visit(len) {
	sharkSize = 2;
	fishAte = 0;
	distanceMoved = 0;
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			scanf_s("%d", &arr[i][j]);
			if (arr[i][j] == 9) {
				cur.i = i;
				cur.j = j;
			}
		}
	}
};

void babyShark::print() {
	printf("\n\n");
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

void babyShark::resetVisit() {
	for (int i = 0; i < len; ++i) {
		visit[i] = 0;
	}
}

void babyShark::flushQ() {
	while (!q.empty()) q.pop();
}

bool babyShark::bfs() {
	int i, j, move;
	bool found = false;
	while (!q.empty()) {
		i = q.front().i;
		j = q.front().j;
		move = q.front().move;
		q.pop();
		if (found && move > foundTime) break;
		if (arr[i][j] && arr[i][j] < sharkSize) {
			if (found) {
				if (fishI > i) {
					fishI = i;
					fishJ = j;
				}
				else if (fishI == i && fishJ > j) fishJ = j;
			}
			else {
				found = true;
				fishI = i;
				fishJ = j;
				foundTime = move;
			}
			continue;
		}
		if (i - 1 >= 0 && !visit[i - 1][j] && arr[i - 1][j] <= sharkSize) {
			visit[i - 1][j] = true;
			q.push({ i - 1, j, move + 1 });
		}
		if (j - 1 >= 0 && !visit[i][j - 1] && arr[i][j - 1] <= sharkSize) {
			visit[i][j - 1] = true;
			q.push({ i, j - 1, move + 1 });
		}
		if (j + 1 < len && !visit[i][j + 1] && arr[i][j + 1] <= sharkSize) {
			visit[i][j + 1] = true;
			q.push({ i, j + 1, move + 1 });
		}
		if (i + 1 < len && !visit[i + 1][j] && arr[i + 1][j] <= sharkSize) {
			visit[i + 1][j] = true;
			q.push({ i + 1, j, move + 1 });
		}

	}
	return found;
}

int babyShark::getMaxFishHunt() {
	q.push({ cur.i, cur.j, 0 });
	visit[cur.i][cur.j] = true;
	arr[cur.i][cur.j] = 0;
	while (bfs()) {
		arr[fishI][fishJ] = 0;
		++fishAte;
		if (fishAte == sharkSize) {
			fishAte = 0;
			++sharkSize;
		}
		distanceMoved = foundTime;
		flushQ();
		resetVisit();
		q.push({ fishI, fishJ, foundTime });
		visit[fishI][fishJ] = true;
	}
	return distanceMoved;
}



int main() {
	int size;
	scanf_s("%d", &size);
	babyShark shark(size);

	printf("%d", shark.getMaxFishHunt());
}
