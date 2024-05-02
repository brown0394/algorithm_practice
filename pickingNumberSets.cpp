#include <iostream>
#include <vector>
#include <bitset>

int main() {
	int n;
	scanf_s("%d", &n);
	std::vector<int> upper(n + 1);
	std::bitset<101> visited;
	std::bitset<101> added;
	for (int i = 1; i <= n; ++i) {
		scanf_s("%d", &upper[i]);
	}
	int maxLen = 0;
	int start;
	for (int i = 1; i <= n; ++i) {
		if (visited[i]) continue;
		start = i;
		int cur = upper[i];
		int len = 0;
		visited[i] = true;
		while (cur) {
			++len;
			if (cur == start) {
				maxLen += len;
				added = visited;
				break;
			}
			else if (visited[cur]) break;
			visited[cur] = true;
			cur = upper[cur];
		}
		visited = added;
	}
	printf("%d\n", maxLen);
	for (int i = 1; i < 101; ++i) {
		if (visited[i]) printf("%d\n", i);
	}
	
}