#include <iostream>
#include <vector>
#include <queue>

struct node {
	char i;
	char j;
	int alphabetsPassed;
	char count;
};

int main() {
	int row, col;
	scanf("%d %d", &row, &col);
	std::vector<std::vector<char>> arr(row, std::vector<char>(col));
	for (int i = 0; i < row; ++i) {
		getchar();
		for (int j = 0; j < col; ++j) {
			scanf("%c", &arr[i][j]);
		}
	}
	std::queue<node> q;
	q.push({ 0, 0, 1 << (arr[0][0] - 'A'), 1 });
	int i,j, alphabetsPassed, count;
	int max = 0;
	while (!q.empty()) {
		i = q.front().i;
		j = q.front().j;
		alphabetsPassed = q.front().alphabetsPassed;
		count = q.front().count;
		if (max < count) {
            max = count;
            if (max == 26) break;
        }
		q.pop();
		if (i + 1 < row && !((1 << (arr[i + 1][j] - 'A')) & alphabetsPassed)) {
			q.push({ i + 1, j, alphabetsPassed | (1 << (arr[i + 1][j] - 'A')), count + 1 });
		}
		if (i - 1 >= 0 && !((1 << (arr[i - 1][j] - 'A')) & alphabetsPassed)) {
			q.push({ i - 1, j, alphabetsPassed | (1 << (arr[i - 1][j] - 'A')), count + 1 });
		}
		if (j + 1 < col && !((1 << (arr[i][j + 1] - 'A')) & alphabetsPassed)) {
			q.push({ i, j + 1, alphabetsPassed | (1 << (arr[i][j + 1] - 'A')), count + 1 });
		}
		if (j - 1 >= 0 && !((1 << (arr[i][j - 1] - 'A')) & alphabetsPassed)) {
			q.push({ i, j - 1, alphabetsPassed | (1 << (arr[i][j - 1] - 'A')), count + 1 });
		}
	}
	printf("%d\n", max);
}