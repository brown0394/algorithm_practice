#include <iostream>
#include <vector>


int main() {
	int testCases;
	scanf_s("%d", &testCases);
	for (int i = 1; i <= testCases; ++i) {
		int checkPointN;
		scanf_s("%d", &checkPointN);
		int last, cur, peaks = 0;
		bool hasClimbed = false;
		scanf_s("%d", &last);
		for (int j = 1; j < checkPointN; ++j) {
			scanf_s("%d", &cur);
			if (cur > last) {
				hasClimbed = true;
			}
			else {
				if (cur < last && hasClimbed) ++peaks;
				hasClimbed = false;
			}
			last = cur;
		}
		printf("Case #%d: %d\n", i, peaks);
	}
}