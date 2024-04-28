#include <iostream>
#include <vector>
#include <algorithm>

struct node {
	int idx;
	int height;
	bool operator < (const node& other) {
		if (height == other.height) return idx < other.idx;
		return height > other.height;
	}
};

int main() {
	int maxHeight, maxWidth;
	scanf_s("%d %d", &maxHeight, &maxWidth);
	int open = 0;
	int openIdx = 0;
	std::vector<int> heights(maxWidth);
	std::vector<node> heightsSorted(maxWidth);
	for (int i = 0; i < maxWidth; ++i) {
		scanf_s("%d", &heights[i]);
		heightsSorted[i].idx = i;
		heightsSorted[i].height = heights[i];
	}
	std::sort(heightsSorted.begin(), heightsSorted.end());
	int left = heightsSorted.front().idx;
	int right = left;
	int start = left;
	int sum = 0;
	for (int i = 1; i < maxWidth; ++i) {
		if (heightsSorted[i].idx < start && heightsSorted[i].idx < left) {
			for (int j = left - 1; j > heightsSorted[i].idx; --j) {
				sum += heightsSorted[i].height - heights[j];
			}
			left = heightsSorted[i].idx;
		}
		else if (heightsSorted[i].idx > start && heightsSorted[i].idx > right) {
			for (int j = right + 1; j < heightsSorted[i].idx; ++j) {
				sum += heightsSorted[i].height - heights[j];
			}
			right = heightsSorted[i].idx;
		}
	}
	printf("%d\n", sum);
}