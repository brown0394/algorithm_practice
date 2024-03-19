#include <iostream>
#include <vector>

#define MAX 1000000000

struct node {
	int sum;
	int count;
	int fifth;
};
int main() {
	int testCases;
	scanf_s("%d", &testCases);
	int teamMemCount[201]{ 0 };
	node teamScore[201]{ 0 };
	for (int i = 0; i < testCases; ++i) {
		int participants;
		scanf_s("%d", &participants);
		int max = 0;
		std::vector<int> ranks(participants);
		for (int j = 0; j < participants; ++j) {
			scanf_s("%d", &ranks[j]);
			++teamMemCount[ranks[j]];
			if (ranks[j] > max) max = ranks[j];
		}
		int score = 1;
		for (int j = 0; j < participants; ++j) {
			if (teamMemCount[ranks[j]] == 6) {
				if (teamScore[ranks[j]].count < 4) {
					teamScore[ranks[j]].sum += score;
				}
				else if (teamScore[ranks[j]].count == 4) {
					teamScore[ranks[j]].fifth = score;
				}
				++teamScore[ranks[j]].count;
				++score;
			}
			else teamScore[ranks[j]].sum = MAX + 1;
		}
		int minSum = MAX, minFifth = MAX, teamWon = -1;
		for (int j = 1; j <= max; ++j) {
			teamMemCount[j] = 0;
			if (teamScore[j].sum < minSum) {
				teamWon = j;
				minSum = teamScore[j].sum;
				minFifth = teamScore[j].fifth;
			}
			else if (teamScore[j].sum == minSum && teamScore[j].fifth < minFifth) {
				teamWon = j;
				minFifth = teamScore[j].fifth;
			}
			teamScore[j].count = 0;
			teamScore[j].fifth = 0;
			teamScore[j].sum = 0;
		}
		printf("%d\n", teamWon);
	}

}
