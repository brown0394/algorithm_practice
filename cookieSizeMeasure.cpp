#include <iostream>
#include <string>
#include <vector>
int main() {
	int n;
	std::cin >> n;
	std::vector<std::string> cookie(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> cookie[i];
	}
	int i = 0, j = 0;
	bool found = false;
	for (; i < n; ++i) {
		for (j = 0; j < n; ++j) {
			if (cookie[i][j] == '*') {
				printf("%d %d\n", i + 2, j + 1);
				found = true;
				break;
			}
		}
		if (found) break;
	}
	++i;
	int count = 0;
	for (int k = j - 1; k >= 0; --k) {
		if (cookie[i][k] != '*') break;
		++count;
	}
	printf("%d", count);
	count = 0;
	for (int k = j + 1; k < n; ++k) {
		if (cookie[i][k] != '*') break;
		++count;
	}
	printf(" %d", count);
	count = 0;
	for (++i; i < n; ++i) {
		if (cookie[i][j] != '*') break;
		++count;
	}
	printf(" %d", count);
	count = 0;
	for (int k = i; k < n; ++k) {
		if (cookie[k][j-1] != '*') break;
		++count;
	}
	printf(" %d", count);
	count = 0;
	for (int k = i; k < n; ++k) {
		if (cookie[k][j + 1] != '*') break;
		++count;
	}
	printf(" %d\n", count);
}
