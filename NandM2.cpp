#include <iostream>
#include <vector>
#include <queue>

struct node {
	int i;
	int count;
	int path;
};

int main() {
	int N, M;
	scanf_s("%d %d", &N, &M);
	std::vector<int> arr(N, 0);
	for (int i = 0; i < N; ++i) {
		arr[i] = i + 1;
	}
	std::queue<node> q;
	for (int i = 0; i <= N - M; ++i) {
		q.push(node{ i, 1, 1 << i });
	}
	int i, count, path;
	while (!q.empty()) {
		i = q.front().i;
		count = q.front().count;
		path = q.front().path;
		q.pop();
		if (count < M) {
			int til = N - M + count;
			for (int j = i + 1; j <= til; ++j) {
				q.push(node{ j, count + 1,  path | (1 << j)});
			}
		}
		else {
			int cur = 1;
			int idx = 1;
			bool first = true;
			while (count) {
				if (cur & path) {
					if (first) {
						printf("%d", idx);
						first = false;
					}
					else printf(" %d", idx);
					--count;
				}
				cur = cur << 1;
				++idx;
			}
			putchar('\n');
		}
	}
	
}