#include <iostream>
#include <vector>

int stacked;
char start[10001];
char target[10001];

class node {
public:
	int totalSpin;
	int spin;
	node() {
		totalSpin = -1;
		spin = -1;
	}
};

std::vector<std::vector<node>> record;

void getDiffLeftRight(int cur, int depth, int* diffLeft, int* diffRight) {
	if (cur > target[depth]) {
		*diffLeft = target[depth] + 10 - cur;
		*diffRight = cur - target[depth];
	}
	else if (cur < target[depth]) {
		*diffLeft = target[depth] - cur;
		*diffRight = cur + 10 - target[depth];
	}
}

void spinStack(int left, int depth) {
	int diffLeft = 0, diffRight = 0;
	int cur = (((start[depth] - '0') + left) % 10) + '0';
	getDiffLeftRight(cur, depth, &diffLeft, &diffRight);
	if (depth == stacked - 1) {
		if (diffLeft < diffRight) {
			record[depth][left].totalSpin = diffLeft;
			record[depth][left].spin = diffLeft;
		}
		else {
			record[depth][left].totalSpin = diffRight;
			record[depth][left].spin = -diffRight;
		}
		return;
	}
	int nextLeft = (left + diffLeft) % 10;
	if (record[depth + 1][nextLeft].totalSpin == -1) spinStack(nextLeft, depth + 1);
	if (record[depth + 1][left].totalSpin == -1) spinStack(left, depth + 1);
	if (diffLeft + record[depth + 1][nextLeft].totalSpin 
		< diffRight + record[depth + 1][left].totalSpin) {
		record[depth][left].totalSpin = diffLeft + record[depth + 1][nextLeft].totalSpin;
		record[depth][left].spin = diffLeft;
		return;
	}
	record[depth][left].spin = -diffRight;
	record[depth][left].totalSpin = diffRight + record[depth + 1][left].totalSpin;
}

void print() {
	for (int i = 0; i < 10; ++i) {
		if (record[0][i].totalSpin != -1) {
			for (int j = 0; j < stacked; ++j) {
				printf("%d %d\n", j + 1, record[j][i].spin);
				if (record[j][i].spin > 0) i = (i + record[j][i].spin) % 10;
			}
			break;
		}
	}
}

int main() {
	scanf_s("%d", &stacked);
	scanf_s("%s %s", start, 10001, target, 10001);
	record.resize(stacked, std::vector<node>(10));
	spinStack(0, 0);
	printf("%d\n", record[0][0].totalSpin);
	print();
}
