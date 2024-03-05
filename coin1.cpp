#include <iostream>
#include <vector>

int main() {
	short int coins, target;
	scanf_s("%hd %hd", &coins, &target);
	std::vector<short int> coin;
	std::vector<std::vector<int>> coinCombi(target + 1);
	for (int i = 0; i < coins; ++i) {
		int in;
		scanf_s("%d", &in);
		if (in > 10'000) break;
		coin.push_back((short int)in);
	}
	//std::sort(connections.begin(), connections.end());
	coinCombi[coin[0]].push_back(1);
	int curCoin = 1;
	for (int i = coin[0] + 1; i <= target; ++i) {
		if (i < coin[curCoin]) coinCombi[i].resize(curCoin);
		else {
			++curCoin;
			coinCombi[i].resize(curCoin);
			coinCombi[i][curCoin-1] = 1;
		}
		for (int j = 0; j < curCoin; ++j) {
			int prior = i - coin[j];
			if (prior < coin[j]) break;
			for (int k = j; k < curCoin; ++k) {
				coinCombi[i][j] += coinCombi[prior][k];
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < coins; ++i) sum += coinCombi[target][i];
	printf("%d\n", sum);
}
