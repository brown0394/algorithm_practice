#include <iostream>
#include <algorithm>
int main() {
	int testCases;
	scanf_s("%d", &testCases);
	int mountain1[1000], mountain2[1000];
	for (int i = 0; i < testCases; ++i) {
		int size1, size2;
		scanf_s("%d", &size1);
		for (int j = 0; j < size1; ++j) {
			scanf_s("%d", &mountain1[j]);
		}
		scanf_s("%d", &size2);
		for (int j = 0; j < size2; ++j) {
			scanf_s("%d", &mountain2[j]);
		}
		std::sort(mountain1, mountain1 + size1);
		std::sort(mountain2, mountain2 + size2);
		int minDiff = 1000000000;
		int idx1 = 0, idx2 = 0;
		while (idx1 < size1 && idx2 < size2) {
			int diff;
			if (mountain1[idx1] > mountain2[idx2]) {
				diff = mountain1[idx1] - mountain2[idx2];
				++idx2;
			}
			else {
				diff = mountain2[idx2] - mountain1[idx1];
				++idx1;
			}
			if (diff < minDiff) minDiff = diff;
		}
		printf("%d\n", minDiff);
	}
}