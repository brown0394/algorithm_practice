#include <iostream>
#include <vector>
#include <bitset>
#include <queue>

int main() {
	int people, parties;
	scanf_s("%d %d", &people, &parties);
	std::vector<std::vector<int>> partyParticipants(parties);
	std::vector<std::vector<int>> participatingParties(people+1);
	std::bitset<51> checked;
	std::bitset<51> partyChecked;
	int peopleKnowsT;
	scanf_s("%d", &peopleKnowsT);
	int in;
	std::queue<int> q;
	for (int i = 0; i < peopleKnowsT; ++i) {
		scanf_s("%d", &in);
		q.push(in);
		checked[in] = true;
	}
	int participating;
	bool knows;
	int partyWithLies = parties;
	for (int i = 0; i < parties; ++i) {
		knows = false;
		scanf_s("%d", &participating);
		for (int j = 0; j < participating; ++j) {
			scanf_s("%d", &in);
			partyParticipants[i].push_back(in);
			participatingParties[in].push_back(i);
		}
	}
	while (!q.empty()) {
		in = q.front();
		q.pop();
		for (auto it = participatingParties[in].begin(); it != participatingParties[in].end(); ++it) {
			if (!partyChecked[*it]) {
				partyChecked[*it] = true;
				--partyWithLies;
				for (auto it2 = partyParticipants[*it].begin(); it2 != partyParticipants[*it].end(); ++it2) {
					if (!checked[*it2]) {
						checked[*it2] = true;
						q.push(*it2);
					}
				}
			}
		}
	}

	printf("%d\n", partyWithLies);
}