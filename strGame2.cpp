#include <iostream>
#include <vector>

#define MAXLEN 10010

int main() {
	char str[MAXLEN];
	int testCases, repeat;
	scanf_s("%d", &testCases);
	for (int i = 0; i < testCases; ++i) {
		getchar();
		scanf_s("%s %d", str, MAXLEN, &repeat);
		std::vector<std::vector<int>> alphaIdx(26);
		int min = MAXLEN;
		int max = 0;
		for (int j = 0; str[j]; ++j) {
			int idx = str[j] - 'a';
			alphaIdx[idx].push_back(j);
			if (alphaIdx[idx].size() >= repeat) {
				int back = alphaIdx[idx].size() - 1;
				if (min > alphaIdx[idx][back] - alphaIdx[idx][back - repeat + 1] + 1) {
					min = alphaIdx[idx][back] - alphaIdx[idx][back - repeat + 1] + 1;
				}
				if (max < alphaIdx[idx][back] - alphaIdx[idx][back - repeat + 1] + 1) {
					max = alphaIdx[idx][back] - alphaIdx[idx][back - repeat + 1] + 1;
				}
			}
		}
		if (min == MAXLEN) printf("-1\n");
		else printf("%d %d\n", min, max);
	}
}