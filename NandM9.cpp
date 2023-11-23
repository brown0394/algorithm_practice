#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct node {
	int including;
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
	q.push(node{ 1,{0} });
	for (int i = 1; i < N; ++i) {
		if (arr[i-1] != arr[i]) {
			q.push(node{ 1 << i, {i} });
		}
	}
	std::vector<int>* path;
	int including, last;
	while (!q.empty()) {
		including = q.front().including;
		path = &q.front().path;
		if (path->size() < M) {
			last = -1;
			for (int j = 0; j < N; ++j) {
				if (!(including & 1 << j) && arr[j] != last) {
					last = arr[j];
					q.push(node{ including | 1 << j, *path });
					q.back().path.push_back(j);
				}
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