#include <iostream>
#include <vector>


int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int players;
	std::cin >> players;
	std::vector<int> cards(1000001, -1);
	std::vector<int> playerCard(players, 0);
	int maxVal = 0;
	for (int i = 0; i < players; ++i) {
		std::cin >> playerCard[i];
		cards[playerCard[i]] = i;
		if (playerCard[i] > maxVal) maxVal = playerCard[i];
	}
	std::vector<int> playerWins(players, 0);
	for (int i = 0; i < players; ++i) {
		int num = playerCard[i];
		for (int j = 2; num * j <= maxVal; ++j) {
			int mul = num * j;
			if (cards[mul] >= 0) {
				++playerWins[i];
				--playerWins[cards[mul]];
			}
		}
	}
	for (auto it = playerWins.begin(), end = playerWins.end(); it != end; ++it) {
		std::cout << *it << ' ';
	}
	std::cout << '\n';
}