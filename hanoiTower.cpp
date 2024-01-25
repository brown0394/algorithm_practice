#include <iostream>
#include <stack>
#include <vector>

struct node {
	int from;
	int to;
};

std::vector<node> path;

void hanoi(int from, int to, int num) {
	if (num == 2) {
		for (int i = 1; i <= 3; ++i) {
			if (i != from && i != to) {
				path.push_back({ from, i });
				path.push_back({ from, to });
				path.push_back({ i, to });
				break;
			}
		}
	}
	else {
		for (int i = 1; i <= 3; ++i) {
			if (i != from && i != to) {
				hanoi(from, i, num - 1);
				path.push_back({ from, to });
				hanoi(i, to, num - 1);
				break;
			}
		}
	}
}
int main() {
	int disc;
	scanf_s("%d", &disc);
	if (disc == 1) {
		printf("1\n1 3\n");
	}
	else {
		int size = (1 << disc) - 1;
		path.reserve(size + 1);
		hanoi(1, 3, disc);
		printf("%d\n", size);
		for (auto it = path.begin(); it != path.end(); ++it) {
			printf("%d %d\n", it->from, it->to);
		}
	}
}
