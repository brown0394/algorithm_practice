#include <iostream>
#include <vector>
#include <algorithm>

struct node {
	int loc;
	int height;
	bool operator <(const node& other) {
		return height > other.height;
	}
};

inline int substractArea(const int& x1, const int& x2, const int& y1, const int& y2) {
	return (x1 - x2) * (y1 - y2);
}

int main() {
	int numOfPillars;
	scanf_s("%d", &numOfPillars);
	std::vector<node> pillars(numOfPillars);
	int widthMin = 10000;
	int widthMax = 0;
	for (int i = 0; i < numOfPillars; ++i) {
		scanf_s("%d %d", &pillars[i].loc, &pillars[i].height);
		if (widthMin > pillars[i].loc) widthMin = pillars[i].loc;
		if (widthMax < pillars[i].loc) widthMax = pillars[i].loc;
	}
	std::sort(pillars.begin(), pillars.end());
	int width = widthMax + 1 - widthMin;
	int height = pillars[0].height;
	int area = width * pillars[0].height;
	int left = pillars[0].loc;
	int right = left;
	for (int i = 1; i < numOfPillars; ++i) {
		if (pillars[i].loc < left) {
			area -= substractArea(left, pillars[i].loc, height, pillars[i].height);
			left = pillars[i].loc;
		}
		else if (pillars[i].loc > right) {
			area -= substractArea(pillars[i].loc, right, height, pillars[i].height);
			right = pillars[i].loc;
		}
	}
	printf("%d\n", area);
}