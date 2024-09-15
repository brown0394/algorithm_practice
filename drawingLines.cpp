#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>


int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int points;
	std::cin >> points;
	std::vector<std::vector<long long>> pointsSameColor(points + 1);
	const long long MAX = std::numeric_limits<long long>::max();
	for (int i = 0, loc, color; i < points; ++i) {
		std::cin >> loc >> color;
		pointsSameColor[color].push_back(loc);
	}
	long long totalLen = 0;
	for (int i = 1; i <= points; ++i) {
		if (pointsSameColor[i].empty()) continue;
		std::sort(pointsSameColor[i].begin(), pointsSameColor[i].end());
		for (int j = 0, len = pointsSameColor[i].size(); j < len; ++j) {
			long long closest = MAX;
			if (j) {
				closest = pointsSameColor[i][j] - pointsSameColor[i][j - 1];
			}
			if (j + 1 < len && pointsSameColor[i][j + 1] - pointsSameColor[i][j] < closest) {
				closest = pointsSameColor[i][j + 1] - pointsSameColor[i][j];
			}
			if (closest < MAX) totalLen += closest;
		}
	}
	std::cout << totalLen << '\n';
}