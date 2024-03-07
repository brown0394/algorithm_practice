#include <iostream>
#include <vector>
#include <algorithm>

#define MAXVAL 100000

int main() {
	int coins, target;
	scanf_s("%d %d", &coins, &target);
	std::vector<int> coin;
	std::vector<int> coinCombi(target + 1, MAXVAL);
	for (int i = 0; i < coins; ++i) {
		int in;
		scanf_s("%d", &in);
		if (in <= target) coin.push_back(in);
	}
	coins = coin.size();
	std::sort(coin.begin(), coin.end());
	coinCombi[0] = 0;
	for (int i = coin[0]; i <= target; ++i) {
		int min = MAXVAL;
		for (int j = 0; j < coins; ++j) {
			if (coin[j] > i) break;
			if (coinCombi[i - coin[j]] < min) min = coinCombi[i - coin[j]];
		}
		if (min != MAXVAL) coinCombi[i] = min + 1;
	}
	if (coinCombi[target] == MAXVAL) printf("-1\n");
	else printf("%d\n", coinCombi[target]);
}
