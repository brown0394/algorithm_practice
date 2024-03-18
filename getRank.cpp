#include <iostream>

int main() {
	int scores, newScore, scorePage;
	scanf_s("%d %d %d", &scores, &newScore, &scorePage);
	int score;
	bool found = false;
	int foundRank = 1, foundIdx = 0;
	for (int i = 0; i < scores; ++i) {
		scanf_s("%d", &score);
		if (!found && newScore >= score) {
			foundRank = i + 1;
			foundIdx = i;
			if (newScore == score) ++foundIdx;
			found = true;
		}
		else if (found && newScore == score) {
			++foundIdx;
		}
	}
	if (!found && scores < scorePage) printf("%d\n", scores + 1);
	else if (found && foundIdx < scorePage) printf("%d\n", foundRank);
	else printf("-1\n");
}
