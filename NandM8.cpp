#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct node {
	int i;
	std::vector<int> path;
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
		q.push(node{ i,{i}});
	}
	std::vector<int>* path;
	int i;
	while (!q.empty()) {
		i = q.front().i;
		path = &q.front().path;
		if (path->size() < M) {
			for (int j = i; j < N; ++j) {
				q.push(node{ j, *path});
				q.back().path.push_back(j);
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