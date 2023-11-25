#include <iostream>
#include <vector>
#include <queue>

struct node {
	unsigned int cur;
	unsigned int count;
};

int main() {
	unsigned int A, B;
	scanf_s("%d %d", &A, &B);

	std::queue<node> q;
	q.push(node { A, 1 });
	bool found = false;
	unsigned int doubled, mulTenPlusOne, cur, count = 0;
	while (!q.empty()) {
		cur = q.front().cur;
		count = q.front().count;
		q.pop();
		if (cur == B) {
			found = true;
			break;
		}
		++count;
		doubled = cur << 1;
		mulTenPlusOne = cur * 10 + 1;
		if (doubled <= B) {
			q.push(node{ doubled, count });
			if (mulTenPlusOne <= B) {
				q.push(node{ mulTenPlusOne, count });
			}
		}
	}

	if (found) {
		printf("%d\n", count);
	}
	else {
		printf("-1\n");
	}
}