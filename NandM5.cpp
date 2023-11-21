#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct node {
	std::vector<int> path;
	int including;
};

int main() {
	int N, M;
	scanf_s("%d %d", &N, &M);
	std::vector<int> arr(N, 0);
	for (int i = 0; i < N; ++i) {
		scanf_s("%d", &arr[i]);
	}
	sort(arr.begin(), arr.end());
	std::queue<node> q;
	for (int i = 0; i < N; ++i) {
		q.push(node{ {i}, 1 << i });
	}
	std::vector<int>* path;
	int including;
	while (!q.empty()) {
		path = &q.front().path;
		including = q.front().including;
		if (path->size() < M) {
			int cur = 1;
			for (int j = 0; j < N; ++j) {
				if (!(including & cur)) {
					q.push(node{ *path, including | cur });
					q.back().path.push_back(j);
				}
				cur = cur << 1;
			}
		}
		else {
			printf("%d", arr[q.front().path[0]]);
			for (auto it = q.front().path.begin() + 1; it != q.front().path.end(); ++it) {
				printf(" %d", arr[*it]);
			}
			putchar('\n');
		}
		q.pop();
	}

}