#include <iostream>
#include <vector>
#include <queue>

struct node {
	int i;
	int count;
	std::vector<int> path;
};

int main() {
	int N, M;
	scanf_s("%d %d", &N, &M);
	std::vector<int> arr(N, 0);
	for (int i = 0; i < N; ++i) {
		arr[i] = i + 1;
	}
	std::queue<node> q;
	for (int i = 0; i < N; ++i) {
		q.push(node{ i, 1, {i+1} });
	}
	int i, count;
	while (!q.empty()) {
		i = q.front().i;
		count = q.front().count;
		if (count < M) {
			for (int j = i; j < N; ++j) {
				q.push(node{ j, count + 1,  {q.front().path} });
				q.back().path.push_back(j + 1);
			}
		}
		else {
			printf("%d", q.front().path[0]);
			for (auto it = q.front().path.begin() + 1; it != q.front().path.end(); ++it) {
				printf(" %d", *it);
			}
			putchar('\n');
		}
		q.pop();
	}
	
}