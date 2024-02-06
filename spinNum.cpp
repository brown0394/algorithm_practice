#include <iostream>
#include <vector>

int stacked;
char start[10001];
char target[10001];
std::vector<std::vector<int>> record;

int spinStack(int left, int depth) {
	int diffLeft = 0, diffRight = 0;
	int cur = (((start[depth] - '0') + left) % 10) + '0';
	if (cur > target[depth]) {
		diffLeft = target[depth] + 10 - cur;
		diffRight = cur - target[depth];
	}
	else if (cur < target[depth]) {
		diffLeft = target[depth] - cur;
		diffRight = cur + 10 - target[depth];
	}
	if (depth == stacked - 1) {
		if (diffLeft <= diffRight) record[depth][left] = diffLeft;
		else record[depth][left] = diffRight;
		return record[depth][left];
	}
	int nextLeft = (left + diffLeft) % 10;
	if (record[depth + 1][nextLeft] == -1) record[depth + 1][nextLeft] = spinStack(nextLeft, depth + 1);
	diffLeft += record[depth + 1][nextLeft];
	if (record[depth + 1][left] == -1) record[depth + 1][left] = spinStack(left, depth + 1);
	diffRight += record[depth + 1][left];
	if (diffLeft <= diffRight) return diffLeft;
	return diffRight;
}

int main() {
	scanf_s("%d", &stacked);
	scanf_s("%s %s", start, 10001, target, 10001);
	record.resize(stacked, std::vector<int>(10, -1));
	printf("%d\n", spinStack(0, 0));
}
