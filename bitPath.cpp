#include <iostream>
#include <vector>
#include <queue>
#include <bitset>



int main() {
	int n;
	scanf_s("%d", &n);
	std::vector<std::bitset<100>> path(n);
	int in;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf_s("%d", &in);
			if (in) path[i][j] = true;
			else path[i][j] = false;
		}
	}
	std::queue<int> q;
	int idx;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (path[i][j]) q.push(j);
		}
		while (!q.empty()) {
			idx = q.front();
			q.pop();
			for (int j = 0; j < n; ++j) {
				if (path[idx][j] && !path[i][j]) q.push(j);
			}
			path[i] |= path[idx];
		}
	}
	bool first;
	for (int i = 0; i < n; ++i) {
		first = true;
		for (int j = 0; j < n; ++j) {
			if (path[i][j]) {
				if (first) {
					first = false;
					printf("1");
				}
				else {
					printf(" 1");
				}
			}
			else {
				if (first) {
					first = false;
					printf("0");
				}
				else {
					printf(" 0");
				}
			}
		}
		putchar('\n');
	}
}