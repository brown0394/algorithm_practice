#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

struct node {
	int i;
	int j;
	bool operator < (const node& other) {
		if (i == other.i) {
			return j < other.j;
		}
		return i < other.i;
	}
};

int main() {
	int row, col, trampoline, fallingStars;
	scanf_s("%d %d %d %d", &col, &row, &trampoline, &fallingStars);
	std::vector<node> star(fallingStars);
	std::set<int> js;
	for (int i = 0; i < fallingStars; ++i) {
		scanf_s("%d %d", &star[i].j, &star[i].i);
		js.insert(star[i].j);
	}
	std::sort(star.begin(), star.end());
	int a = 10;
	int minStarsTouchGround = fallingStars;
	row -= trampoline;
	col -= trampoline;
	for (int i = 0; i < fallingStars; ++i) {
		for (auto it = js.begin(); it != js.end(); ++it) {
			int verticalEnd = star[i].i + trampoline;
			int horizontalEnd = *it + trampoline;
			int touchGround = fallingStars;
			int idx = i;
			while (idx < fallingStars && star[idx].i <= verticalEnd) {
				if (star[idx].j >= *it && star[idx].j <= horizontalEnd) --touchGround;
				++idx;
			}
			if (touchGround < minStarsTouchGround) minStarsTouchGround = touchGround;
		}
	}
	printf("%d\n", minStarsTouchGround);
}