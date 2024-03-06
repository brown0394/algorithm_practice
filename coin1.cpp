#include <iostream>
#include <vector>

int main() {
	int coins, target;
	scanf("%d %d", &coins, &target);
	std::vector<int> coin;
	std::vector<int> coinCombi(target + 1);
	for (int i = 0; i < coins; ++i) {
		int in;
		scanf("%d", &in);
		if (in <= target) coin.push_back(in);
	}
	coinCombi[0] = 1;
	for (int i = 0; i < coin.size(); ++i) {
		for (int j = coin[i]; j <= target; ++j) {
			coinCombi[j] += coinCombi[j - coin[i]];
		}
	}
	printf("%d\n", coinCombi[target]);
}
