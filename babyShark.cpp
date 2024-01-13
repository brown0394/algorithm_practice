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
	std::queue<node> q;
	void flushQ();
	void eatFish();
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

void babyShark::eatFish() {
	++fishAte;
	if (fishAte == sharkSize) {
		fishAte = 0;
		++sharkSize;
	}
	print();
}

int babyShark::getMaxFishHunt() {

	q.push({ cur.i, cur.j, 0 });
	visit[cur.i][cur.j] = true;
	arr[cur.i][cur.j] = 0;
	int i, j, move;
	while (!q.empty()) {
		i = q.front().i;
		j = q.front().j;
		move = q.front().move;
		q.pop();
		if (i - 1 >= 0 && !visit[i - 1][j] && arr[i - 1][j] <= sharkSize) {
			if (arr[i - 1][j] < sharkSize && arr[i - 1][j]) {
				arr[i - 1][j] = 0;
				eatFish();
				distanceMoved = move + 1;
				flushQ();
				resetVisit();
				q.push({ i - 1, j, move + 1 });
				continue;
			}
			visit[i - 1][j] = true;
			q.push({ i - 1, j, move + 1 });
		}
		if (j - 1 >= 0 && !visit[i][j - 1] && arr[i][j - 1] <= sharkSize) {
			if (arr[i][j - 1] < sharkSize && arr[i][j - 1]) {
				arr[i][j - 1] = 0;
				eatFish();
				distanceMoved = move + 1;
				flushQ();
				resetVisit();
				q.push({ i, j - 1, move + 1 });
				visit[i][j - 1] = true;
				continue;
			}
			visit[i][j - 1] = true;
			q.push({ i, j - 1, move + 1 });
		}
		if (j + 1 < len && !visit[i][j + 1] && arr[i][j + 1] <= sharkSize) {
			if (arr[i][j + 1] < sharkSize && arr[i][j + 1]) {
				arr[i][j + 1] = 0;
				eatFish();
				distanceMoved = move + 1;
				flushQ();
				resetVisit();
				visit[i][j + 1] = true;
				q.push({ i, j + 1, move + 1 });
				continue;
			}
			visit[i][j + 1] = true;
			q.push({ i, j + 1, move + 1 });
		}
		if (i + 1 < len && !visit[i + 1][j] && arr[i + 1][j] <= sharkSize) {
			if (arr[i + 1][j] < sharkSize && arr[i + 1][j]) {
				arr[i + 1][j] = 0;
				eatFish();
				distanceMoved = move + 1;
				flushQ();
				resetVisit();
				visit[i + 1][j] = true;
				q.push({ i + 1, j, move + 1 });
				continue;
			}
			visit[i + 1][j] = true;
			q.push({ i + 1, j, move + 1 });
		}

	}
	return distanceMoved;
}



int main() {
	int size;
	scanf_s("%d", &size);
	babyShark shark(size);

	printf("%d", shark.getMaxFishHunt());
}
