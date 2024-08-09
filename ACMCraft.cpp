#include <iostream>
#include <queue>

int connection[1001][1005];
int costs[1005];
int tot[1005];
const int LEN = 0;
const int IN = 1004;

int getTimeToBuild(int target, int buildings) {
	std::queue<int> q;
	for (int i = 1; i <= buildings; ++i) {
		if (!connection[i][IN]) {
			if (i == target) return costs[i];
			q.push(i);
		}
	}
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= connection[cur][LEN]; ++i) {
			--connection[connection[cur][i]][IN];
			if (tot[connection[cur][i]] < tot[cur] + costs[connection[cur][i]]) {
				tot[connection[cur][i]] = tot[cur] + costs[connection[cur][i]];
			}
			if (!connection[connection[cur][i]][IN]) {
				if (connection[cur][i] == target) return tot[connection[cur][i]];
				q.push(connection[cur][i]);
			}
		}
	}
	return -1;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int testCases;
	std::cin >> testCases;
	for (int i = 0, buildings, seqs; i < testCases; ++i) {
		std::cin >> buildings >> seqs;
		for (int i = 1; i <= buildings; ++i) {
			std::cin >> costs[i];
			connection[i][LEN] = 0;
			connection[i][IN] = 0;
			tot[i] = costs[i];
		}
		for (int i = 0, from, to; i < seqs; ++i) {
			std::cin >> from >> to;
			++connection[from][LEN];
			connection[from][connection[from][LEN]] = to;
			++connection[to][IN];
		}
		int target;
		std::cin >> target;
		std::cout << getTimeToBuild(target, buildings) << '\n';
	}
}