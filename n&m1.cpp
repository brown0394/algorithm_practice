#include <iostream>
#include <stack>
#include <vector>
#include <bitset>

struct node {
	int subPath;
	int idx;
	int depth;
};

int main() {
	int n, m;
	scanf_s("%d %d", &n, &m);

	if (m == 1) {
		for (int i = 1; i <= n; ++i) {
			printf("%d\n", i);
		}
	}
	else {
		std::vector<int> path(m - 1);
		std::stack<node> stk;
		int subPath, depth, idx;
		for (int i = 0; i < n; ++i) {
			stk.push({ 1 << i, 0, 1 });
			path[0] = i + 1;
			while (!stk.empty()) {
				int cur;
				subPath = stk.top().subPath;
				depth = stk.top().depth;
				idx = stk.top().idx;
				if (depth == m - 1) {
					for (int j = 0; j < n; ++j) {
						cur = 1 << j;
						if (!(cur & subPath)) {
							printf("%d", path[0]);
							for (int k = 1; k < m - 1; ++k) {
								printf(" %d", path[k]);
							}
							printf(" %d\n", j + 1);
						}
					}
					stk.pop();
					continue;
				}
				for (idx; idx < n; ++idx) {
					cur = 1 << idx;
					if (!(cur & subPath)) {
						cur = cur | subPath;
						path[depth] = idx + 1;
						stk.top().idx = idx + 1;
						stk.push({ cur, 0, depth + 1 });
						break;
					}
				}
				if (idx < n) continue;
				stk.pop();
			}
		}
	}
}
