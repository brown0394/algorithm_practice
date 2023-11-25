#include <iostream>
#include <vector>
#include <queue>


int main() {
	int N;
	scanf_s("%d", &N);
	std::vector<std::vector<int>> arr(N+1);
	std::vector<int> parents(N + 1);
	int from, to;
	for (int i = 0; i < N-1; ++i) {
		scanf_s("%d %d", &from, &to);
		arr[from].push_back(to);
		arr[to].push_back(from);
	}
	std::queue<int> q;
	for (int i = 0; i < arr[1].size(); ++i) {
		q.push(arr[1][i]);
		parents[arr[1][i]] = 1;
	}
	int idx;
	while (!q.empty()) {
		idx = q.front();
		q.pop();

		for (int i = 0; i < arr[idx].size(); ++i) {
			if (arr[idx][i] != parents[idx]) {
				q.push(arr[idx][i]);
				parents[arr[idx][i]] = idx;
			}
		}
	}
	for (int i = 2; i <= N; ++i) {
		printf("%d\n", parents[i]);
	}

}