#include <iostream>
#include <vector>

struct node {
	int idx;
	int count;
};

int getBallsMinMove(const std::vector<node>& balls, int lastIdx) {
	if (balls.empty()) return 0;
	int moves = 0;
	const node& back = balls.back();
	if (balls[0].idx == 0) {
		if (back.idx + back.count == lastIdx && balls[0].count < back.count) {
			for (auto it = ++balls.rbegin(); it != balls.rend(); ++it) {
				moves += it->count;
			}
		}
		else {
			for (auto it = ++balls.begin(); it != balls.end(); ++it) {
				moves += it->count;
			}
		}
	}
	else if (back.idx + back.count == lastIdx) {
		for (auto it = ++balls.rbegin(); it != balls.rend(); ++it) {
			moves += it->count;
		}
	}
	else {
		if (back.count < balls[0].count) {
			for (auto it = balls.rbegin(); it != balls.rend(); ++it) {
				moves += it->count;
			}
		}
		else {
			for (auto it = balls.begin(); it != balls.end(); ++it) {
				moves += it->count;
			}
		}
	}
	return moves;
}

int main() {
	int numOfBalls;
	std::vector<node> blueBalls;
	std::vector<node> redBalls;
	scanf_s("%d", &numOfBalls);
	bool blue = false;
	char in;
	getchar();
	int count = 1;
	scanf_s("%c", &in);
	if (in == 'B') blue = true;
	for (int i = 1; i <= numOfBalls; ++i) {
		if (i < numOfBalls) scanf_s("%c", &in);
		else {
			if (in == 'R') in = 'B';
			else in = 'R';
		}
		if (in == 'R') {
			if (blue) {
				blueBalls.push_back(node{ i - count, count });
				count = 1;
				blue = false;
			}
			else ++count;
		}
		else {
			if (blue) ++count;
			else {
				redBalls.push_back(node{ i - count, count });
				count = 1;
				blue = true;
			}
		}
	}
	int blueMove = getBallsMinMove(blueBalls, numOfBalls);
	int redMove = getBallsMinMove(redBalls, numOfBalls);
	if (blueMove < redMove) printf("%d\n", blueMove);
	else printf("%d\n", redMove);
}