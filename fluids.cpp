#include <iostream>
#include <vector>

int main() {
	int nfluids;
	scanf_s("%d", &nfluids);
	std::vector<int> fluids(nfluids);
	for (int i = 0; i < nfluids; ++i) {
		scanf_s("%d", &fluids[i]);
	}
	int minDiff = 2000000000;
	int left = 0;
	int right = nfluids - 1;
	int curDiff, lv, rv;
	while (left < right) {
		curDiff = fluids[left] + fluids[right];
		if (curDiff < 0) {
			if (-curDiff < minDiff) {
				minDiff = -curDiff;
				lv = fluids[left];
				rv = fluids[right];
			}
			++left;
		}
		else {
			if (curDiff < minDiff) {
				minDiff = curDiff;
				lv = fluids[left];
				rv = fluids[right];
			}
			--right;
		}
	}
	printf("%d %d\n", lv, rv);
}