#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> heights;

void calcHeight(int* dwarves, int i, int depth, int sum) {
	if (depth == 8) {
		if (sum == 100) {
			heights.push_back(0);
		}
		else return;
	}
	else {
		while (heights.empty() && i <= depth + 1) {
			calcHeight(dwarves, i + 1, depth + 1, sum + dwarves[i]);
			++i;
		}
		if (!heights.empty())heights.push_back(dwarves[i - 1]);
	}
}

int main() {
	int dwarves[9];
	int in;
	for (int i = 0; i < 9; ++i) {
		scanf_s("%d", &dwarves[i]);
	}
	calcHeight(dwarves, 0, 1, 0);
	std::sort(heights.begin(), heights.end());
	for (auto it = heights.begin() + 1; it != heights.end(); ++it) {
		printf("%d\n", *it);
	}
}
