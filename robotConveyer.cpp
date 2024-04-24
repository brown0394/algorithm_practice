#include <iostream>
#include <vector>
#include <deque>


int main() {
	int spaces, wornOffLimit;
	scanf_s("%d %d", &spaces, &wornOffLimit);
	spaces <<= 1;
	std::vector<int> convBelt(spaces);
	for (int i = 0; i < spaces; ++i) {
		scanf_s("%d", &convBelt[i]);
	}
	int move = 0;
	int putPoint = 0;
	std::deque<int> robots;
	int offPoint = (spaces >> 1) - 1;
	while (wornOffLimit > 0) {
		++move;
		if (!putPoint) putPoint = spaces - 1;
		else --putPoint;
		if (!offPoint) offPoint = spaces - 1;
		else --offPoint;
		if (!robots.empty()) {
			if (robots[0] == offPoint) robots.pop_front();
			for (int i = 0; i < robots.size(); ++i) {
				int next = (robots[i] + 1) % spaces;
				if (convBelt[next]) {
					if (i && robots[i - 1] == next) continue;
					if (--convBelt[next] == 0) --wornOffLimit;
					if (next == offPoint) {
						robots.pop_front();
						--i;
					}
					else robots[i] = next;
					
				}
			}
		}
		if (convBelt[putPoint]) {
			if (--convBelt[putPoint] == 0) --wornOffLimit;
			robots.push_back(putPoint);
		}
	}
	printf("%d\n", move);
}