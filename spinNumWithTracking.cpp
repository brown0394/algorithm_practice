#include <iostream>
#include <vector>

int stacked;
char start[10001];
char target[10001];

class node {
public:
	int spin;
	int next;
	node() {
		spin = -1;
		next = -1;
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

int spinStack(int left, int depth) {
	int diffLeft = 0, diffRight = 0;
	int cur = (((start[depth] - '0') + left) % 10) + '0';
	getDiffLeftRight(cur, depth, &diffLeft, &diffRight);
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
	int next = 0;
	for (int j = 0; j < 10; ++j) {
		if (record[0][j].next != -1) {
			next = record[0][j].next;
			break;
		}
	}
	for (int k = 1; k <= stacked; ++k) {
		if (next > left) {
			printf("%d %d\n", k, next - left);
			left = next;
		}
		else {
			if (k == stacked) {
				int diffLeft = 0, diffRight = 0;
				int cur = (((start[k-1] - '0') + left) % 10) + '0';
				getDiffLeftRight(cur, k-1, &diffLeft, &diffRight);
				if (diffLeft < diffRight) {
					printf("%d %d\n", k, diffLeft);
				}
				else {
					printf("%d %d\n", k, -diffRight);
				}
				break;
			}
			else printf("%d %d\n", k, record[k][left].spin - record[k-1][left].spin);
		}
		next = record[k][left].next;
	}
}

int main() {
	scanf_s("%d", &stacked);
	scanf_s("%s %s", start, 10001, target, 10001);
	record.resize(stacked, std::vector<node>(10));
	record[0][0].spin = spinStack(0, 0);
	printf("%d\n", record[0][0].spin);
	print();
}
