#include <iostream>
#include <vector>

int stacked;
char start[10001];
char target[10001];

struct node {
	int spin;
	int next;
};

std::vector<std::vector<node>> record;

void getDiff(int cur, int depth, int* diffLeft, int* diffRight) {
	if (cur > target[depth]) {
		*diffLeft = target[depth] + 10 - cur;
		*diffRight = cur - target[depth];
	}
	else if (cur < target[depth]) {
		*diffLeft = target[depth] - cur;
		*diffRight = cur + 10 - target[depth];
	}
}

int spinStack(int left, int depth) {
	int diffLeft = 0, diffRight = 0;
	getDiff((((start[depth] - '0') + left) % 10) + '0', depth, &diffLeft, &diffRight);
	if (depth == stacked - 1) {
		if (diffLeft <= diffRight) record[depth][left].spin = diffLeft;
		else record[depth][left].spin = diffRight;
		return record[depth][left].spin;
	}
	int nextLeft = (left + diffLeft) % 10;
	if (record[depth + 1][nextLeft].spin == -1) 
		record[depth + 1][nextLeft].spin = spinStack(nextLeft, depth + 1);
	diffLeft += record[depth + 1][nextLeft].spin;
	if (record[depth + 1][left].spin == -1)
		record[depth + 1][left].spin = spinStack(left, depth + 1);
	diffRight += record[depth + 1][left].spin;
	if (diffLeft <= diffRight) {
		record[depth][left].next = nextLeft;
		return diffLeft;
	}
	record[depth][left].next = left;
	return diffRight;
}

void print() {
	int left = 0;
	int next;
	for (int j = 0; j < 10; ++j) {
		if (record[0][j].next != -1) {
			next = record[0][j].next;
			break;
		}
	}
	int k = 1;
	while (true) {
		if (next > left) {
			printf("%d %d\n", k, next - left);
			left = next;
		}
		else {
			int diffRight = 0;
			int diffLeft = 0;
			getDiff((((start[k - 1] - '0') + left) % 10) + '0', k - 1, &diffLeft, &diffRight);
			if (diffRight) printf("%d %d\n", k, -diffRight);
			else printf("%d 0\n", k);
		}
		if (k == stacked) break;
		next = record[k][next].next;
		++k;
	}
}

int main() {
	scanf("%d", &stacked);
	scanf("%s %s", start, target);
	record.resize(stacked, std::vector<node>(10, {-1, -1}));
	printf("%d\n", spinStack(0, 0));
	print();
}
