#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int fluids;
	scanf_s("%d", &fluids);
	std::vector<int> fluid(fluids);
	for (int i = 0; i < fluids; ++i) {
		scanf_s("%d", &fluid[i]);
	}
	std::sort(fluid.begin(), fluid.end());
	int j = fluid.size() - 1, i = 0;
	int minDiff = ~(1 << 31);
	int minj, mini;
	while (i < j) {
		int diff = fluid[j] + fluid[i];
		int diffComp = diff;
		if (diff > 0) --j;
		else if (diff == 0) {
			mini = i;
			minj = j;
			break;
		}
		else {
			++i;
			diffComp = -diff;
		}
		if (diffComp < minDiff) {
			minDiff = diffComp;
			mini = i;
			minj = j;
			if (diff < 0) --mini;
			else ++minj;
		}
	}
	printf("%d %d\n", fluid[mini], fluid[minj]);
}
