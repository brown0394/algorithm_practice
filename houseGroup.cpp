#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
	int n;
	scanf_s("%d", &n);
	std::vector<std::vector<char>> table(n, std::vector<char>(n, 0));
	std::vector<std::vector<bool>> visit(n, std::vector<bool>(n, false));
	for (int i = 0; i < n; ++i) {
		getchar();
		for (int j = 0; j < n; ++j) {
			scanf_s("%c", &table[i][j], 1);
			if (table[i][j] == '1') visit[i][j] = true;
		}
	}
	int count, k, l;
	std::queue<std::pair<int, int>> q;
	std::vector<int> answer;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (visit[i][j]) {
				count = 1;
				visit[i][j] = false;
				q.push(std::make_pair(i, j));
				while (!q.empty()) {
					k = q.front().first;
					l = q.front().second;
					q.pop();

					if (k + 1 < n && visit[k + 1][l]) {
						q.push(std::make_pair(k + 1, l));
						visit[k + 1][l] = false;
						++count;
					}
					if (k - 1 >= 0 && visit[k - 1][l]) {
						q.push(std::make_pair(k - 1, l));
						visit[k - 1][l] = false;
						++count;
					}
					if (l + 1 < n && visit[k][l + 1]) {
						q.push(std::make_pair(k, l + 1));
						visit[k][l + 1] = false;
						++count;
					}
					if (l - 1 >= 0 && visit[k][l - 1]) {
						q.push(std::make_pair(k, l - 1));
						visit[k][l - 1] = false;
						++count;
					}
				}
				answer.push_back(count);
			}
		}
	}

	std::sort(answer.begin(), answer.end());
	printf("%d\n", answer.size());
	for (auto it = answer.begin(); it != answer.end(); ++it) {
		printf("%d\n", *it);
	}
}