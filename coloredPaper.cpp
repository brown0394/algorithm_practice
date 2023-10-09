#include <iostream>
#include <vector>
#include <queue>

struct index{
	int i;
	int j;
};

class cololredPaper {
private:
	std::vector<std::vector<bool>>table;
	bool checkSame(index start, int M);
public:
	cololredPaper(int N);
	void checkPaper();
};

cololredPaper::cololredPaper(int N): table(N, std::vector<bool>(N)) {
	int in;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf_s("%d", &in);
			table[i][j] = static_cast<bool>(in);
		}
	}
}

bool cololredPaper::checkSame(index start, int M) {
	int comp = table[start.i][start.j];
	for (int i = start.i; i < start.i + M; ++i) {
		for (int j = start.j; j < start.j + M; ++j) {
			if (table[i][j] != comp) {
				return false;
			}
		}
	}
	return true;
}

void cololredPaper::checkPaper() {
	std::queue<std::pair<index, int>> q;
	q.push(std::make_pair(index{ 0, 0 }, table.size()));
	int i, j, M;
	int white = 0;
	int blue = 0;
	while (!q.empty()) {
		i = q.front().first.i;
		j = q.front().first.j;
		M = q.front().second;
		q.pop();
		if (checkSame({ i, j }, M)) {
			if (table[i][j]) ++blue;
			else ++white;
		}
		else {
			M = M >> 1;
			if (M == 1) {
				for (int k = i; k < i + 2; ++k) {
					for (int l = j; l < j + 2; ++l) {
						if (table[k][l]) ++blue;
						else ++white;
					}
				}
			}
			else {
				q.push(std::make_pair(index{ i, j }, M));
				q.push(std::make_pair(index{ i, j + M }, M));
				q.push(std::make_pair(index{ i + M, j }, M));
				q.push(std::make_pair(index{ i + M, j + M }, M));
			}
		}
	}

	printf("%d\n%d\n", white, blue);
}

int main() {
	int N;
	scanf_s("%d", &N);
	cololredPaper cp(N);
	cp.checkPaper();
}