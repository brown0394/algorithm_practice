#include <iostream>
#include <vector>
#include <algorithm>

struct node {
	int id;
	std::vector<int> scores;
	int tries;
	int lastSumbit;
	bool operator < (const node& other) {
		if (scores[0] == other.scores[0]) {
			if (tries == other.tries) {
				return lastSumbit < other.lastSumbit;
			}
			return tries < other.tries;
		}
		return scores[0] > other.scores[0];
	}
};

int main() {
	int testCases;
	scanf_s("%d", &testCases);
	for (int i = 0; i < testCases; ++i) {
		int teams, problems, myTeam, logs;
		scanf_s("%d %d %d %d", &teams, &problems, &myTeam, &logs);
		std::vector<node>infos(teams, node{0, std::vector<int>(problems + 1, 0), 0, 0});
		int id, prob, score;
		for (int j = 0; j < logs; ++j) {
			scanf_s("%d %d %d", &id, &prob, &score);
			--id;
			infos[id].id = id + 1;
			if (infos[id].scores[prob] < score) {
				infos[id].scores[0] -= infos[id].scores[prob];
				infos[id].scores[prob] = score;
				infos[id].scores[0] += score;
			}
			++infos[id].tries;
			infos[id].lastSumbit = j;
		}
		std::sort(infos.begin(), infos.end());
		for (int j = 0, len = infos.size(); j < len; ++j) {
			if (infos[j].id == myTeam) {
				printf("%d\n", j + 1);
				break;
			}
		}
	}
}