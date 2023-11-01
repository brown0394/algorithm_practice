#include <iostream>
#include <vector>
#include <queue>

struct node {
	int i;
	int j;
	int count;
};
int main() {
	int n, m;
	scanf_s("%d %d", &n, &m);
	std::vector<std::vector<char>> table(n, std::vector<char>(m, 0));
	std::vector<std::vector<bool>> visit(n, std::vector<bool>(m, false));
	for (int i = 0; i < n; ++i) {
		getchar();
		for (int j = 0; j < m; ++j) {
			scanf_s("%c", &table[i][j], 1);
			if (table[i][j] == '1') visit[i][j] = true;
		}
	}
	std::queue<node> q;
	int count, k, l;
	count = 1;
	visit[0][0] = false;
	q.push(node{0, 0, 1});
	while (!q.empty()) {
		k = q.front().i;
		l = q.front().j;
		count = q.front().count;
		q.pop();

		if (k + 1 < n && visit[k + 1][l]) {
			if (k + 2 == n && l + 1 == m) {
				++count;
				break;
			}
			q.push(node{ k + 1, l, count + 1});
			visit[k + 1][l] = false;
		}
		if (k - 1 >= 0 && visit[k - 1][l]) {
			q.push(node{ k - 1, l, count + 1 });
			visit[k - 1][l] = false;
		}
		if (l + 1 < m && visit[k][l + 1]) {
			if (k + 1 == n && l + 2 == m) {
				++count;
				break;
			}
			q.push(node{ k, l + 1, count + 1 });
			visit[k][l + 1] = false;
		}
		if (l - 1 >= 0 && visit[k][l - 1]) {
			q.push(node{ k, l - 1, count + 1 });
			visit[k][l - 1] = false;
		}
	}

	printf("%d\n", count);
}