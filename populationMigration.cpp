#include <iostream>
#include <vector>
#include <bitset>
#include <deque>

std::vector<std::bitset<50>> visited;
std::vector<std::vector<int>> countries;
int n, minPop, maxPop;
std::deque<std::pair<int, int>> dq;
int count, sum;

void resetVisited() {
	for (int i = 0; i < n; ++i) {
		visited[i] = 0;
	}
}

bool 

int seq[]{ 1, 0, 1 };
void dfs(int i, int j) {
	sum += countries[i][j];
	++count;
	dq.push_back({ i, j });
	int ij[]{ i, j };
	for (int k = 0; k < 2; ++k) {
		if (ij[k] + 1 < n && countries[i + seq[k]][j + seq[k+1]] >= minPop &&
			countries[i + seq[k]][j + seq[k + 1]] <= maxPop &&
			!visited[i + seq[k]][j + seq[k + 1]]) {
			visited[i + seq[k]][j + seq[k + 1]] = true;
			dfs(i + seq[k], j + seq[k + 1]);
		}
		if (ij[k] && countries[i - seq[k]][j - seq[k + 1]] >= minPop &&
			countries[i - seq[k]][j - seq[k + 1]] <= maxPop &&
			!visited[i - seq[k]][j - seq[k + 1]]) {
			visited[i - seq[k]][j - seq[k + 1]] = true;
			dfs(i - seq[k], j - seq[k + 1]);
		}
	}
}

int main() {
	scanf_s("%d %d %d", &n, &minPop, &maxPop);
	countries.resize(n, std::vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf_s("%d", &countries[i][j]);
		}
	}
	visited.resize(n);
	bool newVal = true;
	int days = 0;
	while (newVal) {
		++days;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (!visited[i][j]) {
					sum = 0; count = 0;
					visited[i][j] = true;
					dfs(i, j);
					int newPop = sum / count;
					if (countries[i][j] != newPop) newVal = false;
					countries[i][j] = newPop;
					while (!dq.empty()) {
						countries[dq.front().first][dq.front().second] = newPop;
						dq.pop_front();
					}
				}
			}
		}
	}
}