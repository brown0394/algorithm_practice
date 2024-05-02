#include <iostream>
#include <vector>
#include <bitset>

int main() {
	int n;
	scanf_s("%d", &n);
	std::vector<int> upper(n + 1);
	std::bitset<101> visited;
	std::vector<int> baseArr;
	baseArr.reserve(50);
	for (int i = 1; i <= n; ++i) {
		scanf_s("%d", &upper[i]);
		if (upper[i] == i) {
			baseArr.push_back(i);
			upper[i] = 0;
		}
	}
	int maxLen = 0;
	int maxStart = 0;
	int start;
	for (int i = 1; i <= n; ++i) {
		start = i;
		int cur = upper[i];
		int len = 0;
		visited[i] = true;
		while (cur) {
			++len;
			if (cur == start) {
				if (maxLen < len) {
					maxLen = len;
					maxStart = start;
				}
				break;
			}
			else if (visited[cur]) break;
			visited[cur] = true;
			cur = upper[cur];
		}
		visited = 0;
	}
	int baseIdx = 0;
	int size = baseArr.size();
	int cur = maxStart;
	printf("%d\n", maxLen + size);
	while (cur) {
		if (baseIdx < size && baseArr[baseIdx] < cur) {
			printf("%d\n", baseArr[baseIdx++]);
		}
		else {
			printf("%d\n", cur);
			if (upper[cur] == maxStart) break;
			cur = upper[cur];
		}
	}
	for (; baseIdx < size; ++baseIdx) printf("%d\n", baseArr[baseIdx]);
}