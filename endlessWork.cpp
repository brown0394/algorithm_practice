#include <iostream>
#include <stack>

struct workInfo {
	int score;
	int minToFinish;
};

int main() {
	int works;
	scanf_s("%d", &works);
	std::stack<workInfo> stk;
	int totalScore = 0;
	for (int i = 0; i < works; ++i) {
		int workGiven;
		scanf_s("%d", &workGiven);
		if (workGiven) {
			int score, minToFinish;
			scanf_s("%d %d", &score, &minToFinish);
			--minToFinish;
			if (minToFinish) stk.push({ score, minToFinish });
			else totalScore += score;
		}
		else if (!stk.empty()) {
			--stk.top().minToFinish;
			if (!stk.top().minToFinish) {
				totalScore += stk.top().score;
				stk.pop();
			}
		}
	}
	printf("%d", totalScore);
}